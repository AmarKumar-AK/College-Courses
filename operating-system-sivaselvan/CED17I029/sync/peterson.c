#include<pthread.h>
#include<stdio.h>
void *func1(void *);
void *func2(void *);
int flag[2];
int turn=0;
int global=100;
int main()
{
    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,func2,NULL);
    pthread_create(&tid2,NULL,func1,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
}

void *func1(void *param)
{
    int i=0;
    while(i<20)
    {
        flag[0]=1;
        turn=1;
        while(flag[1]==1 && turn==1);
        global+=100;
        printf("FT: g: %d\n",global);
        flag[0]=0;
        i++;
    }
}
void *func2(void *param)
{
    int i=0;
    while(i<20)
    {
        flag[1]=1;
        turn=0;
        while(flag[0]==1 && turn==0);
        global-=75;
        printf("SP: g: %d\n",global); 
        flag[1]=0;
//sleep(3);
        i++;
    }
}
