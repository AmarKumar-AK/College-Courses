#include<stdio.h>
void main()
{
int a[3],b[3],c[3];
///////
printf("enter the marks for three rounds for A\n");
for(int i=0;i<3;i++)
 {
  scanf("%d",&a[i]); 
 }
printf("enter the marks for three rounds for B\n");
for(int i=0;i<3;i++)
 {
  scanf("%d",&b[i]); 
 }
printf("enter the marks for three rounds for C\n");
for(int i=0;i<3;i++)
 {
  scanf("%d",&c[i]); 
 }
////////
printf("marks of A for three rounds are ");
for(int i=0;i<3;i++)
 {
  printf(" %d ",a[i]);
 }
printf("\nmarks of B for three rounds are ");
for(int i=0;i<3;i++)
 {
  printf(" %d ",b[i]);
 }
printf("\nmarks of c for three rounds are ");
for(int i=0;i<3;i++)
 { 
  printf(" %d ",c[i]);
 }
////////
printf("\nGrade of first student for three rounds are ");
for(int i=0;i<3;i++)
  {
switch(a[i])
{
case 2: printf(" A"); break;
case 3: printf(" A"); break;
case 4: printf(" S"); break;
case 5: printf(" S"); break;
case 0: printf(" B"); break;
case 1: printf(" B"); break;
}
  }
//////
printf("\nGrade of second student for three rounds are");
for(int i=0;i<3;i++)
  {
switch(b[i])
{
case 2: printf(" A"); break;
case 3: printf(" A"); break;
case 4: printf(" S"); break;
case 5: printf(" S"); break;
case 0: printf(" B"); break;
case 1: printf(" B"); break;
}
  }
///////
printf("\nGrade of third student for three rounds are");
for(int i=0;i<3;i++)
  {
switch(c[i])
{
case 2: printf(" A"); break;
case 3: printf(" A"); break;
case 4: printf(" S"); break;
case 5: printf(" S"); break;
case 0: printf(" B"); break;
case 1: printf(" B"); break;
}
  }
printf("\n");
////////
a[3]=a[0];
for(int i=0;i<3;i++)
if(a[i]>=4)
{
printf("first student is carnatic singer\n");
}
else if(a[i]+a[i++]>=4)
{
printf("first student is carnatic singer\n");
}

/////////
b[3]=b[0];
for(int i=0;i<3;i++)
if(b[i]>=4)
{
printf("second student is carnatic singer\n");
}
else if(b[i]+b[i++]>=4)
{
printf("second student is carnatic singer\n");
}

/////////
c[3]=c[0];
for(int i=0;i<3;i++)
if(c[i]>=4)
{
printf("third student is carnatic singer\n");
}
else if(c[i]+c[i++]>=4)
{
printf("third student is carnatic singer\n");
}
///////////
float p=(a[0]+a[1]+a[2])/3;
float q=(b[0]+b[1]+b[2])/3;
float r=(c[0]+c[1]+c[2])/3;
//////////
printf("the avg marks of first student is %f\n",p);
printf("the avg marks of second student is %f\n",q);
printf("the avg marks of third student is %f\n",r);
}
