#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int n,m,data;
    cin>>n>>m;
    set<int>s;
    for(int i=0 ; i<n ; ++i){
        cin>>data;
        s.insert(data);
    }
    for(int i=0 ; i<m ; ++i){
        cin>>data;
        if(binary_search(s.begin(),s.end(),data)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}