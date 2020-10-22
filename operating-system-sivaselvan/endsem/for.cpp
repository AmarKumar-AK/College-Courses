//data transfer between parent and child
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

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

    pid_t pid=fork();
    if(pid<0){
        perror("forking error");
        return 1;
    }
    else if(pid>0){
        //parent
        char in_message[100];
        char out_message[100];
        string msg="";
        //message to be sent to child
        FILE *f1=fopen("1.txt","r");
        while(fscanf(f1,"%s",in_message)!=EOF){
            msg+=in_message;
        }
        const char *mg=msg.c_str();
        write(p1[1],mg,100);
    }
    else if(pid==0){
        //child
        char in_message[100];
        char out_message[100];
        FILE *f2=fopen("2.txt","w");
        //message read from parent
        read(p1[0],out_message,100);
        while(fprintf(f2,"%s",out_message));
    }
    return 0;
}