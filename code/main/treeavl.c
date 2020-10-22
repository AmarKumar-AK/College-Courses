#include<stdio.h>
#include<stdlib.h>

struct Tnode
{
   struct Tnode *lcptr;
   int data;
   int height;
   struct Tnode *rcptr;
};

struct Tnode* rptr=NULL;

struct Tnode* insert(struct Tnode *ptr,int x);
struct Tnode* RotateRight(struct Tnode *ptr);
struct Tnode* RotateLeft(struct Tnode *ptr);
struct Tnode* RotateRightLeft(struct Tnode *ptr);
struct Tnode* RotateLeftRight(struct Tnode *ptr);
void updateheight(struct Tnode *ptr);
int findheight(struct Tnode *ptr);
void search();
void print(struct Tnode *ptr);


void main()
{
	
	int choice,x;
	while(1)
	{
		printf("\n1.insert and print inorder\n2.search\n3.exit\nyour option : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\n");
				printf("enter a number to insert : ");
				scanf("%d",&x);
				rptr=insert(rptr,x);
				break;
			case 2: printf("\n");
				search();
				break;
			case 3: exit(1);break;
			default: printf("invalid option !!!\n");
		}
		print(rptr);
		printf("\n");
	}
	
}




struct Tnode* insert(struct Tnode *ptr,int x)
{  
	if(ptr==NULL)
   {
   	ptr=malloc(sizeof(struct Tnode));
		ptr->data=x;	
		ptr->lcptr=NULL;
		ptr->rcptr=NULL;
		ptr->height=0;
	}
	else
	{
		if(x<ptr->data)
		{
			ptr->lcptr=insert(ptr->lcptr,x);
			if(findheight(ptr->lcptr)-findheight(ptr->rcptr)==2 ||findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2)
			{
				
				if(x<ptr->lcptr->data)
					ptr=RotateRight(ptr);
				else
					ptr=RotateLeftRight(ptr);
			} 
		}
		else
		{
			ptr->rcptr=insert(ptr->rcptr,x);
			if(findheight(ptr->lcptr)-findheight(ptr->rcptr)==2 ||findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2)
			{
				if(x>ptr->rcptr->data)
					ptr=RotateLeft(ptr);
				else
					ptr=RotateRightLeft(ptr);
			} 
		}		
	}
	updateheight(ptr);
   return ptr;
}

int findheight(struct Tnode *ptr)
{
	int h1,h2;
	if(ptr==NULL)
	{
		return -1;
	}
	else
	{
 		h1 = findheight(ptr->lcptr);
		h2= findheight(ptr->rcptr);
		if(h1<h2)
			return h2+1;
		else
			return h1+1;
	}
}

void updateheight(struct Tnode *ptr)
{	
   
   int h1,h2;
	if(ptr->lcptr==NULL)
	{
		h1=-1;
	}
	else
		h1=ptr->lcptr->height;
	if(ptr->rcptr==NULL)
	{
		h2=-1;
	}
	else
		h2=ptr->rcptr->height;
	if(h1<h2)
		ptr->height=h2+1;		
	else
		ptr->height=h1+1;
}

struct Tnode* RotateRight(struct Tnode *ptr)
{
	struct Tnode *jptr=ptr;
	struct Tnode *kptr=ptr->lcptr;
	jptr->lcptr=kptr->rcptr;
	kptr->rcptr=jptr;
	updateheight(jptr);
	updateheight(kptr);
	return kptr;
}

struct Tnode* RotateLeft(struct Tnode *ptr)
{
	struct Tnode *jptr=ptr;
	struct Tnode *kptr=ptr->rcptr;
	jptr->rcptr=kptr->lcptr;
	kptr->lcptr=jptr;
	updateheight(jptr);
	updateheight(kptr);
	return kptr;
}

struct Tnode* RotateLeftRight(struct Tnode *ptr)
{
	struct Tnode *jptr=ptr;
	struct Tnode *kptr=ptr->lcptr;
	ptr->lcptr=RotateLeft(kptr);
	return(RotateRight(jptr));
}

struct Tnode* RotateRightLeft(struct Tnode *ptr)
{
	struct Tnode *jptr=ptr;
	struct Tnode *kptr=ptr->rcptr;
	ptr->rcptr=RotateRight(kptr);
	return(RotateLeft(jptr));
}

void print(struct Tnode *ptr)
{
	if(ptr!=NULL)
	{
		print(ptr->lcptr);
		//printf("%d %d ",ptr->data,ptr->height);
		printf("%d ",ptr->data);
		print(ptr->rcptr);
	}
}

void search()
{
	int x,flag=0;
	if(rptr==NULL)
	{	
		printf("AVL tree is empty\n");
		return;
	}
	printf("enter a number to search : ");
	scanf("%d",&x);	
	struct Tnode *t= rptr;
	while(t!=NULL)
	{
        	if(t->data==x)
		{
        	    printf("the number %d is present in the AVL tree\n",t->data);
        	    flag=1;
		    break;
        	}
        	else if(t->data<x)
		    t=t->rcptr;
        	else 
		    t=t->lcptr;
        }
	
	if(flag==0)
		printf("\nno number exits\n");
	

}






