#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    ull t;
    cin>>t;
    while(t--){
        ull n;
        cin>>n;
        ull ones_count = 0;
        ull zeros_count = 0;
        while(n!=0){
            if(n&1){
                ones_count++;
                n/=2;
            } else {
                zeros_count++;
                n/=2;
            }
        }
        cout<<ones_count<<" "<<zeros_count<<"\n";
    }
    return 0;
}

