#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[20];
    srand(time(NULL));
    for(int i=0 ; i<20 ; ++i)
    {
        a[i]=rand()%50+1;
    }
    cout<<"unsorted"<<endl;
     for(int i=0 ; i<20 ; ++i)
    {
        cout<<a[i]<<" ";
    }
    for(int i=0 ; i<20 ; ++i)
    {
        int max=0;
        int index;
        max=*max_element(a,a+20-i);
        for(int j=0 ; j<20-i ; ++j)
        {
            if(a[j]==max)
            {
                index=j;
                break;
            }
        }
        swap(a[index],a[19-i]);  
    }
    cout<<endl<<"sorted"<<endl;
    for(int i=0 ; i<20 ; ++i)
    {
        cout<<a[i]<<" ";
    }
}