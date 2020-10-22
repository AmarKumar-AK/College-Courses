#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    string s1,s2,res;
    int n1,n2;
    while(t--){
        cin>>s1>>s2;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),back_inserter(res));
    }
    cout<<"out"<<endl;
    cout<<s1.size()+s2.size()-2*res.size()<<endl;
    return 0;
}