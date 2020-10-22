//generating mean median mode
//./a.out 3 7 1 6 2 7 7 3
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
int size;

void *mean(void *param[]){
    size=0;
    //calculating size
    while(param[++size]!=NULL);
    float sum=0;
    //summing all elements
    for(int i=1 ; i<size ; ++i){
        sum+=atoi(param[i]);
    }
    printf("mean : %.2f\n",sum/(size-1));
}

void *median(void *param[]){
    //sorting
    for(int i=2 ; i<size ; ++i){
        for(int j=i ; j>0 ; --j){
            if(atoi(param[j])<atoi(param[j-1])){
                int *temp =param[j];
                param[j]=param[j-1];
                param[j-1]=temp;
            }
        }
    }
    printf("median : %d\n",atoi(param[size/2]));
}
void *mode(void *param[]){
    int current_count=1,max_count=0,mod;
    int prev=atoi(param[1]);
    for(int i=2 ; i<size ; ++i){
        if(atoi(param[i])==prev){
            current_count++;
        }
        else{
            current_count=1;
        }
        
        if(max_count<current_count){
            max_count=current_count;
            mod=prev;
        }
        prev=atoi(param[i]);
    }
    printf("mode : %d\n",mod);
}
int main(int argc, char const *argv[])
{
    pthread_t tid1,tid2,tid3;
    pthread_create(&tid1,NULL,(void *)mean,(void *)argv);
    pthread_create(&tid2,NULL,(void *)median,(void *)argv);
    pthread_create(&tid3,NULL,(void *)mode,(void *)argv);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    return 0;
}



























// //sorting
    // for(int i=2 ; i<size ; ++i){
    //     for(int j=i ; j>0 ; --j){
    //         if(atoi(param[j])<atoi(param[j-1])){
    //             int *temp =param[j];
    //             param[j]=param[j-1];
    //             param[j-1]=temp;
    //         }
            
    //     }
    // }
    //////////////////
        // int a[100];
    // int k=0;
    // while(param[++k]!=NULL){
    //     a[k-1]=atoi(param[k]);
    // }
    // printf("%d",a[0]);
    ////////////////
    // printf("inside median : %d",size);
    // for(int i=1 ; i<size ; ++i){
    //     printf("%d ",atoi(param[i]));
    // }