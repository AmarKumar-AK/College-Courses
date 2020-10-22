/*#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n; 
	printf("Enter the size of array :  ");
	scanf("%d",&n);
	
	int i,a[n];
	printf("enter the elements in the array\n");
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&a[i]);
	}
	int j;
	int dis=n;//to store the value of n
	for(i=0 ; i<n-1 ; i++)
	{
		for(j=i+1 ; j<n ; j++)
		{
			if(a[i]==a[j])
			{
				dis--;
				break;
			}
		}	
	}
	
	printf("the number of distinct numbers in the array is %d\n",dis);
	
	return 0;
}*/

#include<bits/stdc++.h>
#define size 10
using namespace std;
int main()
{
vector<int> list;
int a[10],i;
for(i=0 ; i<size ; i++)
{
	scanf("%d",&a[i]);
	list.push_back(a[i]);
}

for(i=0 ; i<size ; i++)
{
	printf("%d ",list[i]);
}
}
