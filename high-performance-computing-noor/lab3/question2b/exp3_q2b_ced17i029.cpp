#include<omp.h>
#include<bits/stdc++.h>
using namespace std; 
using namespace std::chrono; 
const long long int n=10000000;
int addition(vector<long double>a,vector<long double>b){
    long long i;
    long double asum=0;
    long double psum=0;
    #pragma omp parallel for shared(a,asum) private(i,psum)
    for(i=0 ; i<n ; ++i){
        psum = psum + a[i]*b[i];
    }
    #pragma omp critical
    asum = asum + psum;

    
    // cout<<"asum : "<<asum<<endl;
    return 0;
}


int main() 
{ 

	vector<long double> a(n),b(n); 
	
    for(long long i = 0 ; i<n ; ++i){
        cin>>a[i];
        cin>>b[i];
    }

	// start time
	auto start = high_resolution_clock::now(); 

    addition(a,b);

	// end time
	auto stop = high_resolution_clock::now();
	auto total_time = duration_cast<microseconds>(stop - start); 
	cout <<total_time.count()<< endl; 

	return 0; 
} 