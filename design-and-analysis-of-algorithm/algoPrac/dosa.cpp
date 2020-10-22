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
        int max=*max_element(radius,radius+SIZE-i);
        int imax=distance(radius,max_element(radius,radius+SIZE-i));
		if(imax==size-1)
		{
			size--;
			continue;
		}
        reverse(radius,radius+imax+1);
        reverse(radius,radius+5-i);
        size--;
	}
    for(int i=0 ; i<SIZE ; ++i)
		cout<<radius[i]<<" ";
	cout<<endl;
}
int main()
{
	d.flip();
}