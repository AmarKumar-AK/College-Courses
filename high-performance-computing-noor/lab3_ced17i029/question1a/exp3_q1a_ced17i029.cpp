#include<omp.h>
#include<bits/stdc++.h>
using namespace std; 
using namespace std::chrono; 
const long long int n=10000000;
int addition(vector<long double>a){
    long long i;
    long double asum=0;
    #pragma omp parallel for shared(a) private(i) reduction(+:asum)
    for(i=0 ; i<n ; ++i){
        asum = asum + a[i];
    }
    // cout<<"asum : "<<asum<<endl;
    return 0;
}


int main() 
{ 

	vector<long double> a(n); 
	
    for(long long i = 0 ; i<n ; ++i){
        cin>>a[i];
    }

	// start time
	auto start = high_resolution_clock::now(); 

    addition(a);

	// end time
	auto stop = high_resolution_clock::now();
	auto total_time = duration_cast<microseconds>(stop - start); 
	cout <<total_time.count()<< endl; 

	return 0; 
} 