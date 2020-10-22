#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#include<unistd.h>
#include<curses.h>
#include<semaphore.h>

sem_t mutex;
sem_t oxyQueue;
sem_t hydQueue;
int hydrogen=0;
int oxygen=0;

void *hydrogen_t(void *arg)
{
    while(1)
    {
      // int value;  sem_getvalue(&hydQueue,&value);
      // printf("\033[1;32mhydQueue : %d\n", value);
      sem_wait(&mutex);

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
          sem_post(&mutex);
      }
	  // printf("hhhha1 \n");
      sem_wait(&hydQueue);
      // printf("hhha2 \n");
      sem_post(&mutex);
      sleep(rand()%2);
    }
}

void *oxygen_t(void *arg)
{
  while(1)
  {
    // int value;
    // sem_getvalue(&oxyQueue,&value);
    // printf("\033[1;31moxyQueue : %d\n",value);
    sem_wait(&mutex);
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
        sem_post(&mutex);
    }
	  // printf("ooooa1 \n");
    sem_wait(&oxyQueue);
    // printf("oooooa2 \n");
    sem_post(&mutex);
    sleep(rand()%2);
  }
}

int main()
{
    sem_init(&mutex,0,1);
    sem_init(&oxyQueue,0,1);
    sem_init(&hydQueue,0,1);
    pthread_t hyd_t,oxy_t;
    pthread_create(&hyd_t,NULL,hydrogen_t,NULL);
    pthread_create(&oxy_t,NULL,oxygen_t,NULL);
    pthread_join(hyd_t,NULL);
    pthread_join(oxy_t,NULL);
}
