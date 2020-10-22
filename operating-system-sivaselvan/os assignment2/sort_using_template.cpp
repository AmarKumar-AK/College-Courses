#include<bits/stdc++.h>
using namespace std;

template<typename T>
void srt(T a[],T b[]){
  int n=(b-a);
  for(int i=1 ; i<n ; ++i){
    for(int j=i ; j>0 ; --j){
      if(a[j]<a[j-1]){
        swap(a[j],a[j-1]);
      }
    }
  }
}

int main(){
    int a[]={6, 3, 9, 1, 7};
    int asize=sizeof(a)/sizeof(a[0]);
    char b[]={'n', 'c', 'p', 'a', 't'};
    int bsize=sizeof(b)/sizeof(b[0]);
    float c[]={1.32, 3.71, 0.67, 5.43, 2.91};
    int csize=sizeof(c)/sizeof(c[0]);

    srt(a,a+asize);
    for(int i=0 ; i<asize ; ++i){
      cout<<a[i]<<" ";
    }
    cout<<endl;

    srt(b,b+bsize);
    for(int i=0 ; i<bsize ; ++i){
      cout<<b[i]<<" ";
    }
    cout<<endl;

    srt(c,c+csize);
    for(int i=0 ; i<csize ; ++i){
      cout<<c[i]<<" ";
    }
    cout<<endl;


    return 0;
}