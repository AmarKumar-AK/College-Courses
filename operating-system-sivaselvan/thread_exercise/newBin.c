//implementing binary search using multi threading
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
    int num;
    int beg;
    int end;
};

void *binarySearch(void *param){
    struct node *nd=param;
    int *a=nd->a;
    int beg=nd->beg;
    int end=nd->end;
    int x=nd->num;
    int mid=(beg+end)/2;
    if( x == a[mid]){
        printf("%d found\n",x);
        exit(0);
        // return 0;
    }
    else if(x < a[mid]){
        // binarySearch(a,x,beg,mid-1);
        struct node *nd1=malloc(sizeof(struct node));
        nd1->a=a,nd1->beg=beg,nd1->end=mid-1,nd1->num=x;
        pthread_t tid1;
        pthread_create(&tid1,NULL,binarySearch,nd1);
    }
    else if(x > a[mid]){
        // binarySearch(a,x,mid+1,end);
        struct node *nd2=malloc(sizeof(struct node));
        nd2->a=a,nd2->beg=mid+1,nd2->end=end,nd2->num=x;
        pthread_t tid2;
        pthread_create(&tid2,NULL,binarySearch,nd2);
    }
}

int main(int argc, char const *argv[]){
    int a[argc];
    for(int i=0 ; i<argc-1 ; ++i){
        a[i]=atoi(argv[i+1]);
    }
    //sorting
    for(int i=1 ; i<argc-1 ; ++i){
        for(int j=i ; j>0 ; --j){
            if(a[j]<a[j-1]){
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
    int num;
    printf("enter the number to search : ");
    scanf("%d",&num);
    int total=argc-1;
    total=total/4;

    pthread_t tid[4];
    int b=0;
    for(int i=0 ; i<4 ; ++i){
        struct node *nd=malloc(sizeof(struct node));
        nd->a=a; nd->num=num;
        nd->beg = total*i;
        if(i<3){
            nd->end = nd->beg +total-1;
        }
        else{
            nd->end = argc - 1;
        }
        pthread_create(&tid[i],NULL,binarySearch,nd);
    }
    for(int i=0 ; i<4 ; ++i){
        pthread_join(tid[i],NULL);
    }
    
    return 0;
}
