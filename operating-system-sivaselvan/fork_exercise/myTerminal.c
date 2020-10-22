// #include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<wait.h>
// using namespace std;

void push(char stack[][100], char s[], int *top){
    strcpy(stack[*top],s);
    (*top)++;
}

void printStack(char stack[][100], int *top, int end){
    for(int i=*top-1; i>=end; i--){
        printf("%s\n",stack[i]);
    }
    printf("\n");
}

int main(){
    char stack[10][100]={0};
    int top = 0;
    while(1){
        printf("\n%s","Saumya:$");
        char s[100]={0};
        scanf("%[^\n]%*c",s);
        push(stack,s,&top);
        char args[10][20]={0};
        char *argu[10]={0};
        int length = strlen(s);
        int ar=0, counter=0;
        for(int i=0; i<length; i++){
            if(s[i]==' '){
                ar+=1;
                counter=0;
            }else{
                args[ar][counter++]=s[i];
            }
        }
        int i=0;
        for(i=0; i<=ar; i++){
            argu[i]=args[i];
        }
        argu[i]=NULL;
        int pid = fork();
        if(pid == 0){
            if(!strcmp(argu[0],"history")){
                printStack(stack, &top, 0);
            }else {
                if(execvp(*argu, argu)<0){
                    printf("No such command\n");
                };
            }
            exit(0);
        }
        wait(NULL);
    }
    return 0;
}