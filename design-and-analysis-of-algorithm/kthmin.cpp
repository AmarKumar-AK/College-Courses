#include<bits/stdc++.h>
#define SIZE 23
using namespace std;

class Find
{
    public:
        int hits[SIZE];
        void read();
        void print();
        int select(int*, int, int, int, int);
        int partition(int*, int, int, int);

}F;
int kth;
vector<int> vec;
int Find::select(int a[], int beg, int end, int kth, int n)
{
    if(n<=5)
    {
        sort(a+beg,a+n);
        for(int i=0 ; i<n ; ++i )
        {
            cout<<a[i]<<" ";
        }
        cout<<"\nkth smallest is : "<<a[kth-1]<<endl;
    }
    vector<int> vec1;
    vector<int>::iterator it=vec.begin();
    int b[(int)ceil((float)SIZE/5)];
    int c=0;
    cout<<endl;
    for(int i=0 ; i<ceil((float)SIZE/5) ; ++i)
    {
        if(i<SIZE/5)
        {
            sort(it,it+5);
            vec1.push_back(*(it+2));
            //b[c]=*(it+2);
            cout<<"printing sorted array "<<endl;
            cout<<*it<<" "<<*(it+1)<<" "<<*(it+2)<<" "<<*(it+3)<<" "<<*(it+4)<<" "<<endl;
            advance(it,5);
            //cout<<*it<<" ";
        }
        else if(i==SIZE/5)
        {
            if(SIZE%5!=0)
            {
                sort(it,it+SIZE%5);
                vec1.push_back( *(it+ ((SIZE%5) + 1)/2-1) );
                //b[c]=*(it+1);
                cout<<"printing sorted array "<<endl;
                for(int i=0 ; i<SIZE%5 ; ++i)
                {
                    cout<<*(it++)<<" ";
                }
                cout<<endl;
            }
        }
        //c++;
         
    }

    cout<<"median is "<<endl;
    for(it=vec1.begin() ; it<vec1.end() ; ++it)
    {
        //cout<<*it<<" ";
        b[c]=*it;
        cout<<b[c++]<<" ";
    }
    /*for(int i=0 ; i<5 ; ++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;*/
    //int d=n/5;
    //int x=select(b,0,n/5,d/2,n/5);
    //int x=select(b, 0, (int)ceil((float)SIZE/5) , (int)ceil((float)SIZE/5)/2 , (int)ceil((float)SIZE/5))
    



    
}

int Find::partition(int a[],int beg, int end,int pivot)
{
    int k;
	int i = beg;
	int j = end;
	
	

	while (i < j)
	{
		while (a[i] <= pivot)
		{
			
			if (i == k)
				break;
			i++;
		}
		while (a[j] > pivot)
		{
			
			if (j == k)
				break;
			j--;
		}

		if (i < k && j > k)
		{

			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else
		{
			if (i == k && j != k)
			{

				int temp = a[k];
				a[k] = a[j];
				a[j] = temp;
				k = j;
			}//end inner if
			else if (i != k && j == k)
			{
				int temp = a[k];
				a[k] = a[i];
				a[i] = temp;
				k = i;
			}//end else if
		}//end else
	}//end while
	return k;
}


int main()
{
    srand(time(NULL));
    F.read();
    F.print();
    F.select(F.hits,0,SIZE-1,kth,SIZE);
    
    
}//end main function

void Find::read()
{
    for(int i=0 ; i<SIZE ; ++i)
    {
        hits[i]=rand()%100+1;
        vec.push_back(hits[i]);
    }
    cout<<"enter k to find kth smallest : ";
    cin>>kth;
}//end read function

void Find::print()
{
    //vector<int>::iterator it;
    cout<<"array is : "<<endl;
    for(int i=0 ; i<SIZE ; ++i)
    {
        cout<<hits[i]<<" ";
    }
    cout<<endl;
    /*for(it=vec.begin() ; it<vec.end() ; ++it)
    {
        cout<<*it<<" ";
    }*/
}