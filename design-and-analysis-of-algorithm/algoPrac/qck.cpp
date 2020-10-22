#include<bits/stdc++.h>
using namespace std;
int quicksort(int ,int);
int part(int,int);
int a[]={8,2,5,1,6,4};
int main()
{
    quicksort(0,5);
    for(int i=0 ; i<6 ; ++i)
    {
        cout<<a[i]<<" ";
    }
}

int quicksort(int beg,int end)
{
    if(beg<end)
    {
        int p=part(beg,end);
        quicksort(beg,p-1);
        quicksort(p+1,end);
    }
}

int part(int beg,int end)
{
    int i=beg;
    int j=end;
    int pivot=a[beg];
    while(i<j)
    {
        while(a[i]<=pivot && i<=end)
        {
            ++i;
        }
        while(a[j]>pivot && j>beg)
        {
            --j;
        }
        if(i<j)
        {
            swap(a[i],a[j]);
        }
    }
    swap(a[beg],a[j]);
    return (j);
}
