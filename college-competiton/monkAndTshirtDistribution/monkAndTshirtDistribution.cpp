#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    int n,m,k;
    while(t--){
        cin>>n>>m>>k;
        ll ups = n-m*k+m-1;
        ll downs = m-1;
        ll upss=1;
        ll downss=1;
        for(int i=ups ; i>ups-downs ; --i){
            upss *= i;
        }
        for(int i=downs ; i>0 ; --i){
            downss *=i;
        }
        cout<<upss/downss<<"\n";
    }
}