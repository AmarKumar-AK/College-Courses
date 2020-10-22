
#include<stdio.h>
int print(int array[]);

int main(){
	int ar[] = {1,5,2,6,4};
	print(ar);
}

int print(int array[])
{
	for(int i=0; i<5; i++)
	{
		printf("%d ",array[i]);
	}
	puts("");
}
