#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
    printf("OS\n");
    fork();
    printf("2019\n");
    fork();
    printf("IIITDM\n");

    return 0;
}