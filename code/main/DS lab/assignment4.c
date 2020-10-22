#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

typedef struct node
{
	struct node *lcptr;
	char name[50];
	int pnr;
	int seatNumber;
	int fare;
	struct node *rcptr;
	int h;//h-height
}ST;

struct node *rptr=NULL;
void print(struct node *ptr);
void printTicket();
int findheight(struct node *ptr);
ST *insert(struct node *ptr,char *name);
struct node* rotateright(struct node *ptr);
struct node* rotateleft(struct node *ptr);
struct node* rotateleftright(struct node *ptr);
struct node* rotaterightleft(struct node *ptr);
void updateheight(struct node *ptr);


void main()
{
  int choice;
	while(1)
	{
		printf("what is your choice?\n1.Book a ticket\n2.print all tickets\n3.print the ticket\n4.exit\n............\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\n");
						char name[50],line[2];
						fgets(line,sizeof(line),stdin);
						printf("enter the name of passenger : ");
						fgets(name,sizeof(name),stdin);
							rptr=insert(rptr,name);
			break;
			case 2: print(rptr);
			break;	
		 	case 3: printTicket();
			break;
		 	case 4: exit(0);
		}//end switch
	} //end while
}//end main

struct node* insert(struct node *ptr,char *name)
{
	if(ptr==NULL)
	{
		ptr=malloc(sizeof(struct node));
		strcpy(ptr->name,name);
   	ptr->pnr=rand()%1000+1;
    	ptr->seatNumber=rand()%100+1;
    	ptr->fare=rand()%5000+1;
		ptr->lcptr=NULL;
		ptr->rcptr=NULL;
		ptr->h=0;
  }
  else
  {
		if(strcmp(name,ptr->name)<0)
		{
 			ptr->lcptr=insert(ptr->lcptr,name);
			if(findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2 || findheight(ptr->lcptr)-findheight(ptr->rcptr)==2)
			{
				if(strcmp(name,ptr->lcptr->name)<0)
					ptr=rotateright(ptr);
				else
					ptr=rotateleftright(ptr);
			}
		}
		else
		{
			ptr->rcptr=insert(ptr->rcptr,name);
			if(findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2 || findheight(ptr->lcptr)-findheight(ptr->rcptr)==2)
			{
				if(strcmp(name,ptr->rcptr->name)>=0)
					ptr=rotateleft(ptr);
				else
					ptr=rotaterightleft(ptr);
			}
		}
  }
	updateheight(ptr);
	return ptr;
}

void print(struct node *ptr)
{
	if(ptr!=NULL)
 {
		print(ptr->lcptr);
		printf("Name--> %sseatNumber--> %d\nfare--> %d\n pnr-->%d\n\n balancing factor-->%d\n",ptr->name,ptr->seatNumber,ptr->fare,ptr->pnr,findheight(ptr->lcptr)-findheight(ptr->rcptr));
		print(ptr->rcptr);
 } 
}

int findheight(struct node *ptr)
{
	int h1,h2;
	if(ptr==NULL)
		return -1;
	else
   {
  		h1=findheight(ptr->lcptr);
		h2=findheight(ptr->rcptr);
		if(h1>h2)
  		return h1+1;
		else
		return h2+1;
   }//end else
}

void updateheight(struct node *ptr)
{ 
	int h1,h2;
	if(ptr->lcptr==NULL)
		 h1=-1;
	else
		h1=ptr->lcptr->h;
	if(ptr->rcptr==NULL)
		 h2=-1;
	else
		h2=ptr->rcptr->h;
	if(h1>h2)
		  ptr->h=h1+1;
	else
		  ptr->h=h2+1;
}


struct node* rotateleft(struct node *ptr)
{
	struct node *jptr=ptr;
	struct node *kptr=ptr->rcptr;
	jptr->rcptr=kptr->lcptr;
	kptr->lcptr=jptr;
   updateheight(jptr);
	updateheight(kptr); 
	return kptr;
}

struct node* rotateright(struct node *ptr)
{
	struct node *jptr=ptr;
	struct node *kptr=ptr->lcptr;
	jptr->lcptr=kptr->rcptr;
	kptr->rcptr=jptr;
   updateheight(jptr);
	updateheight(kptr);
  	return kptr;
}



struct node* rotateleftright(struct node *ptr)
{
	struct node *jptr=ptr;
	struct node *kptr=ptr->lcptr;
  	jptr->lcptr=rotateleft(kptr);
  	return rotateright(jptr);
}


struct node* rotaterightleft(struct node *ptr)
{
	struct node *jptr=ptr;
	struct node *kptr=ptr->rcptr;
  	jptr->rcptr=rotateright(kptr);
  	return rotateleft(jptr);
}

void printTicket()
{
	 printf("Enter the PNR to search for the ticket - ");
	 int a;
	 scanf("%d",&a);
	 ST *ptr=rptr;
	 while(ptr!=NULL)
	 {
	  	if(a<ptr->pnr)
		 ptr=ptr->lcptr;
	  	else if(a>ptr->pnr)
		 ptr=ptr->rcptr;
	  	else if(ptr->pnr==a)
	  	{
			printf("Name--> %sseatNumber--> %d\nfare--> %d \npnr-->%d\n",ptr->name,ptr->seatNumber,ptr->fare,ptr->pnr);
	  		break;
		}
	  
	 }
	if(ptr==NULL)
	  printf("%d is not present\n",a);
}
