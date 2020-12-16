#include<bits/stdc++.h>
using namespace std;
const long long m = 500,l=500,n=500;

long double gen_rand(){
    long double x = rand() % 1000000;
    x = x + x*1.5235449874618; 
    return x; 
}

int main(){

    long double a[m][l],b[l][n];	

    for(long long row=0 ; row<m ; ++row ){
        for(long long col=0 ; col<l ; ++col){
            a[row][col] = gen_rand();
        } 
    }
    for(long long row=0 ; row<l ; ++row ){
        for(long long col=0 ; col<n ; ++col){
            b[row][col] = gen_rand();
        } 
    }
    for(long long row=0 ; row<m ; ++row ){
        for(long long col=0 ; col<l ; ++col){
            cout<<a[row][col]<<" ";
        }
        cout<<endl; 
    }
    for(long long row=0 ; row<l ; ++row ){
        for(long long col=0 ; col<n ; ++col){
            cout<<b[row][col]<<" ";
        }
        cout<<endl; 
    }
}