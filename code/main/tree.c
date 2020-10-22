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
	char book_name[20],line[10],author_name[20];		int isbn_no;
		
	struct book *temp=malloc(sizeof(struct book)); 
	
	printf("enter isbn number\n");			scanf("%d",&isbn_no);
	fgets(line,sizeof(line),stdin);
	printf("enter the name of book\n");		fgets(book_name,sizeof(book_name),stdin);
	printf("enter author name\n");			fgets(author_name,sizeof(author_name),stdin);
	
	strcpy(temp->name,book_name);
	temp->isbn=isbn_no;
	strcpy(temp->author,author_name);
	temp->left=NULL;		temp->right=NULL;
	
	int i;
	if(root==NULL)
	{
		root=temp;
		
	}//outer if ends
	
	else
	{
		struct book *ptr=root;//for traversing through the node.
		//struct book *pptr=NULL;
		//checking where to insert the book
		while(ptr->right!=NULL || ptr->left!=NULL)
		{
		//	pptr=ptr;
			if(strcmp(book_name,ptr->name)>=0)
				ptr=ptr->right;
			else
				ptr=ptr->left;
		}
		//inserting book at appropriate node
		if(strcmp(book_name,ptr->name)>=0)
			ptr->right=temp;
		else
			ptr->left=temp;			
		
		
	/*	while((temp->left)->name!=NULL && (temp->right)->name!=NULL)
		{
			if(strcmp(temp->name,book_name)>=0)
			{
				if(temp->right==NULL)
					strcpy(temp->name,book_name);
				else
					temp=temp->right;
			}//if ends
			else
			{
				if(temp->left==NULL)
					strcpy(temp->author,author_name);
				else
				temp=temp->left;
			}//else ends
		}//while ends*/
		
		
	}//outer else ends
}//insert function ends

void delete()
{

}

void search(struct book *b)
{
	struct book *temp=root; char book_name[30];  char line[2];
	fgets(line,sizeof(line),stdin);
	printf("enter the book_name to search : ");
	fgets(book_name,sizeof(book_name),stdin);
	while(strcmp(book_name,temp->name)!=0)
	{
		if(strcmp(temp->name,book_name)>=0)
			temp=temp->right;
		else
			temp=temp->left;
	}
	if(strcmp(book_name,temp->name)!=0)
		printf("the entered book is not present");
	else
		printf("isbn_no -->%d\nbook_name-->%sauthor-->%s" ,temp->isbn, temp->name, temp->author);
	
}

void print(struct book *ptr)
{
	
	if(ptr==NULL)
		return;
		print(ptr->left);
		printf("%s\n",ptr->name);
		print(ptr->right);
	
	
}

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
			case 3: search();
			break;
			case 4: print(root);
			break;
			case 5: return 0;
			
		}
	}
}

