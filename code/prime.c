#include<stdio.h>
#include<math.h>
void main()
{	/*
		//method 1-to print prime numbers

int a,i,k;
for(a=1;a<=1000;a=a+1)
  { k=0;
for(i=1; i<=a; i++)
    {
if(a%i==0)
	{
	k=k+1;
	}
    }
if(k==2)
	{
	printf("%d ",a);
	}
  }
		
//////////////////////////////////////////////////////////////////////////////////////////////////////
		// method 2-to print prime numbers

int p,q,s;
p=1;
while(p>=1 && p<100)
{
 
 s=0; 
 q=1;
 while(q<=p)
 {
  if(p%q==0)
   {s++;
   }
q++;
 }
 if(s==2)
 {
 printf("%d\n",p);
 }
p++;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
		//to check whether a number is prime or not 

printf("enter the no. to check whether it is prime or not\n");
int i,p,q;
scanf("%d",&i);
q=0;
for(p=1;p<=i;p++)
{

if(i%p==0)
  {
  q++;
  }
}
if(q==2)
  {
  printf("it is a prime number\n");
  }
else
{
printf("it is not a prime number\n");
}

	
//////////////////////////////////////////////////////////////////////////////////////////////////////
		//to print n prime no.

int a,b,c,n;
printf("enter the number of prime numbers you want to print\n");
scanf("%d",&n);
printf("the first %d prime numbers are:\n",n);

int l=1;
for(a=1;a<=10000000;a=a+1)
  { c=0;
{
for(b=1; b<=a; b++)
    {
if(a%b==0)
	{
	c=c+1;
	}
    }

if(c==2)
	{if (l<=n)
	printf("%d \n",a);

	l=l+1;
        }
}
  
}
	*/
///////////////////////////////////////////////////////////////////////////////////////////////////

 

}











