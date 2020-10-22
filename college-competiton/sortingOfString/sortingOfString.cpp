#include<bits/stdc++.h>
using namespace std;
struct node{
    string s;
    int size;
};
int main(){
    int n;
    cin>>n;
    struct node nd[n];
    for(int i=0 ; i<n ; ++i){
        cin>>nd[i].s;
        nd[i].size=nd[i].s.size();
    }
    for(int i=1 ; i<n ; ++i){
        for(int j=i ; j>0 ; --j){
            if(nd[j].size>nd[j-1].size){
                swap(nd[j].s,nd[j-1].s);
                swap(nd[j].size,nd[j-1].size);
            }
            else if(nd[j].size==nd[j-1].size){
                if(nd[j].s<nd[j-1].s){
                    swap(nd[j].s,nd[j-1].s);
                    // swap(nd[j].size,nd[j-1].size);
                }
            }
        }
    }
    for(int i=0 ; i<n ; ++i){
        cout<<nd[i].s<<" ";
    }
    cout<<"\n";
    return 0;
}