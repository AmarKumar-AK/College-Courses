#include<omp.h>
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char argv[]){
    int omp_rank, omp_threads;

    #pragma omp parallel private(omp_rank)
    {   
        // gives thread number by which the statement is executed
        omp_rank = omp_get_thread_num();
        // gives total number of threads
        omp_threads = omp_get_num_threads();

        printf("Hello world by thread number %d of threads %d\n",omp_rank,omp_threads);
    }
    return 0;
}
