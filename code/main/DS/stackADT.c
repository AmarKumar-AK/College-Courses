#include<stdio.h>
struct StackADT 
{
	int a[100];
	int top;	
};
void push(struct StackADT *ps,int x);
int pop(struct StackADT *ps);
int isfull(struct StackADT s);
int isempty(struct StackADT s);
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
	printf("Is Stack is full %d \n",isfull(s));
	printf("Is Stack is empty %d \n",isempty(s));
}
void push(struct StackADT *ps,int x)
{
	if(ps->top==99)
		printf("Stack is full");
	else
	{
		ps->top=ps->top+1;
		ps->a[ps->top]=x;
	}
	
}
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

}
int isfull(struct StackADT s)
{
	if(s.top==99)
		return 1;
	else 
		return 0;
}
int isempty(struct StackADT s)
{
	if(s.top==-1)
		return 1;
	else 
		return 0;
}