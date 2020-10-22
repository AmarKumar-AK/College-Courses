#include<bits/stdc++.h>
using namespace std;
int divn(int ,int);
int main()
{
    int m=divn(0,5);
    cout<<"max sum is : "<<m<<endl;
}
int a[]={10,-8,3,2,-1,6};
int divn(int beg,int end)
{
    if(beg==end)
    {
        if(a[beg]<0)
            return (0);
        else
            return a[beg];
    }
    int mid=(beg+end)/2;
    int LS=divn(beg,mid);
    int RS=divn(mid+1,end);
    int losum=0;
    int lsum=0;
    for(int i=mid ; i>=beg ; --i)
    {
        lsum=lsum+a[i];
        if(lsum>losum)
            losum=lsum;
    }
    int rosum=0;
    int rsum=0;
    for(int i=mid+1 ; i<=end ; ++i)
    {
        rsum=rsum+a[i];
        if(rsum>rosum)
            rosum=rsum;
    }
    int max=losum+rosum;
    if(LS>max)
        max=LS;
    if(RS>max)
        max=RS;
    return (max);
}