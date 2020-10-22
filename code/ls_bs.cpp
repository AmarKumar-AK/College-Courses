//program for linearSearch and binarySearch
#include<bits/stdc++.h>
using namespace std;

class Search
{
	private:
		int arr[100];
	public:
		int linearSearch();
		int binarySearch();
		int read();
		int sort();
}s;

int Search::read()
{
	int i;
	int size=100;
	for(i=0 ; i<size ; i++)
	{
		arr[i]=rand()%size+1;
	}
	//generating random numbers
	/*cout<<"generated random number is\n";
	for(int j=0 ; j<size ; j++)
	{
		cout<<arr[j]<<" ";
	}*/
}

int Search::sort()
{
	//cout<<"\nHey this is sort function\n";
	int size=100;
	for(int i=0 ; i<size-1 ; i++)
	{
		for(int j=i ; j>=0 ; --j)
		{
			if(arr[j]>arr[j+1])
			{
				int temp;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	//printing sorted array
	/*cout<<"this is sorted array\n";
	for(int k=0 ; k<size ; k++)
	{
		cout<<arr[k]<<" ";
	}*/

}

int Search::linearSearch()
{
	float sum = 0;
	for(int p=0; p<1000 ; p++)
	{
		int count=0;
		read();
		int data;
		int size=100;
		//cout<<"\nHey this is linear search function\n";
		data=rand()%100+1;
		for(int i=0 ; i<size ; i++)
		{
			count++;
			if(arr[i]==data)
			{
				//printf("%d is present at %dth position",data,i);
				break;
			}
		}
		sum+= (float)count/1000;
	}//outermost for
	cout<<"Total average in linear search is : "<<sum<<endl;
}


int Search::binarySearch()
{
	float sum=0.0;
	for(int p=0; p<1000 ; p++)
	{
		int first = 0; int last = 100;
		read();
		sort();
		int count = 0;
		//cout<<"\nHey this is binarySearch\n";
		int data=rand()%100+1;
		while(last>=first){
			count++;
			int mid=(first+last)/2;
			if(arr[mid]==data)
			{
				break;
			}
			else if(arr[mid]>data)
			{
				last = mid -1;
				}
			else
			{
				first = mid + 1;
			}
		}
		sum+= (float)count/1000;
	}//outermost for
	cout<<"total avg in binary search is "<<sum<<endl;
}

int main()
{
	srand(time(NULL));
	int a[1000];
	s.linearSearch();
	
	s.binarySearch();
	
}
