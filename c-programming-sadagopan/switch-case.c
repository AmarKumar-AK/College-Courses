#include<stdio.h>
#define X 29
void main()
{

int a;

int x1=5, b=7;

x1=(x1=b*3)+(x1=x1*3);

printf("%d %d", x1,b);

printf("\n \nenter the value of a \n");
scanf("%d",&a);
//int x=29;
a=a=2;
const int x=29;
switch(a)
{

default:  printf("the value of a is something %d \n",a);

case 11: 
{ printf("the value of a is %d \n",1); 

switch(1)

{

case 1: printf("switch inside switch");

}
}


case 10: printf("the value of a is %d \n", 10); 

case 2: printf("the value of a is %d \n",2); 


case 1+2+3:  printf("case with arithmetic");

case (X): printf("case with addn");


case 1>2: printf("false statment"); break;

case (3>2 && 40>5): printf("true st"); break;

/*
if()

{
printf(" it is a natural no");

}

else

printf("it is a real number");
*/

//case 1: printf("two sts with same case labels");



//case a>=80 && a<90 : printf("the value of a is known during run-time");

/*

switch (a>=90)

case 1

case 0

{
switch (a>=80)

case 1

case 0

{
switch(a>=70)

case 1

case 0
}

}

*/



}
}
