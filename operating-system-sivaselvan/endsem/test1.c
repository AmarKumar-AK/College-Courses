#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<time.h>


enum {North, South};
sem_t mutex1;
sem_t mutex2;
sem_t northCar;
sem_t southCar;
int dir;
void *Arrive(void *param){
    // printf("Hello Arrive\n");
    dir=*(int*)param;
    
        if(dir == North){
            sem_post(&northCar);
            int temp;
            sem_getvalue(&northCar,&temp);
            printf("northcar %d\n",temp);//
            sem_wait(&mutex1);
            printf("Going North\n");
            
            // sleep(1);
        }
        else if(dir == South){
            sem_post(&southCar);
            int temp;
            sem_getvalue(&southCar,&temp);
            printf("southcar %d\n",temp);//
            sem_wait(&mutex1);
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
            sleep(1);
            printf("Departing North\n");
            int S;
            sem_getvalue(&southCar,&S);
            printf("South Remaining %d\n",S);
            if(S>0){
                dir=!dir;
            }
        }
        else if(dir == South){
            sem_wait(&southCar);
            sleep(1);
            printf("Departing South\n");
            int N;
            sem_getvalue(&northCar,&N);
            printf("North remaining %d\n",N);
            if(N>0){
                dir=!dir;
            }
        }
        sem_post(&mutex1);
}

int main(){
    srand(time(NULL));

    sem_init(&mutex1,0,1);
    sem_init(&mutex2,0,0);
    sem_init(&northCar,0,0);
    sem_init(&southCar,0,0);


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


    return 0;
}