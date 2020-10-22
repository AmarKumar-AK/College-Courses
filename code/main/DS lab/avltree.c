#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *lcptr;
	int a,t;//a-aadhar;  t-telephone
	struct node *rcptr;
	int h;//h-height
};

struct node *rptr=NULL;
void print(struct node *ptr);
int findheight(struct node *ptr);
struct node* insert(struct node *ptr,int p,int q);
struct node* rotateright(struct node *ptr);
struct node* rotateleft(struct node *ptr);
struct node* rotateleftright(struct node *ptr);
struct node* rotaterightleft(struct node *ptr);
void updateheight(struct node *ptr);
void search();

void main()
{
  int x,p,q;
	while(1)
	{

		printf("\nwhat do you want to do?\n1. Insert\n2. Print\n3. Search\n4. Exit\n.................\n");
	  	scanf("%d",&x);
		switch(x)
		{
			case 1: printf("Enter Aadhar and telephone no.\n");
							scanf("%d%d",&p,&q);//p-aadhar;	q-telephone
							rptr=insert(rptr,p,q);
			break;
			case 2: print(rptr);
			break;	
		 	case 3: search();
			break;
		 	case 4: exit(0);
		}//end switch
	} //end while
}//end main

struct node* insert(struct node *ptr,int p,int q)
{
	if(ptr==NULL)
	{
		ptr=malloc(sizeof(struct node));
   	ptr->a=p;
		ptr->t=q;
		ptr->lcptr=NULL;
		ptr->rcptr=NULL;
		ptr->h=0;
  }
  else
  {
		if(p<ptr->a)
		{
 			ptr->lcptr=insert(ptr->lcptr,p,q);
			if(findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2 || findheight(ptr->lcptr)-findheight(ptr->rcptr)==2)
			{
				if(p<ptr->lcptr->a)
					ptr=rotateright(ptr);
				else
					ptr=rotateleftright(ptr);
			}
		}
		else
		{
			ptr->rcptr=insert(ptr->rcptr,p,q);
			if(findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2 || findheight(ptr->lcptr)-findheight(ptr->rcptr)==2)
			{
				if(p>=ptr->rcptr->a)
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
		printf("-->%d",ptr->t);
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

void search()
{
	 printf("Enter the number you want to search -\n");
	 int a;
	 scanf("%d",&a);
	 struct node *ptr=rptr;
	 while(ptr!=NULL)
	 {
	  	if(a<ptr->t)
		 ptr=ptr->lcptr;
	  	else if(a>ptr->t)
		 ptr=ptr->rcptr;
	  	else if(ptr->t==a)
	  	{
			printf("%d is present\n",ptr->t);
	  		break;
		}
	  
	 }
	if(ptr==NULL)
	  printf("%d is not present\n",a);
}
