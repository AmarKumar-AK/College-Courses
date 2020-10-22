#include<stdio.h>
#include<math.h>
void main()
{
// binary to decimal conversion
int a[32],b,c;
printf("enter the binary to convert into decimal\n");
scanf("%d",&b);
int sum=0;

c=0;
for(int i=0;i<32;i++)
{
	a[i]=b%10;
	b=b/10;
	
	
	a[i]=a[i]*pow(2,c);
c++;
}

for(int i=0; i<32; i++)
{
 sum=sum+a[i];

}
printf("the decimal equivalent is %d",sum);
puts("");








}
