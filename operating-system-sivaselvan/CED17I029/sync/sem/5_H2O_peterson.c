#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#include<unistd.h>
#include<curses.h>
#include<semaphore.h>

sem_t oxyQueue;
sem_t hydQueue;
int hydrogen=0;
int oxygen=0;
bool flag[2];
int turn;

void *hydrogen_t(void *arg)
{
	while(1)
	{
			flag[0]=true;
			turn=1;
			while(flag[1] && turn==1);
						hydrogen++;
						printf("\033[1;32mBEFORE  H : %d    O : %d\n",hydrogen,oxygen);
						if(hydrogen>=2 && oxygen>=1)
						{
								sem_post(&hydQueue);
								sem_post(&hydQueue);
								hydrogen-=2;
								sem_post(&oxyQueue);
								oxygen--;
								printf("\033[1;32mHHHHH2O formed\n");
								printf("\033[1;32mAFTER  H : %d    O : %d\n",hydrogen,oxygen);
						}else
						{
								// sem_post(&mutex);
								flag[0]=false;
						}
					// printf("hhhha1 \n");
						sem_wait(&hydQueue);
						// printf("hhha2 \n");
						flag[0]=false;
						sleep(rand()%2);
	}
}

void *oxygen_t(void *arg)
{
	while(1)
	{
		flag[1]=true;
		turn=0;
		while(flag[0] && turn==0);
		oxygen++;
		printf("\033[1;31mBEFORE   H : %d    O : %d\n",hydrogen,oxygen);
		if(hydrogen>=2)
		{
				sem_post(&hydQueue);
				sem_post(&hydQueue);
				hydrogen-=2;
				sem_post(&oxyQueue);
				oxygen--;
				printf("\033[1;31mH2OOOOOOO formed\n");
				printf("\033[1;31mAFTER   H : %d    O : %d\n",hydrogen,oxygen);

		}else
		{
				// sem_post(&mutex);
				flag[1]=false;
		}
		// printf("ooooa1 \n");
		sem_wait(&oxyQueue);
		// printf("oooooa2 \n");
		flag[1]=false;
		sleep(rand()%2);
	}
}

int main()
{
		flag[0]=false;  flag[1]=false;
    // sem_init(&mutex,0,1);
    sem_init(&oxyQueue,0,1);
    sem_init(&hydQueue,0,1);
    pthread_t hyd_t,oxy_t;
    pthread_create(&hyd_t,NULL,hydrogen_t,NULL);
    pthread_create(&oxy_t,NULL,oxygen_t,NULL);
    pthread_join(hyd_t,NULL);
    pthread_join(oxy_t,NULL);
}
