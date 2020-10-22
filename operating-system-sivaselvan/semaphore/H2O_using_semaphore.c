#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#include<unistd.h>
#include<semaphore.h>
#include<time.h>
sem_t mutex;
sem_t oxyQueue;
sem_t hydQueue;
int hydrogen=0;
int oxygen=0;

void *hydrogens(void *arg){
    while(1){
        sem_wait(&mutex);

        hydrogen++;
        printf("BEFORE  H : %d    O : %d\n",hydrogen,oxygen);
        if(hydrogen>=2 && oxygen>=1){
          	sem_post(&hydQueue);
          	sem_post(&hydQueue);
          	hydrogen-=2;
          	sem_post(&oxyQueue);
         	oxygen--;
          	printf("H2O formed\n");
          	printf("AFTER  H : %d    O : %d\n",hydrogen,oxygen);
      	}
		else{
			sem_post(&mutex);
		}
		sem_wait(&hydQueue);
		sem_post(&mutex);
		sleep(rand()%2);
    }
}

void *oxygens(void *arg){
  	while(1){
    	sem_wait(&mutex);
    	oxygen++;
    	printf("BEFORE   H : %d    O : %d\n",hydrogen,oxygen);
    	if(hydrogen>=2){
			sem_post(&hydQueue);
			sem_post(&hydQueue);
			hydrogen-=2;
			sem_post(&oxyQueue);
			oxygen--;
			printf("H2O formed\n");
			printf("AFTER   H : %d    O : %d\n",hydrogen,oxygen);

    	}
		else{
        	sem_post(&mutex);
    	}
		sem_wait(&oxyQueue);
		sem_post(&mutex);
		sleep(rand()%2);
  	}
}

int main(){
    sem_init(&mutex,0,1);
    sem_init(&oxyQueue,0,1);
    sem_init(&hydQueue,0,1);
    pthread_t tid[2];
    pthread_create(&tid[0],NULL,hydrogens,NULL);
    pthread_create(&tid[1],NULL,oxygens,NULL);
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
	return 0;
}
