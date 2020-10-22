#include<bits/stdc++.h>
#define SIZE 10
using namespace std;

struct dict
{
		string word;
		string meaning;
};

class dictionary
{
	public:
		struct dict d[SIZE];
		
		void read();
		void print();
		void mergeSort(int, int);
		void merge(int, int);
	
}di;


/////////////////////////////////////////////////

void dictionary::read()
{
	for(int i=0 ; i<SIZE ; ++i)
	{
		cin >>di.d[i].word >>di.d[i].meaning;
	}//end for
}

/////////////////////////////////////////////////

void dictionary::print()
{
	for(int i=0 ; i<SIZE ; ++i)
	{
		cout << di.d[i].word << " : " << di.d[i].meaning<<endl; 
	}//end for
}

/////////////////////////////////////////////////
void dictionary::mergeSort(int beg, int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		mergeSort(beg,mid);
		mergeSort(mid+1,end);
		merge(beg,end);
	}//end if
}//end mergeSort function

//////////////////////////////////////////////////

void dictionary::merge(int beg, int end)
{
	struct dict e[end-beg+1];
	int mid=(beg+end)/2;
	int i=beg;
	int j=mid+1;
	int k=0;
	
	while(i<=mid && j<=end)
	{
			if(di.d[i].word < di.d[j].word)
			{
				e[k].word = di.d[i].word;
				e[k].meaning=di.d[i].meaning;
				++k;
				++i;
			}//inner if
			else
			{
				e[k].word = di.d[j].word;
				e[k].meaning=di.d[j].meaning;
				++k;
				++j;
			}//inner else if
		
	}//end while
	
	//copy remaining elements
	while(j<=end)
	{
			e[k].word=di.d[j].word;
			e[k].meaning=di.d[j].meaning;
			++k;
			++j;
	
	}//end if
	while(i<=mid)
	{
		
			e[k].word=di.d[i].word;
			e[k].meaning=di.d[i].meaning;
			++k;
			++i;

	}//end else
	//cout<<"Hello world"<<endl;
	
	//copying all element in original dictionary
	int m=0;
	for(int x=beg ; x<=end ; ++x)
	{
		di.d[x].word=e[m].word;
		di.d[x].meaning=e[m].meaning;
		m++;
	}//end for x
	
}

//////////////////////////////////////////////////////////////

int main()
{
	//for reading word and meaning
	cout<<"enter word and meaning separated by space"<<endl;
	di.read();
	
	di.mergeSort(0,SIZE-1);
	
	//for printing word and meaning
	cout<<"words along with meaning are "<<endl;
	di.print();
	
	
}






