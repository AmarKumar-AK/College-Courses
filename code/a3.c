#include<stdio.h>
void main(){
	int flag;
	printf("enter flag value\n");
	scanf("%d",&flag);
	switch(flag)
	{
		default: printf("the value of flag is more than 2\n");
		case 1: printf("the value of flag is one\n");
			printf("i am in CASE 1\n");
		case 2: printf("the value of flag is one\n" );
			printf("i am in CASE 2\n");
	}


	int i=0;
	for(i=0;i<20;i++)
	{
		switch(i)
		{
			case 0: i=i+5;
			case 1: i+=2;
			case 5: i+=5;
			default: i=i+4;
			break;
		}
		printf("the value of is is %d\n",i);
	}






}

