//string concatenation
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
int main(){
    int p1[2],p2[2];
    if(pipe(p1)<0){
        perror("error in pipe1");
        return 1;
    }
    if(pipe(p2)<0){
        perror("error in pipe2");
        return 1;
    }

    char str[]=" Hi! there";
    
    pid_t pid=fork();
    if(pid<0){
        perror("forking error");
        return 1;
    }
    else if(pid>0){
        char in_string[100];
        printf("enter the string to which you want to concatenate : ");
        fgets(in_string,100,stdin);
        write(p1[1],in_string,100);
        wait(NULL);
        read(p2[0],in_string,100);
        printf("concatenated string is %s",in_string);
    }
    else if(pid==0){
        char add_string[100];
        read(p1[0],add_string,100);
        int k=strlen(add_string);
        for(int i=0 ; i<strlen(str) ; ++i){
            add_string[k++]=str[i];
        }
        write(p2[1],add_string,100);
    }
}