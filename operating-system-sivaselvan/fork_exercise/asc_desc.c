#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
int sort(int a[],int size,int mode){
    for(int i=1 ; i<size ; ++i){
        for(int j=i ; j>0 ; --j){
            if(mode==1){
                if(a[j]<a[j-1]){
                    int temp=a[j];
                    a[j]=a[j-1];
                    a[j-1]=temp;
                }
            }
            else if(mode==0){
                if(a[j]>a[j-1]){
                    int temp=a[j];
                    a[j]=a[j-1];
                    a[j-1]=temp;
                }
            }
            
        }
    }
}
int main(){
    int size;
    printf("enter the size of array : ");
    scanf("%d",&size);
    int a[size];
    printf("enter the elements of array\n");
    for(int i=0 ; i<size ; ++i){
        scanf("%d",&a[i]);
    }

    pid_t pid;
    pid=fork();
    if(pid==0){
        printf("Inside child\n");
        sort(a,size,0);
        for(int i=0 ; i<size ; ++i){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    else if(pid>0){
        printf("Inside parent\n");
        sort(a,size,1);
        for(int i=0 ; i<size ; ++i){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    
    return 0;
}