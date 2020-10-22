#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>
//# include<bits/stdc++.h>
//using namespace std;

void *reader(void *i);
void *writer(void *i);
int phil[5] = { 1, 2, 3, 4, 5 }; 
int readcount=0,writecount=0,sh_var=5,bsize[5];
sem_t mutex,wb;
pthread_t r[5],w[5];

void *reader(void *i)
{       
	int f = *((int *)i);

        sem_wait(&mutex);
        readcount++;
        if(readcount==1)
            sem_wait(&wb);
	sem_post(&mutex);	        
        printf("\n-------------------------");
        printf("\n\n reader- << %d << is reading << %d",f,sh_var); 


	//sleep(1);
	sem_wait(&mutex);        
	readcount--;
        if(readcount==0)
            sem_post(&wb);
        sem_post(&mutex);
}

void *writer(void *i)
{
	int ar = *((int *)i);        
        sem_wait(&wb);
        
        sh_var=sh_var+5;
	printf("\n\n writer- %d is writing << %d",ar,sh_var);      
	//sleep(2);	
	sem_post(&wb);
        
}

int main()
{
        sem_init(&mutex,0,1);
        sem_init(&wb,0,1);
        for(int i=0; i<5; i++)
{
	pthread_create(&w[i],NULL,(void *)writer,(void *)&phil[i]);        
	pthread_create(&r[i],NULL,(void *)reader,(void *)&phil[i]);
	//sleep(1);
 }       
for(int i=0; i<5; i++)
{        pthread_join(w[i],NULL);
        pthread_join(r[i],NULL);
 }       
return(0);
}    

