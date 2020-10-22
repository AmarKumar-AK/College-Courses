#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<time.h>

pthread_mutex_t lock;
pthread_mutex_t goNorth;
pthread_mutex_t goSouth;
enum Direction {North, South};
int northWait; // waiting to go north
int southWait; // waiting to go south
int northBound; // going north in Tunnel
int southBound; // going south in Tunnel
int dir;
void *Arrive(void *param){
    printf("Hello Arrive\n");
    while(1){

        pthread_mutex_lock(&lock);
        // printf("Hello Arrive1\n");
        // sleep(1);
        // If no one in the tunnel, car goes
        if ((northBound > 0) || (southBound > 0)){
            if (dir == North){
                // if no one is waiting to go south, car goes north
                if ((southWait > 0) || (southBound > 0)) {
                    northWait++;
                    printf("Arriving North %d\n",northWait);
                    pthread_mutex_lock(&goNorth);
                    northWait--;
                }
            }
            else {
                // if no one is waiting to go north, car goes south
                if ((northWait > 0) || (northBound > 0)) {
                    southWait++;
                    printf("Arriving South %d\n",southWait);
                    pthread_mutex_lock(&goSouth);
                    southWait--;
                }
            }
        }
        if (dir == North){
                northBound++;
        }  
        else{
            southBound++;
        } 
        // printf("No one in tunnel\n");
        pthread_mutex_unlock(&lock);
    }
    
}

void *Depart(void *param){
    printf("Hello Depart\n");
    while(1){
        
        pthread_mutex_lock(&lock);
        // printf("hello Depart1\n");
        // sleep(1);
        if (dir == North) {
            northBound--;
            if (southWait > 0) {
                if (northBound == 0){
                    printf("Departing from North %d\n",northBound);
                    pthread_mutex_unlock(&goSouth);
                }
                    
            }
        }
        else {
            southBound--;
            if (northWait > 0) {
                if (southBound == 0){
                    printf("Departing from South %d\n",southBound);
                    pthread_mutex_unlock(&goNorth);
                }   
            }
        }
        pthread_mutex_unlock(&lock);
    }
    
}

int main(){
    srand(time(NULL));
    dir=0;
    northWait = 0; // no one waiting
    southWait = 0; // no one waiting
    northBound = 0; // no one in tunnel
    southBound = 0; // no one in tunnel
    // printf("Hello in main1");
    if (pthread_mutex_init(&lock, NULL) != 0){ 
        printf("\nlock mutex init has failed\n"); 
        return 1; 
    }
    if (pthread_mutex_init(&goNorth, NULL) != 0){ 
        printf("\ngoNorth mutex init has failed\n"); 
        return 1; 
    }
    if (pthread_mutex_init(&goSouth, NULL) != 0){ 
        printf("\ngoSouth mutex init has failed\n"); 
        return 1; 
    }
    pthread_t tid1,tid2;
    // printf("Hello in main2");
    pthread_create(&tid1,NULL,(void *)Arrive,NULL);
    pthread_create(&tid2,NULL,(void *)Depart,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_mutex_destroy(&lock);
    pthread_mutex_destroy(&goNorth);
    pthread_mutex_destroy(&goSouth);

    return 0;
}