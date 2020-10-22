#include<bits/stdc++.h>
using namespace std;

void mergesort(int,int);
void merge(int,int);
int a[]={8,2,5,7,1,6};
int main()
{
    mergesort(0,5);
    for(int i=0 ; i<6 ; ++i)
    {
        cout<<a[i]<<" ";
    }
}

void mergesort(int beg, int end)
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        mergesort(beg,mid);
        mergesort(mid+1,end);
        merge(beg,end);
    }
}

void merge(int beg, int end)
{
    int mid=(beg+end)/2;
    int i=beg;
    int j=mid+1;
    int b[6];
    int k=0;
    while(i<=mid && j<=end)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            ++i;
            ++k;
        }
        else
        {
            b[k]=a[j];
            ++j;
            ++k;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        ++i;
        ++k;
    }
    while(j<=end)
    {
        b[k]=a[j];
        ++j;
        ++k;
    }
    int p=0;
    for(int x=beg ; x<=end ; ++x)
    {
        a[x]=b[p];
        ++p;
    }
}