

#include<stdio.h>
struct list
{
	int array[25];
	int lsize;
};

void insert(struct list *ptrl, int pos, int x);//prototype
int delete(struct list *ptrl, int pos);//prototype
int print(struct list xyz);//prototype
int isFull(struct list l);//prototype
int isEmpty(struct list l);//prototype

void main()
{
	struct list l;
	l.lsize=0;
	
	isFull(l);									//checks whether the array is full or not before entering the element
	
	int k;
	printf("enter the no. of inputs you want to enter\n");
	scanf("%d",&k);							//entering the no. of inputs
	while(k>25 || k<0)
	{
		printf("invalid input");
		printf("enter the no. of inputs you want to enter\n");
		scanf("%d",&k);						//entering the no. of inputs again...if invalid input
	}
	
	int p,e;
	printf("enter the postion and element of the array");
	scanf("%d-%d",&p,&e);				//entering the position and element
	
	int i;
	for(i=0; i<k; i++)	
	while(p>l.lsize)
	{
		printf("invalid input");
		
		printf("enter the postion and element of the array");
		scanf("%d-%d",&p,&e);			//entering the position and element again...if invalid input
	}
	
	insert(&l,p,e);				//inserting the number in the array in a certain position
	
	
	isEmpty(l);						//checks whether the array is empty or not after inserting the number in the array
	
	int n; 								//position to be deleted
	printf("enter the postion which you want to delete\n");
	scanf("%d",&n);				//taking the value of position to be deleted
	while(n>l.lsize || n<0)
	{
		printf("invalid position\n");	
		printf("enter the valid postion which you want to delete\n");
		scanf("%d",&n);
	}
	

	printf("deleted number is %d \n",delete(&l,n-1));			//shows the value of deleted number
	
	print(l);
	
}//main function ends



int isFull(struct list l)
{
	if(l.lsize==25)
	printf("the list is full\n");
	else
	printf("the list is not full\n");
}//isFull function ends


void insert(struct list *ptrl, int pos, int x)
{
	int i;
	for(i=ptrl->lsize; i>=pos; i--)
	ptrl->array[i+1]=ptrl->array[i];
	ptrl->array[pos]=x;
	ptrl->lsize++;
}//insert function ends


int isEmpty(struct list l)
{
	if(l.lsize==0)
	printf("the list is empty\n");
	else
	printf("the list is not empty\n");
}//isEmpty function ends


int delete(struct list *ptrl, int pos)
{
	int i,x=ptrl->array[pos];
	for(i=pos+1; i<ptrl->lsize;i++)
	ptrl->array[i-1]=ptrl->array[i];
	ptrl->lsize--;
	return (x);
}//delete function ends


int print(struct list xyz)
{
	int i;
	for(i=0;i<xyz.lsize;i++)
	printf("%d\n",xyz.array[i]);
}//print function ends


