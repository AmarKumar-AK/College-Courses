#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll comb(int n,int k){
    ll ups = n;
    ll downs = k;
    ll upss=1;
    ll downss=1;
    for(int i=ups ; i>ups-downs ; --i){
        upss *= i;
    }
    for(int i=downs ; i>0 ; --i){
        downss *=i;
    }
    ll answer=upss/downss;
    return answer;
}
int main(){
    int t;
    cin>>t;
    int n,y,k;
    int m=1000000007;
    while(t--){
        cin>>n>>y>>k;
        ll nk=pow(9,n-k);
        ll nk1=nk/9;
        ll answer = ((8*comb(n-1,k)*nk1)%m + (comb(n-1,k-1)*nk)%m)%m;
        cout<<answer<<"\n";       
    }
}