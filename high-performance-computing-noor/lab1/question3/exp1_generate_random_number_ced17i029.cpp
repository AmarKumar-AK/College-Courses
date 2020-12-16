#include<bits/stdc++.h>
using namespace std;
int main(){

    long long n = 4000000;
    vector<long double> a(n),b(n); 
	// lambda function to generate random floating point numbers
	auto f = []() -> long double { long double x = rand() % 1000000; x = x + x*3.52354; return x; }; 
	// filling the vector with value generated by lambda function f
	generate(a.begin(), a.end(), f); 
    generate(b.begin(), b.end(), f);

    for(long long i=0 ; i<n ; ++i ){
        printf("%Lf\n%Lf\n",a[i],b[i]);
    }
}