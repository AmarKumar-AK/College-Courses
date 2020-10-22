#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *nptr;
};

void insert(int pos,int x);
void printList();
int Delete(int pos);
int isEmpty();
int isFull();

//create empty clist
struct node *hptr=NULL;

void main()
{
 if(isEmpty())
  printf("The circular linked list is empty\n");
 else
  printf("The circular linked list is not empty\n");
 if(isFull())
 printf("The circular linked list is full\n");
 else
 printf("the circular linked list is not full\n");
 
 insert(1,10);
 insert(1,20);
 insert(1,30);
 insert(1,40);
 insert(3,50);
 insert(6,60);
 printf("\n");
 printList();
 printf("\nDeleted element in pos 2 is %d\n",Delete(6));
 printList();
 printf("\nDeleted element in pos 1 is %d\n",Delete(1));
 printList();
 printf("\nDeleted element in pos 1 is %d\n",Delete(3));
 printList();
 printf("\nDeleted element in pos 1 is %d\n",Delete(2));
 printList();

}

void insert(int pos,int x)
{
 struct node *tmp = malloc(sizeof(struct node));
 tmp->data=x;
 if(hptr==NULL)
 {
   tmp->nptr=tmp;   
   hptr=tmp;
 }
 else if(pos==1 && hptr!=NULL)
 {
    tmp->nptr=hptr;
    
    struct node *thptr=hptr;
    do
    {
      printf("\n%d",(thptr->nptr)->data);
      thptr=thptr->nptr;
    }while(thptr->nptr!=hptr);
     hptr=tmp;
     thptr->nptr=tmp;
 }
 else
 {
   int i=1;
   struct node *thptr=hptr;
   while(i<pos-1) //loop breaks when i= pos-1
   {
    thptr=thptr->nptr;
    i++;
   }
   tmp->nptr=thptr->nptr;
   thptr->nptr=tmp;
 }
 
}

int Delete(int pos)
{
 struct node *thptr=hptr;
 struct node *thptr1=hptr;
 int i=1,x;
 if(pos==1)
 {
  x=hptr->data;
  struct node *tmp=hptr;
    do
    {
      //printf("%d",tmp->data);
      tmp=tmp->nptr;
    }while(tmp->nptr!=hptr);
    printf("\n");
   thptr=tmp->nptr;
   hptr=thptr->nptr;
   tmp->nptr=hptr;
 }
 else
 {
  while(i<pos-1)
  {
   thptr=thptr->nptr;
   i++;
  }
  thptr1=thptr->nptr;
  x=(thptr->nptr)->data;
  thptr->nptr=thptr1->nptr;
 }
 return(x);
}

void printList()
{
 struct node *tmp=hptr;
 do 
 {
  printf("%d ",tmp->data);
  tmp=tmp->nptr;
 }while(tmp!=hptr); 
}

int isEmpty()
{
 if(hptr==NULL)
  return(1);
 else
  return(0);
}

int isFull()
{
 if(malloc(sizeof(struct node))==NULL)
  return(1);
 else 
  return(0);
}
