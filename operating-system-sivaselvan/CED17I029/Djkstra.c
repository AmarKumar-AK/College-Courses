#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#include<unistd.h>
#include<curses.h>
#define max_size 10
int buff[max_size];

bool b[2];
bool c[2];
int k=1;

int count=0;
int in=0;
int out=0;
void *producer(void *arg)
{
  while(1)
  {
    while(count==max_size);
    int p=rand()%1000;
    b[0]=false;
    L1:
        if(k!=0)
        {
            c[0]=true;
            if(b[k])
            {
                k=0;
                goto L1;
            }
        }
        else
        {
            c[0]=false;
            for(int j=0; j<2; j++)
            {
                if(j!=0 && !c[j])
                  goto L1;
            }
        }
        //   cs   //
        printf("\033[1;32mProducer :  %d\n",p);
        buff[in]=p;
        count++;
        in=(in+1)%max_size;
        //   cs    //
        c[0]=true;
        b[0]=true;
        sleep(rand()%3);
  }
}

void *consumer(void *arg)
{
  while(1)
  {
      while(count==0);
      b[1]=false;
      L1:
          if(k!=1)
          {
              c[1]=true;
              if(b[k])
              {
                  k=1;
                  goto L1;
              }
          }
          else
          {
              c[1]=false;
              for(int j=0; j<2; j++)
              {
                  if(j!=1 && !c[j])
                    goto L1;
              }
          }
          //   cs   //
          int p=buff[out];
          printf("\033[1;31mConsumer :  %d\n",p);
          count--;
          out=(out+1)%max_size;
          //   cs    //
          c[1]=true;
          b[1]=true;
          sleep(rand()%3);
  }
}

int main()
{
  b[0]=false;  b[1]=false; c[0]=false; c[1]=false;
  pthread_t tid[2];
  pthread_create(&tid[0],NULL,producer,NULL);
  pthread_create(&tid[1],NULL,consumer,NULL);
  pthread_join(tid[0],NULL);
  pthread_join(tid[1],NULL);
}
