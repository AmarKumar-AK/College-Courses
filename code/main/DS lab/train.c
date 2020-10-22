#include<time.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct passenger
{
	int pnr;
	char name[100];
	int fare;
};
struct WaitingListQueue
{
	struct passenger p[100];
	int rear;
	int front;
};

void enqueue(struct WaitingListQueue *w);//prototype
void dequeue(struct WaitingListQueue *w);//prototype
void print(struct WaitingListQueue w);//prototype

int main()
{
	struct WaitingListQueue w;
	w.rear=-1;
	w.front=-1;
	srand(time(NULL));
	
	int n;			//for choosing what to do
	while(1)
	{
	printf("what do you want to do?\n1. Enqueue\n2. Dequeue\n3. print\n4. exit\n");
	scanf("%d",&n);
	if(n<1 || n>4)
	printf("invalid input\n");
	else
	{
		switch(n)
		{
			case 1: 	enqueue(&w);	
			break;
			
			case 2: 	dequeue(&w);
			break;
			
			case 3: 	print(w);
			break;
			
			case 4: 	return 0;
			
			
		}//switch ends
	}//else ends		
	}//while ends	
		
	
	
}//main function ends




void print(struct WaitingListQueue w)
{
	int i;
	if(w.rear<w.front || w.front==-1)
	printf("No person is in the waiting list\n");
	else
	for(i=w.rear ; i>=w.front ; i--)
	printf("PNR no. is %d- Name is %s- fare is %d\n", i+1, w.p[i].name , rand()%1000+1);
	
}//print function ends


void enqueue(struct WaitingListQueue *w)
{
	
	
	int i;
	if(w->rear==99 && w->front==99)
	printf("booking cannot be done\n");
	else if(w->rear==-1 && w->front==-1)
	{
		
		w->rear++;
		w->front++;
		printf("enter passenger name\n");
		scanf("%s",w->p[w->rear].name);
		w->p[w->rear].pnr=1;
		
	}
	else
	{
	
		w->rear++;
		printf("enter the passenger name\n");
		scanf("%s",w->p[w->rear].name);
	}
}//enqueue function ends


void dequeue(struct WaitingListQueue *w)
{
	if(w->front==-1 || (w->front) > (w->rear))
	printf("No waiting\n");
	else 
	{
		(w->front)++;
	}
	
}//dequeue function ends
