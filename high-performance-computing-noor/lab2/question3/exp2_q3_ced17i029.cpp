#include<omp.h>
#include<bits/stdc++.h>
using namespace std; 
using namespace std::chrono; 
const long long m = 500,l=500,n=500;


int matrix_mul(long long a[m][l],long long b[l][n]){
    long long c[m][n];
    long long row,col,dot;
    long long blockSize=5,blockRow,blockCol;
    #pragma omp parallel for shared (a,b,c) private(row,col) schedule(static)
    for(row = 0 ; row< m ; row+=blockSize){
        #pragma omp parallel for
        for(col=0 ; col< n ; col+=blockSize){
            #pragma omp parallel for
            for(blockRow=row ; blockRow<row+blockSize ; ++blockRow){
                #pragma omp parallel for
                for(blockCol=col ; blockCol<col+blockSize ; ++blockCol ){
                    #pragma omp parallel for
                    for(dot=0 ; dot<l ; ++dot){
                        c[blockRow][blockCol] = a[blockRow][dot] * b[dot][blockCol];
                    } 
                }
            }
              
        }
    }

    return 0;
}


int main() 
{ 

    
	long long a[m][l],b[l][n]; 
	// taking matrix input
    for(long long row = 0 ; row<m ; ++row){
        for(long long col = 0 ; col<l ; ++col){
            cin>>a[row][col];
        }
    }
    for(long long row = 0 ; row<l ; ++row){
        for(long long col = 0 ; col<n ; ++col){
            cin>>b[row][col];
        }
    }

	// start time
	auto start = high_resolution_clock::now(); 

    matrix_mul(a,b);

	// end time
	auto stop = high_resolution_clock::now();
	auto total_time = duration_cast<microseconds>(stop - start); 
	cout <<total_time.count()<< endl; 

	return 0; 
} 