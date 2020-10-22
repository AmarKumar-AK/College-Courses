
//program to evaluate postfix expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct stack
{
	
	float st[100];
	//float op1;
	//float op2;
	int top;
};


float pop(struct stack *s);//prototype
void push(struct stack *s, float a);//prototype


void main()
{
	struct stack s;
	s.top=-1;
	char a[100];
	int i;
	printf("enter the expression in postfix\n");
	scanf("%s",a);
	
	//evaluation
	float op2,op1,val;
	
		for(i=0 ; i<strlen(a) ; i++)
		{
			if(a[i]>=48 && a[i]<=57)
			{
				float k=a[i]-48;
				push(&s,k);
				
			}
		else if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/')
			{
				op2=pop(&s);	
				op1=pop(&s);
				
				switch(a[i])
				{
					case '+' : val = op1 + op2;
					break;
					case '-' : val = op1 - op2;
					break;
					case '*' : val = op1 * op2;
					break;
					case '/' : val = op1 / op2;
					break;
				}//switch ends
				
				push(&s,val);
				
			}//elseif ends
		else
		printf("\nerror!!!!\n");
			
		}//for ends
		
		
			val=pop(&s);
			printf("%f\n",val);
			
}//main function ends






void push(struct stack *s, float  a)
{
	s->top++;
	s->st[s->top]=a;
	
}//push function ends


float pop(struct stack *s)
{
	float store=s->st[s->top];
	(s->top)--;
	return store;
}//pop ends
		
