#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll foo(int x, ll n, ll m) {
    if (n == 0){
        return 1%m;
    } 
    long long u = foo(x,n/2,m);
    u = ((u%m)*(u%m))%m;
    if (n&1){
        u = ((u%m)*(x%m))%m;
    } 
    return u;
}
int main(){
    ll n,m;
    cin>>n>>m;
    cout<<foo(2,n-1,m);
}