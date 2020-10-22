#include<bits/stdc++.h>
#define ARRAYSIZE 13
using namespace std;

class Find
{
    public:
        void read();
        void print();
        int select(int*, int, int, int, int);
        int partit(int, int, int);
}F;

int kth;
vector<int> vec;

int a[]={25,57,20,85,63,         45,72,5,32,16,         98,4,9};
//int a[]={5,8,4,6,2};
//kth is starting from 0
int Find::select(int a[], int beg, int end, int kth, int n)
{
    //cout<<"n is : "<<n<<endl;
    int z[n];
    int t=beg;
    for(int i=0 ; i<n ; ++i)
    {
        z[i]=a[t++];
        //cout<<"z[i] is : "<<z[i]<<endl;
        //printf("z[%d] is : %d \n",i,z[i]);
    }
    
    if(n<=5)
    {
        //int b[n];
        sort(z,z+n);
        /*for(int i=0 ; i<n ; ++i)
        {
            b[i]=z[i];
            //cout<<"b[i] is : "<<b[i]<<endl ;
            printf("b[%d] is : %d \n",i,b[i]);
        }
        cout<<"kth inside n<=5 : "<<kth<<endl;*/
        return z[kth];
    }
    
    int r=n%5;
    //cout<<"r is "<<r<<endl;
    //cout<<"n is "<<n<<endl;
    int size=ceil((float)n/5);
    int b[size];
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
        if(r==1 || r==2)
            b[counter]=z[n-r];
        else if(r==3 || r==4) 
            b[counter]=z[n-r+1];
        cout<<"b[counter] after is "<<b[counter]<<endl;
    }

    //int x=select(b,0,2,2,3);
    //cout<<"size is : "<<size<<endl;
    int x=select(b , 0 , size-1 , (size-1)/2 , size );
    //cout<<"x is : "<<x<<endl;
    //cout<<"beg before partit is : "<<beg<<endl;
    //cout<<"end before partit is : "<<end<<endl;
    int index;
    for(int i=0 ; i<ARRAYSIZE ; ++i)
    {
        if(a[i]==x)
        {
            index=i;
            break;
        }
    }
    //cout<<"index before partit is : "<<index<<endl;
    //cout<<"array before partit is : "<<endl;
    /*for(int i=beg ; i<=end ; ++i)
    {
        cout<<a[i]<<" ";
    }*/
    int k=partit(beg , end , index);
    
    for(int i=0 ; i<ARRAYSIZE ; ++i)
    {
        if(a[i]==x)
        {
            index=i;
            break;
        }
    }
    /*cout<<"array after partit is : "<<endl;
    for(int i=0 ; i<ARRAYSIZE ; ++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;*/
    //cout<<"k is : "<<k<<endl;
    //cout<<"beg after partit is : "<<beg<<endl;
    //cout<<"end after partit is : "<<end<<endl;
    //cout<<"kth after partit is : "<<kth<<endl;
    int y;

    //cout<<"index is : "<<index<<endl;
    if(kth+beg==k)
    {
        return a[k];
    }

    else if(kth+beg<k)
    {
        y=select(a , beg , k-1 , kth , k-beg);
        //cout<<"y in kth<k : "<<y<<endl;
    }

    else if(kth+beg>k)
    {
        //cout<<"k+1 inside else is "<<k+1<<endl;
        //cout<<"end is : "<<end<<endl;
        //cout<<"kth - k-1 is : "<<kth+beg-k-1<<endl;
        //cout<<"array in else "<<endl;
        /*for(int i=0 ; i<end+1 ; ++i)
        {
            cout<<a[i]<<" ";
        }*/
        y=select(a , index+1 , end , kth+beg-k-1 , end-k);
        //cout<<"y in kth>k : "<<y<<endl;
    }
    return (y);
    /*for(int i=0 ; i<(int)ceil((float)n/5) ; ++i)
    {
        cout<<b[i]<<" ";
    }*/

    
}

int Find::partit(int beg, int end,int k)
{
	int i = beg;
	int j = end;
	while (i < j)
	{
		while (a[i] <= a[k])
		{
			
			if (i == k)
				break;
			i++;
		}
		while (a[j] > a[k])
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
    /*cout<<"array inside partit : "<<endl;
    for(int y=beg ; y<=end ; ++y)
    {
        cout<<a[y]<<" ";
    }
    cout<<endl;*/
    
   

	return k;
}


int main()
{
    srand(time(NULL));
    F.read();
    F.print();
    int r=F.select(a,0,ARRAYSIZE-1,kth,ARRAYSIZE);
    sort(a,a+ARRAYSIZE);
    F.print();
    cout<<"kth min is : "<<r<<endl;

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
    for(int i=0 ; i<ARRAYSIZE ; ++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    /*for(it=vec.begin() ; it<vec.end() ; ++it)
    {
        cout<<*it<<" ";
    }*/
}
