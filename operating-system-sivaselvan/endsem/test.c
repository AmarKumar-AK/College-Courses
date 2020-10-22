#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<time.h>

pthread_mutex_t goNorth;
pthread_mutex_t goSouth;

enum {North, South};
sem_t mutex1;
sem_t mutex2;
sem_t northCar;
sem_t southCar;
int dir;
void *Arrive(void *param){
    // printf("Hello Arrive\n");
    dir=*(int*)param;
    
        // sem_wait(&mutex1);
        if(dir == North){
            sem_post(&northCar);
            int temp;
            sem_getvalue(&northCar,&temp);
            printf("northcar %d\n",temp);//
            sem_wait(&mutex1);
            // pthread_mutex_lock(&goNorth);
            printf("Going North\n");
            
            // sleep(1);
        }
        else if(dir == South){
            sem_post(&southCar);
            int temp;
            sem_getvalue(&southCar,&temp);
            printf("southcar %d\n",temp);//
            sem_wait(&mutex1);
            // pthread_mutex_lock(&goSouth);
            printf("Going South\n");

            // sleep(1);
        }
        sem_post(&mutex2);
}
void *Depart(void *param){
    // printf("Hello Depart\n");
    dir=*(int*)param;

        sem_wait(&mutex2);
        if(dir == North){
            sem_wait(&northCar);
            pthread_mutex_unlock(&goNorth);
            sleep(1);
            printf("Departing North\n");
            int S;
            sem_getvalue(&southCar,&S);
            printf("S %d\n",S);
            if(S>0){
                dir=!dir;
            }
        }
        else if(dir == South){
            sem_wait(&southCar);
            pthread_mutex_unlock(&goSouth);
            sleep(1);
            printf("Departing South\n");
            int N;
            sem_getvalue(&northCar,&N);
            printf("N %d\n",N);
            if(N>0){
                dir=!dir;
            }
        }
        sem_post(&mutex1);
}

int main(){
    srand(time(NULL));
    // dir=0;
    sem_init(&mutex1,0,1);
    sem_init(&mutex2,0,0);
    sem_init(&northCar,0,0);
    sem_init(&southCar,0,0);
    pthread_mutex_init(&goNorth,NULL);
    pthread_mutex_init(&goSouth,NULL);

    pthread_t tid1[10],tid2[10];
    printf("Hello in main\n");
    for(int i=0 ; i<10 ; ++i){
        int local=rand()%2;
        printf("direction : %d\n",local);
        pthread_create(&tid1[i],NULL,(void *)Arrive,&local);
        pthread_create(&tid2[i],NULL,(void *)Depart,&local);
        // sleep(3);
    }
    for(int i=0 ; i<10 ; ++i){
        pthread_join(tid1[i],NULL);
        pthread_join(tid2[i],NULL);  
    }
    pthread_mutex_destroy(&goNorth);
    pthread_mutex_destroy(&goSouth);

    return 0;
}