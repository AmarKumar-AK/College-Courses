#include<stdio.h>
#include<mpi.h>
#include<math.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

#define MASTER 0
#define N 10000

double a[N][N],b[N][N],c[N][N];

int main(int argc, char **argv){
        int rank,numproc;
        int rows,offset,leftover;
        int countid,originalrows;

        MPI_Init(&argc,&argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &numproc);

        MPI_Status status;
        int i,j,k;
        if(rank == MASTER){
                double t1,t2;
                rows = N/numproc;
                offset = rows;
                leftover = N % numproc;
                for(i=0 ; i<N ; ++i){
                        for(j=0 ; j<N ; ++j){
                                a[i][j] = rand()%1000000 + (1.0/(rand()%10000)) ; 
                                b[i][j] = rand()%1000000 + (1.0/(rand()%10000)) ; 
                                c[i][j] = 0;
                        }
                }
                /*for(i=0 ; i<N ; ++i){
                        for(j=0 ; j<N ; ++j){
                                cout<<a[i][j]<<" ";
                        }
                        cout<<endl;
                }
                cout<<endl;
                for(i=0 ; i<N ; ++i){
                        for(j=0 ; j<N ; ++j){
                                cout<<b[i][j]<<" ";
                        }
                        cout<<endl;
                }
                cout<<endl;*/
                t1 = MPI_Wtime();
                for(i=0 ; i<rows ; ++i){
                        for(j=0 ; j<N ; ++j){
                                c[i][j] = a[i][j] + b[i][j];
                        }
                }
                for(countid = 1 ; countid<numproc ; ++countid){
                        if(leftover>0){
                                originalrows = rows;
                                rows++;
                                leftover--;
                                MPI_Send(&offset, 1, MPI_INT, countid, 1, MPI_COMM_WORLD);
                                MPI_Send(&rows, 1, MPI_INT, countid, 2, MPI_COMM_WORLD);
                                MPI_Send(&a[offset][0], rows*N, MPI_DOUBLE, countid, 0, MPI_COMM_WORLD);
                                MPI_Send(&b[offset][0], rows*N, MPI_DOUBLE, countid, 0, MPI_COMM_WORLD);
                                offset = offset + rows;
                                rows = originalrows;
                        }
                        else{
                                MPI_Send(&offset, 1, MPI_INT, countid, 1, MPI_COMM_WORLD);
                                MPI_Send(&rows, 1, MPI_INT, countid, 2, MPI_COMM_WORLD);
                                MPI_Send(&a[offset][0], rows*N, MPI_DOUBLE, countid, 0, MPI_COMM_WORLD);
                                MPI_Send(&b[offset][0], rows*N, MPI_DOUBLE, countid, 0, MPI_COMM_WORLD);
                                offset = offset + rows;
                        }
                }
                for(i=1 ; i<numproc ; ++i){
                        MPI_Recv(&offset, 1, MPI_INT, i, 1, MPI_COMM_WORLD,&status);
                        MPI_Recv(&rows, 1, MPI_INT, i, 2, MPI_COMM_WORLD,&status);
                        MPI_Recv(&c[offset][0], rows*N, MPI_DOUBLE, i, 2,MPI_COMM_WORLD, &status);
                }
                t2 = MPI_Wtime();
                /*for(i=0 ; i<N ; ++i){
                        for(j=0 ; j<N ; ++j){
                                cout<<c[i][j]<<" ";
                        }
                        cout<<endl;
                }
                cout<<endl;     */
                printf("execution time : %lf\n",t2-t1);
        }//MASTER
        else{
                MPI_Recv(&offset, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
                MPI_Recv(&rows, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);
                MPI_Recv(&a, rows*N, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &status);
                MPI_Recv(&b, rows*N, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &status);
                for(i=0 ; i<rows ; ++i){
                        for(j=0 ; j<N ; ++j){
                                c[i][j] = a[i][j] + b[i][j];
                        }
                }
                MPI_Send(&offset, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
                MPI_Send(&rows, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
                MPI_Send(&c, rows*N, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD);
        }//WORKER
        MPI_Finalize();
}