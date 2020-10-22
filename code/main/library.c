
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct book
{
	int AccountNumber;
	char BookTitle[100];
	char Author[100];
};
struct library
{
	int top;
	struct book b[100];
};

void IsEmpty(struct library l);//prototype
void IsFull(struct library l);//prototype
void Push(struct library *l,int AccountNumber, char BookTitle[], char Author[]);//prototype
void Pop(struct library *l);//prototype
void Search(struct library l,int AccountNumber);//prototype
void Print(struct library l);//prototype

int main()
{
	struct library l;
	l.top=-1;

	int AccountNumber;
	char BookTitle[100];
	char Author[100];
	
	
	int n;
	while(1)
	{
	printf("what do you want to do?\n1. Push\n2. Pop\n3. check for Full\n4. check for Empty\n5. search\n6. print\n7. exit\n");
	scanf("%d",&n);
	
	switch(n)
	{
		case 1: 	printf("Enter Account Number\n");
					scanf("%d",&AccountNumber);
					printf("Enter Title of the book\n");
					scanf("%s",BookTitle);
					printf("Enter Author Name of the book\n");
					scanf("%s",Author);
					Push(&l,AccountNumber,BookTitle,Author);
					
		break;
		
		case 2: 	Pop(&l);
		break;
		
		case 3: 	IsFull(l);			//Done
		break;
		
		case 4: 	IsEmpty(l);			//Done
		break;
		
		case 5: 	printf("Enter the Account Number\n");
					scanf("%d",&AccountNumber);
					Search(l,AccountNumber);
		break;
		
		case 6: 	Print(l);
		break;
		
		case 7: 	return 0;
		break;
		
	}//switch ends
		
	}//while ends	
		
	
	
}//main function ends


void IsEmpty(struct library l)
{
	if(l.top==-1)
	printf("The list is empty\n");
	else
	printf("The list is not empty\n");
}//IsEmpty ends


void IsFull(struct library l)
{
	if(l.top==100)
	printf("The list is Full\n");
	else
	printf("The list is not full\n");
}//IsFull ends


void Print(struct library l)
{
	int i;
	if(l.top==-1)
	{
		printf("The list is Empty\n");
	}
	else
	for(i=l.top ; i>=0 ; i--)
	{
		printf("(%d)AccountNumber is %d- BookTitle is %s- Author is %s\n",i+1,l.b[i].AccountNumber,l.b[i].BookTitle,l.b[i].Author);
	 	
	}
}//print function ends


void Search(struct library l,int AccountNumber)
{
	int i;
	
	for(i=0;i<=l.top;i++)
	{
		if(l.b[i].AccountNumber==AccountNumber)
		{
			printf("The Account Number is %d\n",l.b[i].AccountNumber);
			printf("The Title of the book is %s\n",l.b[i].BookTitle);
			printf("The Author of the book is %s\n",l.b[i].Author);
			break;
		}
		else if(l.top==-1)
		printf("The list is empty\n");
		
	}
		if(l.b[i].AccountNumber!=AccountNumber && l.top!=-1)	
		printf("The given Data is not present\n");
		
}


void Push(struct library *l,int AccountNumber, char BookTitle[], char Author[])
{
	if(l->top==99)
		printf("Stack is full\n");
	else
	{
		l->top=l->top+1;
		l->b[l->top].AccountNumber=AccountNumber;
		strcpy(l->b[l->top].BookTitle,BookTitle);
		strcpy(l->b[l->top].Author,Author);
		
	}
}


void Pop(struct library *l)
{
	if(l->top==-1)
	printf("There is no book\n");
	else
	{
		(l->top)--;
		printf("\npop is done\n");
	}
}
