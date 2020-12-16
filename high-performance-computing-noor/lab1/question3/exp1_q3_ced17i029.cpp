#include<omp.h>
#include<bits/stdc++.h>
using namespace std; 
using namespace std::chrono; 

int vector_mul(vector<long double>a,vector<long double>b,long long n){
    vector<long double>c(n);
    long long i;
    
    #pragma omp parallel for shared (a,b,c,n) private(i) schedule(static)
    for (i = 0; i < n; ++i)
    {
        c[i] = a[i] * b[i];
        // printf("%Lf  %Lf  %Lf\n",a[i],b[i],c[i]);
    }
    return 0;
}


int main() 
{ 

    long long n = 4000000;
	vector<long double> a(n),b(n); 
	
    for(long long i = 0 ; i<n ; ++i){
        cin>>a[i];
        cin>>b[i];
    }

	// start time
	auto start = high_resolution_clock::now(); 

    vector_mul(a,b,n);

	// end time
	auto stop = high_resolution_clock::now();
	auto total_time = duration_cast<microseconds>(stop - start); 
	cout <<total_time.count()<< endl; 

	return 0; 
} 