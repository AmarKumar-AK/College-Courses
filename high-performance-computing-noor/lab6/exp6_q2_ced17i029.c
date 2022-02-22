#include <mpi.h>
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#define MASTER 0
#define SIZE 12000000

int main(int argc, char **argv)
{
    long double * a;
	long double * b; 
	long double * c;
	int total_proc;	
	int rank;
	long long int n_per_proc,i,x,high,low;	
    long double dotproduct = 0,result;

    MPI_Init (&argc, &argv);
	MPI_Comm_size (MPI_COMM_WORLD, &total_proc);
	MPI_Comm_rank (MPI_COMM_WORLD,&rank);
    double start = MPI_Wtime();
    a = (long double *) malloc(sizeof(long double)*SIZE);
    b = (long double *) malloc(sizeof(long double)*SIZE);
    if(rank == MASTER) {
       
        for(i=0;i<SIZE;i++){
            a[i] = rand()%10000000 + 1.0/(rand()%100000);
            b[i] = rand()%10000000 + 1.0/(rand()%100000);
        }
    }
    MPI_Bcast(a, SIZE, MPI_LONG_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(b, SIZE, MPI_LONG_DOUBLE, 0, MPI_COMM_WORLD);
    n_per_proc = SIZE/total_proc;
    low = rank * n_per_proc;
    high = low + n_per_proc;
    for(i=low; i<high; i++) {
        dotproduct += a[i]*b[i];
    }
    MPI_Reduce(&dotproduct, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank == MASTER) {

        double end = MPI_Wtime();
        printf("execution time = %lf\n",end - start);
        // printf("%d\n",result );
    }

    MPI_Finalize();
}
