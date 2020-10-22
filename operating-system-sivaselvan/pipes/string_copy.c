//string copy
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
int main(){
    int p1[2];
    if(pipe(p1)<0){
        perror("error in pipe1");
        return 1;
    }
    
    pid_t pid=fork();
    if(pid<0){
        perror("forking error");
        return 1;
    }
    else if(pid>0){
        char in_text[100];
        printf("enter the text to copy : ");
        fgets(in_text,100,stdin);
        write(p1[1],in_text,100);
    }
    else if(pid==0){
        char copied[100];
        read(p1[0],copied,100);
        printf("copied text : %s\n",copied);
    }
    return 0;
}