#include<bits/stdc++.h>
using namespace std;

// Function to check if x is power of 2 
bool isPowerOfTwo(int n) 
{ 
   if(n==0) 
   return false; 
  
   return (ceil(log2(n)) == floor(log2(n))); 
}

void bin(int red,unsigned n,vector<int>a[]) 
{ 
    unsigned i;
    int x=0;
    for (i = 1 << red; i > 0; i = i / 2){
        if(n & i){
            a[x++].push_back(1);
        }
        else{
            a[x++].push_back(0);
        }
    }  
} 


int main(){
    string s;
    
    cout<<"enter the data : ";
    cin>>s;

    // calculating number of redundant bit
    int redundant=0;
    while(log2(s.size()+redundant)>=redundant)
    {
        redundant++;
    }    
    ///////////////////////////////////////
    int totalnumber=pow(2,redundant);
    vector<int>v(totalnumber);
    v.clear();
    // data with redundant bit 0
    int pos=s.size()-1;
    for(int i=1 ; i<=s.size()+redundant ; ++i){
        if(isPowerOfTwo(i)){
            v.push_back(0);
        }
        else{
            v.push_back((int)(s[pos]-'0'));
            pos--;
        }
    }

    ////////////////////////////////////////
    vector<int>a[redundant];
    for(int i=0 ; i<totalnumber ; ++i){
        bin(redundant-1,i,a);
    }

    // ///////////////////////////////////////
    vector<int>vv[totalnumber/2];
    for(int i=redundant-1 ; i>=0 ; --i){
        for(int j=0 ; j<totalnumber ; ++j){
            // cout<<a[i][j];
            if(a[i][j]==1){
                vv[redundant-i-1].push_back(j);
            }
        }
        // cout<<endl;
    }
    int k=0;
    for(int x=1 ; x<totalnumber ; x=x*2){
        for(int j=0 ; j<totalnumber/2 ; ++j){
            v[x-1]=v[x-1]^v[vv[k][j]-1];
        }
        k++;
        cout<<v[x-1]<<endl;
    }
    for(auto &x:v){
        cout<<x;
    }
    
}