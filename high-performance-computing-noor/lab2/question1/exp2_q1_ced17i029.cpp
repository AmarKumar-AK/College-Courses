#include<omp.h>
#include<bits/stdc++.h>
using namespace std; 
using namespace std::chrono; 
const long long m = 100,n=100;


int matrix_add(long double a[m][n],long double b[m][n]){
    long double c[m][n];
    long long row,col;
    
    #pragma omp parallel for shared (a,b,c) private(row,col) schedule(static)
    for(row = 0 ; row< m ; ++row){
        #pragma omp parallel for
        for(col=0 ; col< n ; ++col){
            c[row][col] = a[row][col] + b[row][col];
        }
    }

    return 0;
}


int main() 
{ 

    
	long double a[m][n],b[m][n]; 
	// taking matrix input
    for(long long row = 0 ; row<m ; ++row){
        for(long long col = 0 ; col<n ; ++col){
            cin>>a[row][col];
        }
    }
    for(long long row = 0 ; row<m ; ++row){
        for(long long col = 0 ; col<n ; ++col){
            // cin>>a[i][j];
            cin>>b[row][col];
        }
    }

	// start time
	auto start = high_resolution_clock::now(); 

    matrix_add(a,b);

	// end time
	auto stop = high_resolution_clock::now();
	auto total_time = duration_cast<microseconds>(stop - start); 
	cout <<total_time.count()<< endl; 

	return 0; 
} 