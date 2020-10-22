#include<stdio.h>
#include<stdlib.h>
struct Tnode
{
	struct Tnode *lcptr;
	int data;
	int height;
   struct Tnode *rcptr;
}*rptr=NULL;
struct Tnode* insert(struct Tnode *ptr,int x);
void updateheight(struct Tnode *ptr);
int findheight(struct Tnode *ptr);
struct Tnode* RotateRight(struct Tnode *ptr);
struct Tnode* RotateLeft(struct Tnode *ptr);
struct Tnode* RotateRightLeft(struct Tnode *ptr);
struct Tnode* RotateLeftRight(struct Tnode *ptr);
void print(struct Tnode *ptr)
{
	if(ptr!=NULL)
	{
		print(ptr->lcptr);
		printf("%d %d ",ptr->data,ptr->height);
		print(ptr->rcptr);
	}
}
void main()
{
	
	rptr=insert(rptr,50);
	rptr=insert(rptr,40); 
	rptr=insert(rptr,45);
	rptr=insert(rptr,70);
	rptr=insert(rptr,100);
	rptr=insert(rptr,55);
	print(rptr);
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
	}//end if
	else
	{
		if(x<ptr->data)
		{
			ptr->lcptr=insert(ptr->lcptr,x);
			if(findheight(ptr->lcptr)-findheight(ptr->rcptr)==2 ||findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2)
			{
				
				if(x<ptr->lcptr->data)//if x is present in left side of pointer
					ptr=RotateRight(ptr);
				else
					ptr=RotateLeftRight(ptr);
			}//end inner if 
		}//end outer if
		else
		{
			ptr->rcptr=insert(ptr->rcptr,x);
			if(findheight(ptr->lcptr)-findheight(ptr->rcptr)==2 ||findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2)
			{
				if(x>ptr->rcptr->data)//if x is present in right side of pointer
					ptr=RotateLeft(ptr);
				else
					ptr=RotateRightLeft(ptr);
			} //end inner if
		}//end outer else		
	}//end else
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






