#include<bits/stdc++.h>
#define SIZE 5
using namespace std;

class knapsack
{
	struct knaps
	{
		int weight[SIZE];
		int price[SIZE];
	}ks;
	public:
		void knap1();

}kc;

void knapsack::knap1()
{
	int total;
	cout<<"enter total weight"<<endl;
	cin>>total;
	for(int i=0 ; i<SIZE ; ++i)
	{
		cout<<"enter weight and price respectively"<<endl;
		cin>>kc.ks.weight[i]>>kc.ks.price[i];
	}
	for(int i=0 ; i<SIZE ; ++i)
	{
		for(int j=1 ; j<SIZE-i ; ++j)
		{
			if(kc.ks.price[j]>kc.ks.price[j-1])
			{
				int temp1=kc.ks.price[j-1];
				kc.ks.price[j-1]=kc.ks.price[j];
				kc.ks.price[j]=temp1;
				int temp2=kc.ks.weight[j-1];
				kc.ks.weight[j-1]=kc.ks.weight[j];
				kc.ks.weight[j]=temp2;
				
			}
		} 
	}
	for(int i=0 ; i<SIZE ; ++i)
	{
		cout<<kc.ks.weight[i]<<" : "<<kc.ks.price[i]<<endl;
	}
	int i=0;
	int counter=0;
	//cout<<*(min_element(kc.ks.weight,kc.ks.weight+SIZE));
	while(total>=*(min_element(kc.ks.weight,kc.ks.weight+SIZE)))
	{
		int temp=total/kc.ks.weight[i];
		total=total%kc.ks.weight[i];
		//total=total-kc.ks.weight[i]*temp;
		counter=counter+kc.ks.price[i++]*temp;
	} 
	
	cout<<"maximum price is "<<counter<<endl;
	
}




int main()
{
	kc.knap1();

}
