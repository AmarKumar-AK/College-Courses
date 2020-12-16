#include<bits/stdc++.h>
using namespace std;
const long long m = 100,n=100;

long double gen_rand(){
    long double x = rand() % 1000000;
    x = x + x*1.5235449874618; 
    return x; 
}

int main(){

    long double a[m][n],b[m][n];	

    for(long long row=0 ; row<m ; ++row ){
        for(long long col=0 ; col<n ; ++col){
            a[row][col] = gen_rand();
            b[row][col] = gen_rand();
        } 
    }
    for(long long row=0 ; row<m ; ++row ){
        for(long long col=0 ; col<n ; ++col){
            cout<<a[row][col]<<" ";
        }
        cout<<endl; 
    }
    for(long long row=0 ; row<m ; ++row ){
        for(long long col=0 ; col<n ; ++col){
            cout<<b[row][col]<<" ";
        }
        cout<<endl; 
    }
}