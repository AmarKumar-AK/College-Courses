#include<bits/stdc++.h>
using namespace std;
int main(){
    multiset<string>ms;
    set<string>s;
    int n;
    cin>>n;
    string str;
    while(n--){
        cin>>str;
        ms.insert(str);
        s.insert(str);
    }
    for(auto i=s.begin() ; i!=s.end() ; ++i){
        cout<<*i<<" "<<count(ms.begin(),ms.end(),*i)<<endl;
    }
    return 0;
}