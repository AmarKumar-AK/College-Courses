#include<stdio.h>
#include<stdlib.h>
struct node
{
    int c;
    int d;
    struct node *nptr;
};
void insert(int pos,int c,int d);
int delet(int pos);
void print();
void isEmpty();
void isFull();
void result(int x);

struct node *hptr=NULL;
void main()
{
 int x,m,n,o;
 start:
 printf("Select from the options given below -\n1. Add element\n2. Remove element\n3. Result\n4. is the equation empty?\n5. is my memory full?\n6. print\n7. Exit\n");
 scanf("%d",&x);
 switch(x)
 {
     case 1: printf("\nplease enter the position,coefficient and the degree of the variable respectively -\n");
             scanf("%d%d%d",&m,&n,&o);
             insert(m,n,o);
             goto start;

     case 2: printf("\nplease enter the position you want to delete -\n");
             scanf("%d",&m);
             delet(m);
             goto start;

     case 3: printf("\nEnter the value for which you want the value of the polynomial -\n");
             scanf("%d",&n);
             result(n);
             goto start;

     case 4: isEmpty();
             goto start;

     case 5: isFull();
             goto start;

     case 6: print();
             goto start;

     case 7: break;
 }

}

void insert(int pos,int x,int y)
{
    struct node *tmp=malloc(sizeof(struct node));
    tmp->c=x;
    tmp->d=y;
    if(pos==1)
    {
        tmp->nptr=hptr;
        hptr=tmp;
    }
    else
    {
        int i=1;
        struct node *thptr=hptr;
        while(i<pos-1)
        {
            thptr=thptr->nptr;
            i++;
        }
        tmp->nptr=thptr->nptr;
        thptr->nptr=tmp;
    }
}

int delet(int pos)
{
    struct node *thptr=hptr;
    int x,y,i=1;
    if(pos==1)
    {
        x=hptr->c;
        y=hptr->d;
        hptr=hptr->nptr;
    }
    else
    {
        while(i<pos-1)
        {
            thptr=thptr->nptr;
            i++;
        }
        x=(thptr->nptr)->c;
        y=(thptr->nptr)->d;
        thptr->nptr=(thptr->nptr)->nptr;
    }
    return x,y;
}

void print()
{
    struct node *tmp=hptr;
    do
    {
        printf(" %d*x^%d +",tmp->c,tmp->d);
        tmp=tmp->nptr;
    }
    while(tmp!=NULL);
    printf("\n");
}

void isEmpty()
{
 if(hptr==NULL)
  printf("\nyes it is empty!!");
 else
  printf("\nNo it is not empty!!");
}

void isFull()
{
 if(malloc(sizeof(struct node))==NULL)
  printf("\nyes your memory is full!!");
 else
  printf("\nNo your memory is not full!!");
}

void result(int x)
{
    int i=1,m,n,q=0;
    struct node *tmp=hptr;
    do
    {
        m=x;
        if(tmp->d==0)
        {
         m=1;
         n=m*tmp->c;
         q=q+n;
         i=1;
         tmp=tmp->nptr;
        }
        else
        {
            while(i<tmp->d)
        {
            m=m*x;
            i++;
        }
        n=m*tmp->c;
        q=q+n;
        i=1;
        tmp=tmp->nptr;
        }
    }
    while(tmp!=NULL);
        printf("\nyour result is - %d\n",q);
}
