#include<stdio.h>
void main()
{
int a[10];
printf("enter 10 elements\n");
for(int i=0;i<10;i++)
{
scanf("%d",&a[i]);
}
//////////
for(int j=0 ;j<10 ;j++)
{
	int count=0;
 for(int i=0 ;i<10 ;i++)
 {
  if(a[j]==a[i])
  {
   count++;
  }
 }
printf("no. of times %dth integer repeated is %d\n",j,count);
}

















}
