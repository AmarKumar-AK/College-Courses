//data transfer between parent and child
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

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
        //message to be sent to child
        printf("enter the message to child : ");
        scanf("%s",in_message);
        write(p1[1],in_message,100);
        //message read from child
        read(p2[0],out_message,100);
        printf("message from child : %s\n",out_message);
    }
    else if(pid==0){
        //child
        char in_message[100];
        char out_message[100];
        //message read from parent
        read(p1[0],out_message,100);
        printf("message from parent : %s\n",out_message);
        //message to be sent to parent
        printf("enter the message to parent : ");
        scanf("%s",in_message);
        write(p2[1],in_message,100);
    }
    return 0;
}