#include<bits/stdc++.h>
#define SIZE 13
using namespace std;

class Find
{
    
    public:
        void read();
        void print();
        int select(int*, int, int, int, int);
        int partit(int*, int, int, int);

}F;

int kth;
vector<int> vec;

int hits[]={25,57,20,85,63,         45,72,5,32,16,         98,4,9};
//int hits[]={5,8,4,6,2};
//kth is starting from 0
int Find::select(int a[], int beg, int end, int kth, int n)
{
    cout<<"n is : "<<n<<endl;
    int z[n];
    for(int i=beg ; i<=end ; ++i)
    {
        z[i]=a[i];
        //cout<<"z[i] is : "<<z[i]<<endl;
        printf("z[%d] is : %d \n",i,z[i]);
    }
    
    if(n<=5 && n>0)
    {
        int b[n];
        sort(z+beg,z+end+1);
        for(int i=beg ; i<=end ; ++i)
        {
            b[i]=z[i];
            //cout<<"b[i] is : "<<b[i]<<endl ;
            printf("b[%d] is : %d \n",i,b[i]);
        }
        cout<<"kth inside n<=5 : "<<kth<<endl;
        return b[(beg+end)/2-1];
    }
    
    int r=n%5;
    //cout<<"r is "<<r<<endl;
    //cout<<"n is "<<n<<endl;
    int size=ceil((float)n/5);
    int b[size-1];
    int counter=0;
    for(int i=0 ; i<n-r ; i=i+5)
    {
        sort(z+i,z+i+5);
        b[counter]=z[i+2];
        cout<<"b[counter] before is "<<b[counter++]<<endl;
    }
    if(n%5!=0 && n>5)
    {
        sort(z+n-r,z+n);
        if(r==1)
            b[counter]=z[n-r];
        else if(r==2)
            b[counter]=z[n-r];
        else if(r==3)
            b[counter]=z[n-r+1];
        else if(r==4)
            b[counter]=z[n-r+1];
        cout<<"b[counter] after is "<<b[counter]<<endl;
    }

    //int x=select(b,0,2,2,3);
    cout<<"size is : "<<size<<endl;
    int x=select(b , 0 , size-1 , ceil((float)size/2) , size );
    cout<<"x is : "<<x<<endl;
    cout<<"beg before partit is : "<<beg<<endl;
    cout<<"end before partit is : "<<end<<endl;
    int k=partit(a , beg , end , x);
    cout<<"k is : "<<k<<endl;
    int y;


    if(kth==k+1)
    {
        return (x);
    }

    else if(kth<k+1)
    {
        y=select(a , beg , k-1 , kth , k-beg);
        cout<<"y in kth<k : "<<y<<endl;
    }

    else
    {
        cout<<"k+1 inside else is "<<k+1<<endl;
        cout<<"end is : "<<end<<endl;
        cout<<"kth - k-1 is : "<<kth-k-1<<endl;
        cout<<"array in else "<<endl;
        for(int i=0 ; i<end+1 ; ++i)
        {
            cout<<a[i]<<" ";
        }
        y=select(a , k+1 , end , kth-k-1 , end-k);
        cout<<"y in kth>k : "<<y<<endl;
    }
    return (y);
    /*for(int i=0 ; i<(int)ceil((float)n/5) ; ++i)
    {
        cout<<b[i]<<" ";
    }*/

    
}

int Find::partit(int a[],int beg, int end,int pivot)
{
    int index;
    for(int f=beg ; f<=end ; ++f)
    {
        if(a[f]==pivot)
        {
            index=f;
            break;
        }
    }
    int k=index;
    cout<<"index is : "<<k<<endl;
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
    cout<<"array inside partit : "<<endl;
    for(int y=beg ; y<=end ; ++y)
    {
        cout<<a[y]<<" ";
    }
    cout<<endl;
	return k;
}


int main()
{
    srand(time(NULL));
    F.read();
    F.print();
    int r=F.select(hits,0,SIZE-1,kth,SIZE);
    cout<<"returned value from select is : "<<r<<endl;
    //int index=F.partit(hits,0,12,45 );
    //cout<<"index inside main : "<<index<<endl;
    //cout<<"array length is "<<(int)sizeof(hits)/sizeof(*hits)<<endl;
    
    
}//end main function

void Find::read()
{
    /*for(int i=0 ; i<13 ; ++i)
    {
        //hits[i]=rand()%100+1;
        vec.push_back(hits[i]);
    }*/
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