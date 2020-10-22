//queue implementation using linked list

#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int data;
	struct queue *nptr;//denoting next pointer pointing to the next node
}q;

struct queue *hptr=NULL;//denoting head pointer pointing to first node

void insert();//prototype
void delete();//prototype
void isempty();//prototype
void print();//prototype

int main()
{
	int a;//options for what to do
	
	while(1)
	{
		printf("what do you want to do?\n1. insert\n2. delete\n3. check for empty\n4. print\n5. exit\n");
		scanf("%d",&a);
		
				if(a<1 || a>7)
				printf("invalid input\n\n");
				
				switch(a)
				{
					case 1: insert();			
					break;//case 1 break

					case 2: delete();				
					break;//case 2 break
					
					case 3: isempty();
					break;//case 3 break
					
					case 4: print();
					break;//case 5 break
					
					case 5: return 0;
				}
	}//while ends
}//main ends

void insert()
{
	int data;
	struct queue *temp =  malloc(sizeof(struct queue));//memory allocation to a node
			printf("enter the data to insert :  ");
		   scanf("%d",&data);
	
	 		temp->data=data;//data goes inside the node
	 		temp->nptr=hptr;//address of head pointer goes to node
    		hptr=temp;//address of node goes to the head pointer
}//insert ends

void delete()
{
	int store;//for storing the deleted number
	if(hptr!=NULL)
	{
		struct queue *thptr=hptr;//creating a pointer
		if(hptr->nptr!=NULL)//if the queue contains more than one node
		{
			while((thptr->nptr)->nptr!=NULL)
			{
				thptr=thptr->nptr;
			 	
			}//while ends
			store=(thptr->nptr)->data;
			thptr->nptr=NULL;
			printf("the deleted number is : %d \n",store);
		}//inner if
		else//if the queue contains only one node
		{
			store=thptr->data;
			hptr=thptr->nptr;
			thptr->nptr=NULL;
			
			printf("the deleted number is : %d \n",store);
		}//inner else
	}//outer if
	else printf("no data to delete\n");
}

void print()
{
	if(hptr!=NULL)
	{
		struct queue *temp=hptr;
		 do 
		 {
		  printf("-->%d",temp->data);
		  temp=temp->nptr;
		 }while(temp!=NULL);
		 printf("\n");
	} 
	else printf("the stack is empty\n");
}//print ends

void isempty()
{
	if(hptr==NULL)
	printf("the queue is empty\n");
	else printf("the queue is not empty\n");
}
