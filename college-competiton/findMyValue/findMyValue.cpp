#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll calculate(int x, int n){
    int m=1000000007;
    if(n==0){
        return 1%m;
    }
    ll u = calculate(x,n/2);
    u = ((u%m)*(u%m))%m;
    if(n&1){
        u = ((u%m)*(x%m))%m;
    }
    return u;
}
int main(){
    int a,r,n;
    int m=1000000007;
    cin>>a>>r>>n;
    ll aval = calculate(a,n);
    for(int i=1 ; i<n ; ++i){
        aval = ((aval%m) * (calculate(r,i)%m))%m;
    }
    cout<<aval<<"\n";
}