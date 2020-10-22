// #include<stdio.h>
// #include<sys/types.h>
// #include<unistd.h>
// void fib(int n){
//     int a=0;
//     int b=1;
//     int c;
//     printf("%d %d ",0,1);
//     int count=2;
//     while(count!=n){
//         c=a+b;
//         printf("%d ",c);
//         a=b;
//         b=c;
//         count++;
//     }
//     printf("\n");
// }
// void prime(int n){
//     int count=0;
//     int i=2;
//     while(count!=n){
//         int flag=0;
//         for(int j=2 ; j<i ; ++j){
//             if(i%j==0){
//                 flag=1;
//             }
//         }
//         if(flag==0){
//             printf("%d ",i);
//             count++;
//         }
//         ++i;
//     }
// }
// int main(){
//     pid_t pid;
//     int f,p;
//     printf("enter number of fib series you want to generate : ");
//     scanf("%d",&f);
//     printf("enter number of prime series you want to generate : ");
//     scanf("%d",&p);

//     pid=fork();
//     if(pid>0){
//         printf("Inside parent\n");
//         fib(f);
//     }
//     else if(pid==0){
//         printf("Inside child")
//         prime(p);
//     }
//     return 0;
// }

#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    pid_t pid;
    int p;
    printf("enter number of prime series you want to generate : ");
    scanf("%d",&p);
    int a[p];
    
    pid=vfork();

    if(pid==0)
    {
        int count=0;
        int i=2;
        // printf("hello %d",p);
        while(count!=p){
            int flag=0;
            for(int j=2 ; j<i ; ++j){
                if(i%j==0){
                    flag=1;
                }
            }
            if(flag==0){
                // printf("%d ",i);
                a[count]=i;
                count++;
            }
	printf("enter number of prime series you want to generate : ");
    scanf("%d",&p);
    int a[p];
            ++i;
        }
        exit(0);
    }
    else if(pid>0){
        for(int i=0 ; i<p ; ++i){
            printf("%d ",a[i]);
        }

    }
    return 0;
}
