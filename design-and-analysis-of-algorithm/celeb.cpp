#include<bits/stdc++.h>
#define SIZE 5
using namespace std;

class Celebrity
{
		int a[SIZE][SIZE];
	
	public:
		void read();
		int celeb();
}c;


void Celebrity::read()
{
	for(int i=0 ; i<SIZE ; ++i)
	{
		for(int j=0 ; j<SIZE ; ++j)
		{
			cin>>a[i][j];
		}//end inner for
	}//end outer for
	
	
}//end read


int Celebrity::celeb()
{
	read();
	int i,j,counter,index;
	int person[SIZE];
	//assigning number 1 to person--starting from 0
	for(int p=0 ; p<SIZE ; ++p)
	{
		person[p]=1;
	}
	/*for(int p=0 ; p<SIZE ; ++p)
	{
		printf("person[%d]==%d\n",p,person[p]);
	}
	cout<<endl;*/
	///////////check for celebrity////////////
	for(i=0 ; i<SIZE-1 ; i++)
	{
		for(j=i+1 ; j<SIZE ; ++j)
		{
			if(a[i][j]==1)
			{
				person[i]=0;
			}
			else if(a[j][i]==1)
			{
				person[j]=0;
			}
			counter=0;
			for(int k=0 ; k<SIZE ; ++k)
			{
				if(person[k]==1)
				{
					counter++;
					index=k;
				}
			}
			
		}
		if(counter==1)
		{
			break;
		}
		
	}
	/*cout<<"counter is : "<<counter<<endl;
	cout<<"index is : "<<index<<endl;
	for(int p=0 ; p<SIZE ; ++p)
	{
		printf("person[%d]==%d\n",p,person[p]);
	}*/
	///////checking column of celebrity
	int count_column=0;
	for(int k=0 ; k<SIZE ; ++k)
	{
		if(a[k][index]==1)
		{
			count_column++;
		}
	}
	///////checking row of celebrity
	int count_row=0;
	for(int k=0 ; k<SIZE ; ++k)
	{
		if(a[index][k]==1)
		{
			count_row++;
		}
	}
	///////if all column of celebrity is 1 and only one from row is 1
	if(count_column==SIZE && count_row==1)
	{
		cout<<"celebrity is located at index : "<<index<<endl;
	}
	else
	{
		cout<<"no celebrity is present"<<endl;
	}
}


int main()
{
	c.celeb();

}
