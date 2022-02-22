#include<mpi.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MASTER 0

#define TRIALS 20
#define ARRAY_SIZE 12000000

int main(int argc, char *argv[]){
    int rank,total_proc;
    double start,end;
    int namelen;
    // long double * numbers = new long double[ARRAY_SIZE];
    long double *numbers = (long double *) malloc(sizeof(long double)*ARRAY_SIZE);
    long long i,j;
    long double sum,psum;
    long long s, s0, si,ei;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&total_proc);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Get_processor_name(processor_name,&namelen);

    for(i=0 ; i<ARRAY_SIZE ; i++){
        numbers[i] = rand()%10000000 + (1.0/(rand()%100000));
    }

    if(rank == MASTER){
        s=(int)floor(ARRAY_SIZE/total_proc);
        s0 = s + ARRAY_SIZE%total_proc;
    }

    MPI_Bcast(&s, 1, MPI_LONG_LONG_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&s0, 1, MPI_LONG_LONG_INT, 0, MPI_COMM_WORLD);

    si = s0 + (rank-1)%s;
    ei = si + s;
	if(rank == MASTER) start = MPI_Wtime();
    if(rank==MASTER){
        for(i=0 ; i<s0 ; i++){
            psum +=numbers[i];
        }
    }
    else{
        for(i=si ; i<ei ; i++){
            psum +=numbers[i];
        }
    }

    MPI_Reduce(&psum,&sum,1,MPI_LONG_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
	if(rank == MASTER){
		end = MPI_Wtime();
		printf("execution time = %lf\n",end-start);
	}
    MPI_Finalize();
}
