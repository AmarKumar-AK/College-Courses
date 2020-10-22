//implementing mergesort
//./a.out 3 7 2 6 1 9
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

struct node{
    int *a;
    int begs;
    int ends;
};

void *merge(void *param){
    struct node *nd=param;
    int beg=nd->begs;
    int end=nd->ends;
    int *a=nd->a;
    int mid=(beg+end)/2;
    int i=beg;
    int j=mid+1;
    int b[100];
    int k=0;
    while(i<=mid && j<=end){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
    while(j<=end){
        b[k++]=a[j++];
    }
    int p=0;
    for(int x=beg ; x<=end ; ++x){
        a[x]=b[p++];
    }
}

void *mergesort(void *param){
    struct node *nd=param;
    int beg=nd->begs;
    int end=nd->ends;
    int *a=nd->a;
    int mid;
    if(beg<end){
        mid=(beg+end)/2;

        struct node *nd1=malloc(sizeof(struct node));
        nd1->begs=beg,nd1->ends=mid,nd1->a=a;
        // mergesort(a,beg,mid);
        pthread_t tid1;
        pthread_create(&tid1,NULL,mergesort,nd1);

        struct node *nd2=malloc(sizeof(struct node));
        nd2->begs=mid+1,nd2->ends=end,nd2->a=a;
        // mergesort(a,mid+1,end);
        pthread_t tid2;
        pthread_create(&tid2,NULL,mergesort,nd2);

        
        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);
        // merge(nd->a,nd->begs,nd-end);
        pthread_t tid3;
        pthread_create(&tid3,NULL,merge,nd);
        pthread_join(tid3,NULL);
    }
}



int main(int argc,char *argv[]){
    int a[argc];
    for(int i=0 ; i<argc-1 ; ++i){
        a[i]=atoi(argv[i+1]);
    }
    
    struct node *nd=malloc(sizeof(struct node));
    nd->begs=0;
    nd->ends=argc-2;
    nd->a=a;
    // mergesort(a,0,argc-2);
    pthread_t tid;
    pthread_create(&tid,NULL,mergesort,nd);
    pthread_join(tid,NULL);
    for(int i=0 ; i<argc-1 ; ++i){
        printf("%d ",a[i]);
    }
    printf("\nreached end\n");
}