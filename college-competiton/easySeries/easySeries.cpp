#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int F(int x) { 

  int f[x+2];
  int i; 

  ll a = 0; 
  ll b = 1; 
  ll c;
  int m=1000000007;
  ll answer=1;
  for (i = 2; i <= x; i++){ 
        c = a + b;
        a=b;
        b=c;
        answer = ((answer%m) * (c%m))%m;
  }   
  cout<<answer<<"\n";
}

int main(){
    int t,x;
    cin>>t;
    while(t--){
        cin>>x;
        F(x);
    }
    return 0;
}