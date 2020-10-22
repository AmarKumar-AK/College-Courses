#include<bits/stdc++.h>
using namespace std;		//for c++
/*#include<stdio.h>
#include<stdlib.h>		//for c
#include<math.h>*/

struct node {
int data;
struct node *nptr;
}n;

struct node *hptr=NULL;


int insert();//prototype
int printList();


int main()
{
	
	insert();
return 0;
}//main ends

int insert()
{
	
	
	int coefficient,exponent,x_value,data;
	int sum=0;
	printf("enter the value of x :  ");
	scanf("%d",&x_value);
	while(1)
	{
	//struct node *temp = malloc(sizeof(struct node));			//for c
	struct node *temp = new node;			//for c++
			printf("enter the exponent of x ,-ve number to exit :  ");
		   scanf("%d",&exponent);
		if(exponent>=0)
		{
		 printf("enter the coefficient of x^%d :  ",exponent);
		scanf("%d",&coefficient);
	     data=coefficient*pow(x_value,exponent);
	 		temp->data=data;
	 		temp->nptr=hptr;
    		hptr=temp;
		}
		else
		return printList();
	}//while ends
	
	
	
return 0;
}//insert ends

int printList()
{
int sum=0;
 struct node *temp=hptr;
 do 
 {
  printf("-->%d",temp->data);
  sum=sum+temp->data;
  temp=temp->nptr;
 }while(temp!=NULL); 
 delete temp;// for c++
 printf("\nvalue of polynomial is %d\n",sum);
}
