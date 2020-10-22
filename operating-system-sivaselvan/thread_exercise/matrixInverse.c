#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include <sys/types.h>
#include <unistd.h>

int n;
float m[100][100],p[100][100],q[100][100];
struct ind{
    int x;
    int y;
};

float det(float f[100][100],int z){
    float Mi[100][100];
    int i,j,k,c1,c2;
    int determinant;
    float c[100];
    int O=1;
    determinant = 0;
    if(z==2){
        determinant = f[0][0]*f[1][1]-f[0][1]*f[1][0];
        return determinant;
    }
    else{
        for(i=0;i<z;i++){
            c1=0;
            c2=0;
            for(j=0;j<z;j++){
                for(k=0;k<z;k++){
                    if(j!=0 && k!=i){
                        Mi[c1][c2] = f[j][k];
                        c2++;
                        if(c2>z-2){
                            c1++;
                            c2=0;
                        }
                    }
                }
            }
            determinant = determinant + O*(f[0][i]*det(Mi,z-1));
            O=-1*O;
        }
    }
    return determinant;
}

void *cofac(void *arg){
    struct ind *t=arg;
    int k=0,l=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==t->x || j==t->y);
            else{
				p[k][l]=m[i][j];
				l++;
				if(l==n-1){
					k++; l=0;
				}
        	}
      	}
    }

    if(((t->x)+(t->y))%2==0)
      	q[t->x][t->y]=det(p,k);
    else
      	q[t->x][t->y]=(-1)*det(p,k);

}

void readMatrix(int order, float (*a)[order]){
    printf("enter %d X %d matrix\n",order,order);
    for(int i=0 ; i<order ; ++i){
        for(int j=0 ; j<order ; ++j){
            scanf("%f",&a[i][j]);
            m[i][j]=a[i][j];
        }
    }
}

void printMatrix(int order,float (*a)[order]){
    printf("\nmatrix is : \n");
    for(int i=0 ; i<order ; ++i){
        for(int j=0 ; j<order ; ++j){
            printf("%f ",a[i][j]);
        }
        printf("\n");
    }
}

int main(){
    printf("enter the order of matrix : ");
    scanf("%d",&n);
    float a[n][n];
    readMatrix(n,a);
    printMatrix(n,a);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            struct ind *data=(struct ind*)malloc(sizeof(struct ind));
            data->x=i;
            data->y=j;
            pthread_t tid;
            pthread_create(&tid,NULL,cofac,data);
            pthread_join(tid,NULL);
        }
    }
	float tmp;
	float de=det(m,n);
    if(de==0){
        printf("inverse is not possible\n");
        return 0;
    }
//taking transpose and dividing by determinant to find adjoint
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i<j){
				tmp=q[i][j];
				q[i][j]=q[j][i];
				q[j][i]=tmp;
			}
            q[i][j]=(1/de)*q[i][j];
		}
	}

    printf("Inverse of the matrix is - \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%f ",q[i][j]);
        }
        printf("\n");
    }
    return 0;
}
