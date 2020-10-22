//implementing quicksort
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

int partition(int *a,int beg,int end){
    int i = beg;
    int j = end;
    int pivot = a[beg];
    
    while (i <= j){
        while (a[i] <= pivot && i <= end){
            i++;
        }
        while (a[j] > pivot && j > beg){
            j--;
        }
        
        int temp;
        if (i < j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[beg];
    a[beg] = a[j];
    a[j] = temp;
    
    return j;
}

void print(int *a,int SIZE){
    for (int i = 0; i <SIZE; ++i){
        printf("%d ",a[i]);
    }
}

void *sorting(void *param){
    struct node *nd=param;
    int beg=nd->begs;
    int end=nd->ends;
    
    if (beg < end){
        pthread_t tid1,tid2;
        int p = partition(nd->a, beg, end);

        struct node *nd1=malloc(sizeof(struct node));
        nd1->begs=beg;
        nd1->ends=p-1;
        nd1->a=nd->a;
        pthread_create(&tid1,NULL,sorting,nd1);

        struct node *nd2=malloc(sizeof(struct node));
        nd2->begs=p+1;
        nd2->ends=end;
        nd2->a=nd->a;
        pthread_create(&tid2,NULL,sorting,nd2);

        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);
    }
}


int main(int argc, char const *argv[]){
    int a[argc];
    for(int i=0 ; i<argc-1 ; ++i){
        a[i]=atoi(argv[i+1]);
    }

    struct node *nd=malloc(sizeof(struct node));
    nd->a=a;
    nd->begs=0;
    nd->ends=argc-2;

    pthread_t tid;
    pthread_create(&tid,NULL,sorting,nd);
    pthread_join(tid,NULL);

    print(a,argc-1);
    printf("\nreached end\n");
    return 0;
}
