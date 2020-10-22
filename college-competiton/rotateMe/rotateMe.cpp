#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ; i<n ; ++i){
        cin>>a[i];
    }
    sort(a,a+n,greater<int>());
    char lr;
    int x;
    cin>>lr>>x;
    if(lr=='L'){
        for(int i=x ; i<x+n ; ++i){
            cout<<a[i%n]<<" ";
        }
    }
    else{
        for(int i=n-x ; i<2*n-x ; ++i){
            cout<<a[i%n]<<" ";
        }
    }
    return 0;
}