// how to run
// mpicc 1.c -o 1
// mpiexec \-n 140 ./1
#include<stdio.h>
#include<mpi.h>
#define MASTER 0
int main(int argc, char **argv){

	MPI_Init(NULL, NULL);
	int total_procs,rank;
	MPI_Comm_size(MPI_COMM_WORLD, &total_procs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	int namelen;
	MPI_Get_processor_name(processor_name, &namelen);
	double start = MPI_Wtime();
	printf("Hello world from processor %s, rank (Process ID) %d out of %d processors\n", processor_name, rank, total_procs);
	double end = MPI_Wtime();

	if(rank == MASTER){
		printf("%lf\n",end-start);
	}
	MPI_Finalize();
	return 0;
}
