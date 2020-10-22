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
    cout<<endl;
    for(int i=0 ; i<20 ; ++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int number;
    cout<<"enter number to search"<<endl;
    cin>>number;
    int index=-1;
    for(int i=0 ; i<20 ; ++i)
    {
        if(a[i]==number)
        {
            index=i;
            break;
        }
    }
    if(index==-1)
        cout<<"not present"<<endl;
    else
        cout<<"present at "<<index+1<<"th position"<<endl;
}