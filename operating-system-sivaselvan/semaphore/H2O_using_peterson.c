#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#include<unistd.h>
#include<semaphore.h>
#include<time.h>
sem_t oxyQueue;
sem_t hydQueue;
int hydrogen=0;
int oxygen=0;
bool flag[2];
int turn;

void *hydrogens(void *arg){
	while(1){
		flag[0]=true;
		turn=1;
		while(flag[1] && turn==1);
		hydrogen++;
		printf("BEFORE 	H : %d    O : %d\n",hydrogen,oxygen);
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
			flag[0]=false;
		}
		sem_wait(&hydQueue);
		flag[0]=false;
		sleep(rand()%2);
	}
}

void *oxygens(void *arg){
	while(1){
		flag[1]=true;
		turn=0;
		while(flag[0] && turn==0);
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
			flag[1]=false;
		}
		sem_wait(&oxyQueue);
		flag[1]=false;
		sleep(rand()%2);
	}
}

int main(){
	srand(time(NULL));
	flag[0]=false;  flag[1]=false;
    sem_init(&oxyQueue,0,1);
    sem_init(&hydQueue,0,1);
    pthread_t tid[2];
    pthread_create(&tid[0],NULL,hydrogens,NULL);
    pthread_create(&tid[1],NULL,oxygens,NULL);
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
	return 0;
}
