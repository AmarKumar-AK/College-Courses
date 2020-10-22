#include<stdio.h>
struct StackADT 
{
	int a[100];
	int top;	
};
void push(struct StackADT *ps,int x);//prototype
int pop(struct StackADT *ps);//prototype
int isFull(struct StackADT s);//prototype
int isEmpty(struct StackADT s);//prototype

//main function starts
int main()
{
	struct StackADT s;
	s.top=-1;
	push(&s,10);
	push(&s,20);
	push(&s,30);
	push(&s,40);
	printf("%d is poped element \n",pop(&s) );
	printf("%d is poped element \n",pop(&s) );
	printf("%d is poped element \n",pop(&s) );
	printf("%d is poped element \n",pop(&s) );
	printf("%d is poped element \n",pop(&s) );
	printf("Is Stack is full %d \n",isFull(s));
	printf("Is Stack is empty %d \n",isEmpty(s));
}//main function ends


void push(struct StackADT *ps,int x)
{
	if(ps->top==99)
		printf("Stack is full");
	else
	{
		ps->top=ps->top+1;
		ps->a[ps->top]=x;
	}
	
}//push function ends
int pop(struct StackADT *ps)
{
	
	int x=-1;
	if(ps->top==-1)
		printf("Stack is empty\n");
	else 
	{
		x=ps->a[ps->top];
		ps->top=ps->top-1;
	}
	return x;

}//pop function ends
int isFull(struct StackADT s)
{
	if(s.top==99)
		return 1;
	else 
		return 0;
}//isFull function ends
int isEmpty(struct StackADT s)
{
	if(s.top==-1)
		return 1;
	else 
		return 0;
}//isEmpty function ends
