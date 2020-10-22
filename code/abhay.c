#include<stdio.h>
#include<math.h>
int decimaltooctal(int decimalnumber);
int main()
{
   int decimalnumber,R;
   printf("\nenter a decimal no.");
   scanf("%d",&decimalnumber);
   R=decimaltooctal(decimalnumber);
   printf("\noctal of %d =%d",decimalnumber,R);
     return 0;
     }
     
int decimaltooctal(int decimalnumber)
{ 
	int octalnumber=0,i=1;
     	while(decimalnumber=!0)
     	{ 
     		octalnumber=octalnumber+(decimalnumber%8)*i;
     		decimalnumber=decimalnumber/8;
     		i=i*10;
    	} 
    	return octalnumber;
}
     
