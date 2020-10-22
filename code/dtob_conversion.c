#include<stdio.h>
void main()
{
// decimal to binary conversion
int a[32],b,i;
printf("enter the number to convert into binary\n");
scanf("%d",&b);
int counter=0;
for( i=0; i<=32 && b>0; i++)
{
a[i]=b%2;
printf("the value of a[%d] is %d\n",i,a[i]);
b=b/2;
printf("the value of b is %d\n",b );
counter++;
}
printf("binary conversion is\n");
for(i=counter-1; i>=0; i=i-1)
{
printf("%d",a[i]);

}

printf("\n");




}
