//program to find 1st max and 2nd max
#include<stdio.h>
void main()
{
int a[5],first,second,b,c;
printf("enter 5 numbers\n");
for(int i=0;i<5;i++)
{
scanf("%d",&a[i]);
}
/////////
int max=a[0]+a[1];
for(int j=0;j<5;j++)
 {
  for(int i=1;i<5;i++)
   {
     if(j!=i)
      {
       if((a[j]+a[i])>max)
        {
         max=a[j]+a[i];
         b=j;
         c=i;
       
         
        }
     }
   }
 }
///////////
if(a[b]>a[c])
{
first=a[b];
second=a[c];
}
else
{
first=a[c];
second=a[b];
}
printf("max and second max are %d and %d resectively\n",first,second);





}
