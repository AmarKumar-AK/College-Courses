//program to find maximum value that short int and int can hold
#include<stdio.h>
void main()
{
//to print the maximum value of short int
int a=0;
short int i=0;
while(i>=0)
{

i++;
a++;
}

printf("the largest value of short int is %d\n",a-1);



//to print the maximum value of int
long int p=0;
int q=0;
for(;q>=0;q++)
{
p++;
}
printf("the largest value of int is %d\n",p-1);


}
