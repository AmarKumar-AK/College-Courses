#include<bits/stdc++.h>
using namespace std;

class currency
{	
	public:
		void curr();				
}c;
int denomination[]={1,2,5,10,20,50,100,200,500,2000};
int a[]={0,0,0,0,0,0,0,0,0,0};
void currency::curr()
{
	int amount;
	cout<<"enter the total amount"<<endl;
	cin>>amount;
	int i=9;
	while(amount>0)
	{
		a[i]=amount/denomination[i];
		amount=amount%denomination[i--];
	}
	for(int i=0 ; i<10 ; ++i)
	{
		cout<<denomination[i]<<" = "<<a[i]<<endl;
	}
}

int main()
{
	c.curr();

}

