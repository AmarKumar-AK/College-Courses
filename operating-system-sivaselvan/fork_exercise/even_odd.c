#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
    pid_t pid;
    int a=0;
    pid=fork();
    if(pid==0){
        printf("In child\n");
        for(int i=0 ; i<10 ; ++i){
            printf("%d ",a);
            a=a+2;
        }
        printf("\n");
    }
    else if(pid>0){
        a=a+1;
        printf("In parent\n");
        for(int i=0 ; i<10 ; ++i){
            printf("%d ",a);
            a=a+2;
        }
        printf("\n");
    }
    return 0;
}