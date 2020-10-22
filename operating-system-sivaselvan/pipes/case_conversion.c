//case conversion
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
int main(){
    int p1[2];
    if(pipe(p1)<0){
        perror("error in pipe1");
        return 1;
    }

    char *args[2]={"ls",NULL};
    pid_t pid=fork();
    if(pid<0){
        perror("forking error");
        return 1;
    }
    else if(pid>0){
        dup2(p1[1],1);
        execvp("ls",args);
    }
    else if(pid==0){
        int x;
        char text[100];
        while((x=read(p1[0],text,100))>0){
            for(int i=0 ; i<x ; ++i){
                text[i]=toupper(text[i]);
                printf("%c",text[i]);
            }
        }
    }

}