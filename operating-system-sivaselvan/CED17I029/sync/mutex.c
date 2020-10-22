#include<stdio.h> 
#include<string.h> 
#include<pthread.h> 
#include<stdlib.h> 
#include<unistd.h> 
  
pthread_t tid[4]; 
int counter; 
pthread_mutex_t lock; 
  
void* trythis(void *arg) 
{ 
printf("hi\n");
    pthread_mutex_lock(&lock); 
  
    unsigned long i = 0; 
    counter += 1; 
    printf("\n Job %d has started\n", counter); 
  
    for(i=0; i<(0xFFFFFFFF);i++); 
  
    printf("\n Job %d has finished\n", counter); 
  
    pthread_mutex_unlock(&lock); 
printf("bye\n");
  
    return NULL; 
} 
  
int main(void) 
{ 
    int i = 0; 
    int error; 
  
    if (pthread_mutex_init(&lock, NULL) != 0) 
    { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    } 
  
    while(i < 4) 
    { 
        error = pthread_create(&(tid[i]), NULL, &trythis, NULL); 
        if (error != 0) 
            printf("\nThread can't be created :[%s]", strerror(error)); 
        i++; 
    } 
  
    pthread_join(tid[0], NULL); 
    pthread_join(tid[1], NULL); 
    pthread_join(tid[2], NULL); 
    pthread_join(tid[3], NULL); 
    
  pthread_mutex_destroy(&lock); 
  
    return 0; 
} 
