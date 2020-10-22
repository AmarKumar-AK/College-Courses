#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#include<unistd.h>
#include<curses.h>
#define max_size 10
int buff[max_size];
bool flag[2];
int turn=0;
int count=0;
int in=0;
int out=0;
void *producer(void *arg)
{
  while(1)
  {
    while(count==max_size);
    int p=rand()%1000;
    while(flag[1])
    {
      if(turn==1)
      {
        flag[0]=false;
        while(turn==1);
        flag[0]=true;
      }
    }
    //  cs   //
    printf("\033[1;32mProducer :  %d\n",p);
    buff[in]=p;
    count++;
    in=(in+1)%max_size;
    //  cs  //
    turn=1;
    flag[0]=false;
    sleep(rand()%5);
  }
}

void *consumer(void *arg)
{
  while(1)
  {
    // printf("firoz\n");
    while(count==0);
    flag[1]=true;
    while(flag[0])
    {
      if(turn==0)
      {
        flag[1]=false;
        while(turn==0);
        flag[1]=true;
      }
    }
    //  cs   //
    int p=buff[out];
    printf("\033[1;31mConsumer :  %d\n",p);
    count--;
    out=(out+1)%max_size;
    //  cs  //
    turn=0;
    flag[1]=false;
    sleep(rand()%8);
  }
}

int main()
{
  flag[0]=false;  flag[1]=false;
  pthread_t tid[2];
  pthread_create(&tid[0],NULL,producer,NULL);
  pthread_create(&tid[1],NULL,consumer,NULL);
  pthread_join(tid[0],NULL);
  pthread_join(tid[1],NULL);
}
