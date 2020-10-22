#include<stdio.h>
#include<stdlib.h>


struct tree
{
	struct tree *left;
	int data;
	struct tree *right;	
}t;

struct tree *root=NULL;

void insert()
{
	int element;
	struct tree *temp=malloc(sizeof(struct tree));
	printf("enter the data you want to insert :  ");
	scanf("%d",&element);
	temp->data=element;
	temp->left=NULL;
	temp->right=NULL;

	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct tree *ptr=root;
		struct tree *pptr=NULL;
		while(ptr!=NULL)
		{	
			pptr=ptr;
			if(element<ptr->data)
				ptr=ptr->left;
			else
				ptr=ptr->right;
		}
		if(element<pptr->data)
			pptr->left=temp;
		else
			pptr->right=temp;
	}
	
}

void print(struct tree *ptr)
{	
	if(ptr!=NULL)
	{
		printf("-->%d",ptr->data);
 		print(ptr->left);
		print(ptr->right);
	}
	
}

void min(struct tree *t)
{
	struct tree *ptr=root;
	struct tree *pptr=NULL;
	while(ptr!=NULL)
	{
		pptr=ptr;
		ptr=ptr->left;
	}
	printf("minimum is %d\n",pptr->data);
}

void max(struct tree *t)
{
	struct tree *ptr=root;
	struct tree *pptr=NULL;
	while(ptr!=NULL)
	{
		pptr=ptr;
		ptr=ptr->right;
	}
	printf("maximum is %d\n",pptr->data);
}

void main()
{
	int choice;
	
	while(1)
	{
		printf("\n................\nselect your choice:\n1.insert\n2.print\n3.find minimum\n4.find maximum\n5.exit\n...............\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: insert();
			break;
			case 2: print(root);
			break;
			case 3: min(&t);
			break;
			case 4: max(&t);
			break;
			case 5: exit(0);
		}
	}
}

