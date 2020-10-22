#include<bits/stdc++.h>
using namespace std;   
int fm(int a[], int n) 
{ 
    sort(a, a+n);
    return a[n/2];
} 
int partition(int a[], int st, int end, int pivot) 
{ 
    int i,temp;  int p=st; 
    for (i=st; i<end; i++) 
    {
        if (a[i]==pivot) 
           break;    	
    }
    
    temp=a[i]; a[i]=a[end]; a[end]=temp;
    for (int j=st; j<=end-1; j++) 
    { 
        if (a[j]<=pivot) 
        { 
            temp=a[p]; a[p]=a[j]; a[j]=temp; p++; 
        } 
    } 
    temp=a[p]; a[p]=a[end]; a[end]=temp; 
    return p; 
} 
int median(int a[],int beg,int end)
{
	    int n = end-beg+1; 
        int i, med[(n+4)/5];                              // floor((n+4)/5) group
        for (i=0; i<n/5; i++) 
            med[i] = fm(a+beg+i*5, 5); 
        if (i*5 < n) 
        { 
            med[i] = fm(a+beg+i*5, n%5);  
            i++; 
        }     
  		if(i==1)
  		{
  			return med[i-1];
  		}
  		median(med,0,i-1);
  		
}
int select(int a[], int beg, int end, int k) 
{ 
		int fmed=median(a,beg,end);
        int s=partition(a,beg,end,fmed); 
  		int m=s-beg+1;
        if (m==k) 
            return a[s]; 
        else if (k<m)
            return select(a,beg,s-1, k); 
  		else
        	return select(a,s+1,end, k-m);  
}
 
int main() 
{ 
    int a[] = {12,3,6,67,78,23,9,4,29,56,789};  
    //cout<<median(a,0,10);
    cout<<select(a,0,10,11)<<endl; 
}
