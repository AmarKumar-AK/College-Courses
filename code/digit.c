#include<stdio.h>
#include<math.h>
int main()
{
/*
		//to print all the digts
int num;

printf("enter the number\n");
scanf("%d",&num);

while(num!=0)
{
int digit=num%10;
num=num/10;
printf(" %d",digit);
}
*/
/////////////////////////////////////
/*
		//to count the number of digits
int count=0,n;

printf("enter the number\n");
scanf("%d",&n);

while(n!=0)
{
n=n/10;
++count;
}
printf("%d is the number of digit",count);
*/
////////////////////////////////
/*

		//to print first n digits of an integer
int a,b,d,n,c=0;

printf("enter the number\n"); //a is input number
scanf("%d",&a);
d=a;
printf("enter the number of digits to be printed from beginning\n");
scanf("%d",&n);  //n is no. of digits to be printed
while(a!=0)
{
a=a/10;
++c;
}
printf("the value of c is %d\n",c);
b=c-n;
printf("the value of b is %d\n",b);
b=d/(pow(10,b));
printf("the value of b is %d\n",b);
printf("the first %d digits is %d ",n,b); 
*/







}
