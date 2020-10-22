#include<stdio.h>
struct QueueADT 
{
	int a[100];
	int front, rear;	
};
void enqueue(struct QueueADT *pq,int x);
int dequeue(struct QueueADT *pq);
int isfull(struct QueueADT q);
int isempty(struct QueueADT q);
int main()
{
	struct QueueADT q;
	q.front=q.rear=-1;
	enqueue(&q,10);
	enqueue(&q,20);
	enqueue(&q,30);
	enqueue(&q,40);
	printf("%d is dequeued element \n",dequeue(&q) );
	printf("%d is dequeued element \n",dequeue(&q) );
	printf("%d is dequeued element \n",dequeue(&q) );
	printf("%d is dequeued element \n",dequeue(&q) );
	printf("%d is dequeued element \n",dequeue(&q) );
	printf("Is queue is full %d \n",isfull(q));
	printf("Is queue is empty %d \n",isempty(q));
}
void enqueue(struct QueueADT *pq,int x)
{
	if(pq->rear==99)
		printf("queue is full");
	else
	{
		pq->rear=pq->rear+1;
		pq->a[pq->rear]=x;
	}
	if(pq->rear==1)
	{
		pq->front=0;
	}

}
int dequeue(struct QueueADT *pq)
{
	
	int x=-1;
	if((pq->front==-1) || (pq->front>pq->rear))
		printf("queue is empty\n");
	else 
	{
		x=pq->a[pq->front];
		pq->front=pq->front+1;
	}
	return x;

}
int isfull(struct QueueADT q)
{
	if(q.rear==99)
		return 1;
	else 
		return 0;
}
int isempty(struct QueueADT q)
{
	if(q.rear<q.front || q.front==-1)
		return 1;
	else 
		return 0;
}