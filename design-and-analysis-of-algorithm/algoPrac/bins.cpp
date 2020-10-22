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
    sort(a,a+20);
    cout<<endl;
    for(int i=0 ; i<20 ; ++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int number;
    cout<<"enter number to search"<<endl;
    cin>>number;
    int first=0,last=20;
    int flag=0;
    while(last>=first)
    {
        int mid=(first+last)/2;
        if(mid==number)
        {
            flag=1;
            break;
        }
        else if(mid>number)
        {
            last=mid-1;
        }
        else
        {
            first=mid+1;
        }
    }
    if(flag==1)
    {
        cout<<"number is present"<<endl;
    }
    else
    {
        cout<<"number is not present"<<endl;
    }
}