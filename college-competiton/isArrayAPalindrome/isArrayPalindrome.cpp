#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="",temp;
    int n;
    cin>>n;
    int flag=0;
    for(int i=0 ; i<n ; ++i){
        cin>>temp;
        s += temp;
    }
    cout<<s<<"\n";
    for(int i=0 ; i<s.size()/2 ; ++i){
        if(s[i]!=s[s.size()-i-1]){
            flag=1;
            break;
        }
    }
    if(flag){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
    return 0;
}