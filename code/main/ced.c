/*

#include<stdio.h>
void main()
{
    int n;
    scanf("%d",&n);
    int i,b[n],c[n],k[n];
    char a[n];
    
    
        scanf("%s",a);
        for(i=0 ; i<n ; i++)
         k[i]=a[i]-97;
    
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&b[i]);
    }
    
   for(i=0 ; i<n ; i++)
    {
    	c[i]=(b[i]+k[i])%26;
    }
    
    for(i=0 ; i<n ; i++)
    {
        printf("%c",c[i]+97);
    }
    
}
*/
/*
#include<stdio.h>
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	
	int i,a[n],p[q],s[q],j;
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0 ; i<q ; i++)
	{
		scanf("%d %d",&p[i],&s[i]);
	}
	
	for(i=0 ; i<n ; i++)
	{
	int sum=0;
		for(j=p[i] ; j<n ; j++)
		{
			sum=sum+a[j];
			if(sum==s[i])
			{
				printf("Yes\n");
				break;
			}
			
		}
		if(sum!=s[i])
		printf("No\n");
		
			
	}
}*/


