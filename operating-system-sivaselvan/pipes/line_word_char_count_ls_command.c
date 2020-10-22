//count lines,word and character of ls command
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
int main(){
    char *args[2]={"ls",NULL};
    int words=0,characters=0,lines=0;
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
        close(p1[0]);
        dup2(p1[1],1);
        execvp("ls",args);
        close(p1[1]);
    }
    else if(pid==0){
        close(p1[1]);
        int x;
        char str[100];
        // printf("hello\n");
        while((x=read(p1[0],str,100))>0){
            for(int i=0 ; i<x ; ++i){
                characters++;
                printf("%c",str[i]);
                if(str[i]=='\n'){
                    lines++;
                    words++;
                }
                if(str[i]==' '){
                    words++;
                }
            }
        }
        printf("number of lines : %d\n",lines);
        printf("number of words : %d\n",words);
        printf("number of characters : %d\n",characters);
        close(p1[0]);
    }
    return 0;
}