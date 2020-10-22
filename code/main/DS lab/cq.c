

#include<stdio.h>
struct cqueue
{
	int a[6];
	int front;
	int rear;

};

void enqueue(struct cqueue *c, int x);//prototype
void dequeue(struct cqueue *c);//prototype

void main()
{
	struct cqueue c;
	c.front=-1;
	c.rear=-1;
	
	enqueue(&c,10);
	enqueue(&c,20);
	enqueue(&c,30);
	enqueue(&c,40);
	enqueue(&c,50);
	dequeue(&c);
	dequeue(&c);
	dequeue(&c);
	
	enqueue(&c,80);
	enqueue(&c,70);
	

	
	
	int i=c.front;
	int a[5];
	printf("front is %d & rear is %d\n",c.front,c.rear);
	for(i=c.front ; i!=c.rear ; i=(i+1)%5)
	printf("%d ",c.a[i]);
	printf("%d",c.a[c.rear]);
	printf("\n");
	

}


void enqueue(struct cqueue *c, int x)
{
	if((c->rear+1)%5==c->front)
	printf("cqueue is full\n");
	else if(c->rear==-1 && c->front==-1)
	{
		c->rear++;
		c->front++;
		c->a[c->rear] = x;
	}
	else
	c->rear = (c->rear+1)%5;
	c->a[c->rear]=x;
	
	

}

void dequeue(struct cqueue *c)
{
	if(c->rear==-1 && c->front==-1)
	printf("cqueue is empty\n");
	
	else
	c->front = (c->front + 1)%5;

}


