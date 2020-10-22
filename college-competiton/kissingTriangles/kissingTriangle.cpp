#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int main(){
    int n;
    cin>>n;
        for(int i=1 ; i<=n/2 ; ++i){
        cout<<string(i,'*')<<string(n+1-(2*i),' ')<<string(i,'*')<<"\n";
        }

        if((n&1)!=0){
            cout<<string((n/2)+1,'*')<<string((n/2)+1,'*')<<"\n";
        }
        else{
            cout<<string(n/2,' ')<<string(1,'*')<<string(n/2,' ')<<"\n";
        }
        
        for(int i=n/2 ; i>0 ; --i){
            cout<<string(i,'*')<<string(n+1-(2*i),' ')<<string(i,'*')<<"\n";
        }
    return 0;
}