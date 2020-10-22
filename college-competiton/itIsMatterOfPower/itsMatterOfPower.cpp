#include<bits/stdc++.h>
#define ull unsigned long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
ull calc(ull a,ull b){
    int mod=1000000007;
    if(b == 0){
        return 1%mod;
    }
    ull u=calc(a,b/2);
    u=((u%mod)*(u%mod))%mod;
    if(b&1){
        u=((u%mod)*(a%mod))%mod;
    }
    return u;
}
int main(){
    fast;
    ull a,b;
    cin>>a>>b;
    cout<<calc(a,b)<<"\n";
}