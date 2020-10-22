//generating prime number till the given limit
//./a.out 100
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

void *primeNumberGenerator(void *param){
    int *a=(int *)param;
    int flag=0;
        for(int j=2 ; j<*a ; ++j){
            if(*a%j==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            printf("%d ",*a);
        }
}
int main(int argc, char const *argv[])
{
    pthread_t tid;
    int i=2;
    int x=atoi(argv[1]);
    while(i<=x){
        int *f=(int *)malloc(sizeof(int));
        *f=i;
        pthread_create(&tid,NULL,primeNumberGenerator,f);
        //pthread_join(tid,NULL);
        i++;
    }
    for(int i=2 ; i<=x ; ++i){
        pthread_join(tid,NULL);
    }
    
    return 0;
}





























// #include<stdio.h>
// #include<unistd.h>
// #include<pthread.h>
// #include<stdlib.h>

// void *primeNumberGenerator(void *param){
//     int *a=(int *)param;
//     int flag=0;
//         for(int j=2 ; j<*a ; ++j){
//             if(*a%j==0){
//                 flag=1;
//                 break;
//             }
//         }
//         if(flag==0){
//             printf("%d ",*a);
//         }
// }
// int main(int argc, char const *argv[])
// {
//     pthread_t tid;
//     int i=2;
//     int x=atoi(argv[1]);
//     while(i<=x){
//         pthread_create(&tid,NULL,primeNumberGenerator,&i);
//         // pthread_join(tid,NULL);
//         i++;
//     }
//     // cout<<"hello"<<i<<endl;
//     printf("hello%d\n",i);
//     while(i>0){
//         pthread_join(tid,NULL);
//         i--;
//     }
    
//     return 0;
// }