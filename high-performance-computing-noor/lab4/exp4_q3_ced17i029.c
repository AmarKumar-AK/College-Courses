#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define MASTER 0

int main (int argc, char *argv[]) 
{
	long double * a;
	long double * b; 
	long double * c;
	int total_proc;	
	int rank;
	long long int n_per_proc;	

	long long int i, n;
	MPI_Status status;

	MPI_Init (&argc, &argv);
	MPI_Comm_size (MPI_COMM_WORLD, &total_proc);
	MPI_Comm_rank (MPI_COMM_WORLD,&rank);
    long double * ap;
	long double * bp;
	long double * cp;	
	if (rank == MASTER)
	{
        	//printf("enter n : ");
        	//scanf ("%lld", &n);
        	n = 12000000L;
			a = (long double *) malloc(sizeof(long double)*n);
			b = (long double *) malloc(sizeof(long double)*n);
			c = (long double *) malloc(sizeof(long double)*n);
            		MPI_Bcast (&n, 1, MPI_LONG_LONG_INT, MASTER, MPI_COMM_WORLD);
            		n_per_proc = n/total_proc;
			for(i=0;i<n;i++)
				a[i] = rand()%10000000 + 1.0/(rand()%100000);
			for(i=0;i<n;i++)
				b[i] = rand()%10000000 + 1.0/(rand()%100000);
			if(n%total_proc != 0)
			{
			    	n_per_proc+=1;
			    	for(i=0;i<(n_per_proc*total_proc - n);i++)
			    	{
			    		a[n+i] = 0;
			    		b[n+i] = 0;
			    	}
			}
			double start_time = MPI_Wtime();
			ap = (long double *) malloc(sizeof(long double)*n_per_proc);
			bp = (long double *) malloc(sizeof(long double)*n_per_proc);
			cp = (long double *) malloc(sizeof(long double)*n_per_proc);
			MPI_Bcast (&n_per_proc, 1, MPI_LONG_LONG_INT, MASTER, MPI_COMM_WORLD);
			MPI_Scatter(a, n_per_proc, MPI_LONG_DOUBLE, ap, n_per_proc, MPI_LONG_DOUBLE, 0, MPI_COMM_WORLD); 
			MPI_Scatter(b, n_per_proc, MPI_LONG_DOUBLE, bp, n_per_proc, MPI_LONG_DOUBLE, 0, MPI_COMM_WORLD); 
			for(i=0;i<n_per_proc;i++)
				cp[i] = ap[i]*bp[i];
			MPI_Gather(cp, n_per_proc, MPI_LONG_DOUBLE, c, n_per_proc, MPI_LONG_DOUBLE, MASTER, MPI_COMM_WORLD);
			double end_time = MPI_Wtime();

			printf("%g\n",end_time-start_time);
			//for(i=0;i<n;i++)
			//	printf ("%Lf ", c[i]);	
			//printf ("\n");	
   	} 
	else 
	{
			MPI_Bcast (&n, 1, MPI_LONG_LONG_INT, MASTER, MPI_COMM_WORLD);
			MPI_Bcast (&n_per_proc, 1, MPI_LONG_LONG_INT, MASTER, MPI_COMM_WORLD);
			ap = (long double *) malloc(sizeof(long double)*n_per_proc);
			bp = (long double *) malloc(sizeof(long double)*n_per_proc);
			cp = (long double *) malloc(sizeof(long double)*n_per_proc);
			MPI_Scatter(a, n_per_proc, MPI_LONG_DOUBLE, ap, n_per_proc, MPI_LONG_DOUBLE, 0, MPI_COMM_WORLD);
			MPI_Scatter(b, n_per_proc, MPI_LONG_DOUBLE, bp, n_per_proc, MPI_LONG_DOUBLE, 0, MPI_COMM_WORLD);
			for(i=0;i<n_per_proc;i++)
			{
				cp[i] = ap[i]*bp[i];		
//				printf("a = %Lf     b = %Lf     c = %Lf        from rank = %d\n",ap[i],bp[i],cp[i],rank);
			}
			MPI_Gather(cp, n_per_proc, MPI_LONG_DOUBLE, c, n_per_proc, MPI_LONG_DOUBLE, MASTER, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}
