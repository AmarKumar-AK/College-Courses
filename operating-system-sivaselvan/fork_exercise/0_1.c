#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
    if(fork() || fork()){
        fork();
    }
    printf("OS 2019\n");
    return 0;
}