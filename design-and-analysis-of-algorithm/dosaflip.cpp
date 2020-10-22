#include<bits/stdc++.h>
#define SIZE 5
using namespace std;

class Dosa
{
		int radius[SIZE];
	public:
		void read();
		int flip();	
}d;

void Dosa::read()
{
	cout<<"enter the radius of 5 dosa"<<endl;
	for(int i=0 ; i<SIZE ; ++i)
		cin>>radius[i];
}


int Dosa::flip()
{
	read();
	int size=SIZE;
	//calculating maximum radius
	for(int i=0 ; i<SIZE ; ++i)
	{
		int max=radius[0];
		int imax=0;
		
		for(int j=0 ; j<SIZE-i ; ++j)
		{
			if(radius[j]>max)
			{
				max=radius[j];
				imax=j;
			}	
		}
		if(imax==size-1)
		{
			size--;
			continue;
		}
		cout<<"max is : "<<max<<endl;
		for(int k=0 ; k<=imax ; ++k)
		{
			int temp=radius[k];
			radius[k]=radius[imax];
			radius[imax]=temp;
			imax--;
		}
		//printing after first flip
		for(int i=0 ; i<SIZE ; ++i)
		{
		cout<<radius[i]<<" ";
		}
		cout<<endl;
		
		//printing after second flip
		for(int k=0 ; k<size-k ; ++k)
		{
			int temp=radius[k];
			radius[k]=radius[size-1-k];
			radius[size-1-k]=temp;
		}
		size--;
		for(int i=0 ; i<SIZE ; ++i)
		{
		cout<<radius[i]<<" ";
		}
		cout<<endl;
		
	}
	
	
}

int main()
{
	d.flip();

}
