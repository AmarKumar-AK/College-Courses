#include<iostream>
#include<stdlib.h>
int counter=0;
using namespace std;

class Search 

{
	private:
	int array[100];
	public:
	void filler();
	void sort();
	int binsearch(int x);
	int linsearch(int x);
	void printer();
};

void Search :: filler()
{
int i;
for(i=0;i<=99;i++)
	{
		array[i]=rand()%1001;
	}
}
void Search :: printer()
{
int i;
for(i=0;i<=99;i++)
	{
	 cout<<array[i]<<" ";	
	}

}

int Search::linsearch(int x)
{
counter=0;
int i;
for(i=0;i<=99;i++)
	{
	 if(array[i]==x){counter=0;break;}
	 else{counter++;}
	}
return counter;
}
void Search::sort()
{
int i,j;
for(i=0;i<99;i++)
	{
	 bool swap = false;
	 for(j=0;j<99-i;j++)
		{
		 if(array[j]>array[j+1])
			{
			 swap=true;
			 int z;
			 z=array[j];
			 array[j]=array[j+1];
			 array[j+1]=z;
		        }
                }
	}
				
}
int Search::binsearch(int x)
{
counter=0;
int beg= 0;
int mid;
int end =99;
int flag=0;
while(beg<=end)
	{counter++;
	 mid=(beg+end)/2;
	 if(x==array[mid])
	 {
	  flag=1;
	  break;
         } 
	 else if(x<array[mid])
	   {
	    end = mid-1;
           }
        else
           {
           beg=mid+1;
	   }

	}
return counter;
}

int main()
{
srand(time(NULL));
float binavg=0,linavg=0;
int h=0;
for(h=0;h<1000;h++)
	{	
	 Search o1;
	 o1.filler();
	 linavg=linavg+o1.linsearch(rand()%1001);
         o1.sort();
         binavg=binavg+o1.binsearch(rand()%1001);
		
	}
cout<<"linear avg comp "<<linavg/1000<<" binavg "<<binavg/1000;


return 0;
}

