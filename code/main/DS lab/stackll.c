//stack implementation using linked list

#include<stdio.h>
#include<stdlib.h>

struct stack {
	int data;
	struct stack *nptr;
}s;

struct stack *hptr=NULL;

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
	struct stack *temp =  malloc(sizeof(struct stack));
			printf("enter the data to insert :  ");
		   scanf("%d",&data);
	
	 		temp->data=data;
	 		temp->nptr=hptr;
    		hptr=temp;
}//insert ends

void delete()
{
	
	if(hptr!=NULL)
	{
		struct stack *temp=hptr;
		int store=temp->data;
		hptr=temp->nptr;
		temp->nptr=NULL;
		
		printf("the deleted number is : %d \n",store);
	}
	else printf("delete not possible\n");
}//delete ends

void isempty()
{
	if(hptr==NULL)
	printf("the stack is empty\n");
	else
	printf("the stack is not empty\n");
}//isempty ends

void print()
{
	if(hptr!=NULL)
	{
		struct stack *temp=hptr;
		 do 
		 {
		  printf("-->%d",temp->data);
		  temp=temp->nptr;
		 }while(temp!=NULL);
		 printf("\n");
	} 
	else printf("the stack is empty\n");
}//print ends


