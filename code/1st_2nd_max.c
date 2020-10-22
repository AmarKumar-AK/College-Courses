//program to find 1st max and 2nd max
#include<stdio.h>
void main()
{
int a[5],first,second;
printf("enter 5 numbers\n");
for(int i=0;i<5;i++)
{
scanf("%d",&a[i]);
}
////////
first=a[0];
for(int i=1;i<5;i++)
{ 
if(a[i]>first)
   {
    second=first;
    first=a[i];
    printf("first is %d\n",first);
    printf("second is %d\n",second);
   }
}
printf("the largest no. is %d\n",first);
printf("the 2nd largest no. is %d\n",second);

}
