// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;
// ll foo(int x, ll n) {
//     if (n == 0){
//         return 1;
//     } 
//     long long u = foo(x,n/2);
//     u = (u*u);
//     if (n&1){
//         u = (u*x);
//     } 
//     return u;
// }
// int main(){
//     ll n;
//     cin>>n;
//     cout<<foo(3,n);
// }
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    srand(time(NULL));
    for(int i=0 ; i<10 ; ++i)
    cout<<rand()%1000000000000000000<<" "<<rand()%1000000000<<endl;
}