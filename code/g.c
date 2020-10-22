#include<stdio.h>
int main()
{
	char dictionary[10][7]={"in","ring","run","hug","it","turn","z","mime","xyz","pqr"};
	char word[7];//="turing";

	printf("enter the char\n");
	scanf("%s",word);
	printf("these are the meaningfull subset of the word\n");
for(int i=0 ; i<10;i++)
{
	int k=0;
	int counter=0;
for(k=0;dictionary[i][k]!=0;k++)
{
for (int j=0;j<7;j++)
	{
	 if(word[j]==dictionary[i][k])
	 {
	  counter=counter+1;
	 }
	}
}
	if(counter==k)
	printf("'%s'",dictionary[i]);
}
}
