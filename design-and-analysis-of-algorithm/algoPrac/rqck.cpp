#include<bits/stdc++.h>
using namespace std;
int rsort(int,int);
int part(int,int);
int random(int ,int);
int a[]={8,2,10,6,1,5};
int main()
{
    rsort(0,5);
    for(int i=0 ; i<6 ; ++i)
    {
        cout<<a[i]<<" ";
    }
}

int random(int beg,int end)
{
    return (rand()%(end-beg+1)+beg);
}

int rsort(int beg,int end)
{
    if(beg<end)
    {
        int p=part(beg,end);
        rsort(beg,p-1);
        rsort(p+1,end);
    }
}

int part(int beg,int end)
{
    int i=beg;
    int j=end;
    int k=random(beg,end);
    int pivot=a[k];

    while(a[i]<=a[k] && i<=end)
    {
        if(i==k)
            break;
        ++i;
    }
    while(a[j]>a[k] && j>beg)
    {
        if(j==k)
            break;
        --j;
    }
    if(i<k && j>k)
    {
        swap(a[i],a[j]);
    }
    else
    {
        if(i==k && j!=k)
        {
            swap(a[i],a[j]);
            k=j;
        }
        else if(j==k && i!=k)
        {
            swap(a[i],a[j]);
            k=i;
        }
    }
    return (k);
}
