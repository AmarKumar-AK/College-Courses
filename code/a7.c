#include<stdio.h>
int main()
{
int a[32],b,c,i,r;
printf("enter the number to convert into base r system\n");
scanf("%d",&b);
printf("enter the base\n");
scanf("%d",&r);

c=0;
while(b>r)
{
for(i=0;i<=32;i++)
{
a[i]=b%r;
while(b>=r)
b=b/r;
c++;
}
}
printf("conversio is\n");
for(i=c;i>=0;i--)	
{ 
printf("%d",a[i]);
}

			




}
