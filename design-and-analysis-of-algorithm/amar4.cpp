#include<bits/stdc++.h>
#define SIZE 5
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
struct dict f[SIZE+1];
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
		f[i].word=di.d[i].word;
		f[i].meaning=di.d[i].meaning; 
		//cout<<f[x].word<<" : "<<f[x].meaning<<endl;
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
				e[k].meaning = di.d[i].meaning;
				++k;
				++i;
			}//inner if
			else
			{
				e[k].word = di.d[j].word;
				e[k].meaning = di.d[j].meaning;
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

void addWord()
{
	string new_word,new_meaning;
	cout<<"enter new word and its meaning "<<endl;
	cin>>new_word>>new_meaning;
	int y=0;
	while(y<SIZE)
	{
		if(new_word>di.d[y].word)
		{
			y++;
			continue;
		}
		else
		{
			break;
		}
		
	}
	/*int store;
	for(y=0 ; y<SIZE ; ++y)
	{
		if(new_word>di.d[y].word)
		{
			continue;
		}
		else
		{
			break;
		}
		
		
	}*/
	//cout<<"y is "<<y<<endl;
	//cout<<"SIZE is "<<SIZE<<endl;
	for(int k=SIZE ; k>=y ; --k )
	{
		
		f[k].word=f[k-1].word;
		f[k].meaning=f[k-1].meaning;
	}
	f[y].word=new_word;
	f[y].meaning=new_meaning;
	for(int x=0 ; x<=SIZE ; x++)
	{
		cout<<f[x].word<<" : "<<f[x].meaning<<endl;
	}
}

/////////////////////////////////////////////////////////////
int main()
{
	//for reading word and meaning
	cout<<"enter word and meaning separated by space"<<endl;
	di.read();
	
	di.mergeSort(0,SIZE-1);
	
	//for printing word and meaning
	cout<<"words along with meaning are "<<endl;
	di.print();
	addWord();
	
}






