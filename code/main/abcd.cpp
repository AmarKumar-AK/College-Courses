/*#include<bits/stdc++.h>
using namespace std;
int main()
{
	long double a=1030;
	long double b=515;
	long double c=412;
	long double d=103;
	long double e=a*b*c*d;
	printf("%Lf",e);
}*/

/*
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    vector<int> list;
     vector<int>::iterator j;
      vector<int>::iterator k;
       vector<int>::iterator l;
        vector<int>::iterator m;    
    int t;
    //cout<<"enter the number of testcases"<<endl;
    cin>>t;
    int a[t]; long int i,p;  unsigned long long int max,x; 
    for(p=0 ; p<t ; p++)
    {
    //	cout<<"enter the number"<<endl;
        cin>>a[p]; 
   
        long int count=0;
        for(i=1 ; i<=a[p] ; i++)
        {
            if(a[p]%i==0)
            {
            	list.push_back(i);
            	printf("%ld ", i);
            }
        }//for ends
        cout<<endl;
       // printf("front is %d\n",list.front());
        //printf("back is %d\n",list.back());
       //printf("begin is %d\n",list.begin());
       //printf("end is %d\n",list.end());
       //for(j=list.begin() ; j<list.end() ; j++)
        //printf("%d ",*j);
        max=0;
        for(j=list.begin() ; j<list.end() ; j++)
        {
        		 for(k=list.begin() ; k<list.end() ; k++)
        		 {
					 for(l=list.begin() ; l<list.end() ; l++)
					 {
					 	 for(m=list.begin() ; m<list.end() ; m++)
					 	 {
					 	   ll b=*j; ll c=*k; ll d=*l ; ll e=*m;
					 	 	x=b*c*d*e;
					 	 	
					 	 	if(*j+*k+*l+*m==a[p] && x>max)
					 	 	{
					 	 		max=x;  printf("%d %d %d %d\n",*j,*k,*l,*m); count++;
					 	 	}//if ends
					 	 }//for ends
					 }//for ends        		 
        		 }//for ends
        }//for ends
        if(count!=0)
        {
        		printf("%llu",max);
        }else
        {
        	cout<<"-1";
        }
        list.clear();
      
    }//for ends
}//main ends*/
/*
#include<bits/stdc++.h>
using namespace std;


int main() {
 
        int i,n;
    scanf("%d",&n);
    double a[n];
    double sum=10;
        for(i=0 ; i<n ; i++)
        scanf("%lf",&a[i]);
    for(i=0 ; i<n ; i++)
    {
        sum=sum+a[i];
    }
    
    printf("%lf",sum);

}
*//*
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,s;
	cout<<"enter an integer:  ";
	cin>>n;
	vector<int> binary;
	while(n!=1)
	{
		binary.push_back(n%2);
		n=n/2;
	}
	cout<<"binary conversion is :  ";
	cout<<"1";
	for(auto i=binary.rbegin() ; i!=binary.rend() ; i++)
	cout<<*i;
}*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
   
    int i,k; int t,n; int count;
   // cout<<"enter number of testcases"<<endl;
    cin>>t;
    //int store[1000];
    for(i=0 ; i<t ; i++)
    {
    	//cout<<"enter an integer upto which you want the summation of prime number"<<endl;
        cin>>n; unsigned long long int sum=0,j;
        for(j=2; j<=n; j++ )
        {
        int count;
        		if((j%2==0 && j!=2) || (j%3==0 && j!=3) || (j%5==0 && j!=5) || (j%7==0 && j!=7) || (j%11==0 && j!=11))
        		{
        			continue;
        		}else
        		{
        			cout<<j<<" ";
        			count++;
        			sum=sum+j;
        		}
        }
        
        printf("%llu\n",sum);
    }//iterator for testcases
}//main ends
