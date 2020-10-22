#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct book
{
	struct book *left;
	char name[30];//name of the book
	int isbn;
	char author[30];
	struct book *right;
	
}b;

struct book *root=NULL; //pointer pointing to the root node

void insert()
{
	char book_name[30],line[2],author_name[30];		int isbn_no;
		
	struct book *temp=malloc(sizeof(struct book)); 
	//taking input of isbn_no,book_name,author_name respectively
	printf("enter isbn number\n");			scanf("%d",&isbn_no);
	fgets(line,sizeof(line),stdin);
	printf("enter the name of book\n");		fgets(book_name,sizeof(book_name),stdin);
	printf("enter author name\n");			fgets(author_name,sizeof(author_name),stdin);
	//storing isbn_no,book_name,author_name respectively
	strcpy(temp->name,book_name);
	temp->isbn=isbn_no;
	strcpy(temp->author,author_name);
	temp->left=NULL;		temp->right=NULL;
	
	
	if(root==NULL)
	{
		root=temp;
	}//outer if ends
	
	else
	{
		struct book *ptr=root;//for traversing through the node.
		struct book *pptr=NULL;//pointer pointing parent node of ptr
		//checking where to insert the book
		while(ptr!=NULL)
		{	
			pptr=ptr;
			if(strcmp(book_name,ptr->name)<0)
				ptr=ptr->left;
			else
				ptr=ptr->right;
		}
		//inserting book at appropriate node
		if(strcmp(book_name,pptr->name)<0)
			pptr->left=temp;
		else
			pptr->right=temp;			
		
	}//outer else ends
}//insert function ends

void delete(struct book *b)
{
	char line[2];	char book_name[30];
	fgets(line,sizeof(line),stdin);
	printf("enter the book_name to delete : ");
	fgets(book_name,sizeof(book_name),stdin);
	struct book *ptemp=NULL;
	struct book *ptr=root;
	struct book *pptr=NULL;
	while(ptr!=NULL && strcmp(book_name,ptr->name)!=0)
	{
		pptr=ptr;
		if(strcmp(book_name,ptr->name)<0)
			ptr=ptr->left;
		else
			ptr=ptr->right;
	}//while ends
	if(ptr==NULL)						//correct
		printf("\nNo data found\n");
	//for deleting the only root node present
	else if(root->left==NULL && root->right==NULL)			//correct
	{
		root=NULL;
		printf("\ndeleted sucessfully\n");
	}//else if ends
	
	//for deleting the node which has no left and no right node
	else if(ptr->left==NULL && ptr->right==NULL)			//correct
	{
		if(strcmp(book_name,pptr->name)<0)
		{
			pptr->left=NULL;
			printf("\ndeleted sucessfully\n");
		}//if ends
		else
		{
			pptr->right=NULL;
			printf("\ndeleted sucessfully\n");
		}//else ends
	}//else if ends
	
	else if(ptr->left==NULL || ptr->right==NULL)				//correct
	{
		if(strcmp(book_name,pptr->name)<0 && ptr->left!=NULL)
		{
			pptr->left=ptr->left;
			printf("\ndeleted sucessfully\n");
		}
		else if(strcmp(book_name,pptr->name)<0 && ptr->left==NULL)
		{
			pptr->left=ptr->right;
			printf("\ndeleted sucessfully\n");
		}
		else if(strcmp(book_name,pptr->name)>=0 && ptr->left!=NULL)
		{
			pptr->right=ptr->left;
			printf("\ndeleted sucessfully\n");
		}
		else
		{
			pptr->right=ptr->right;
			printf("\ndeleted sucessfully\n");
		}
		
	}
	else
	{
		struct book *temp=ptr;
		ptemp=temp;
		temp=temp->right;
		if(temp->left==NULL)
		{
			strcpy(ptr->name,temp->name);
			ptemp->right=NULL;
			printf("\ndeleted sucessfully\n");
		}
		else
		{
			while(temp->left!=NULL)
			{
				ptemp=temp;
				temp=temp->left;
			} 
			strcpy(ptr->name,temp->name);
			ptemp->left=NULL;
			printf("\ndeleted sucessfully\n");
		}	
	}
	
}

void search(struct book *b)
{
	struct book *temp=root; char book_name[30];  char line[2];
	fgets(line,sizeof(line),stdin);
	printf("enter the book_name to search : ");
	fgets(book_name,sizeof(book_name),stdin);
	printf("-----1");
	if(root==NULL)
		printf("nothing to search\n");
	else
	{
		while(strcmp(book_name,temp->name)!=0)
		{
			if(strcmp(book_name,temp->name)<0)
					temp=temp->left;
			else
					temp=temp->right;
		}
		if(strcmp(book_name,temp->name)!=0)
			printf("the entered book is not present");
		else
			printf("\nisbn_no -->%d\nbook_name-->%sauthor-->%s" ,temp->isbn, temp->name, temp->author);
	}
}

void print(struct book *ptr)
{
	if(ptr!=NULL)
	{
		print(ptr->left);
		printf("%s",ptr->name);
		print(ptr->right);
	}//if ends
	
}//print ends

int main()
{
	int a;
	while(1)
	{
		printf("what do you want to do?\n1.insert\n2.delete\n3.search\n4.print\n5.exit\n...................\n");
		scanf("%d",&a);
		
		switch(a)
		{
			case 1: insert();
			break;
			case 2: delete(&b);
			break;
			case 3: search(&b);
			break;
			case 4: print(root);
			break;
			case 5: return 0;
			
		}//switch ends
	}//while ends
}//main ends

