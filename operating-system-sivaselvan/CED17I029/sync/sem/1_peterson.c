#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#include<unistd.h>
#include<curses.h>
#define max_size 10
int buff[max_size]={0};
bool flag[2];
int turn;
int in=0;
int out=0;
int count=0;
void *producer(void *arg)
{
	while(1)
	{
		if(count==max_size)
		{
			printf("buffer is full\n");
		}
		while(count==max_size);
		flag[0]=true;
		turn=1;
		while(flag[1] && turn==1);
		count++;
		buff[in]=rand()%100;
		printf("\033[1;32mProducer :  %d\n",buff[in]);
		in=(in+1)%max_size;
		flag[0]=false;
		sleep(rand()%2);
	}
}

void *consumer(void *arg)
{
	while(1)
	{
		if(count==0)
		{
			printf("buffer is empty\n");
		}
		while(count==0);

		flag[1]=true;
		turn=0;
		while(flag[0] && turn==0);
		count--;
		int item=buff[out];
		printf("\033[1;31mConsumer :  %d\n",item);
		out=(out+1)%max_size;
		flag[1]=false;
		sleep(rand()%2);
	}
}

int main()
{
	flag[0]=false;  flag[1]=false;
	pthread_t tid[2];
	pthread_create(&tid[0],NULL,producer,(void *)NULL);
	pthread_create(&tid[1],NULL,consumer,(void *)NULL);

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);

	return 0;
}
