//string reversal and palindrome check
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

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
        char in_string[100];
        printf("enter the string to reverse(in parent) : ");
        scanf("%s",in_string);
        write(p1[1],in_string,100);

        read(p2[0],in_string,100);
        printf("reversed string is %s\n",in_string);
        //checking for palindrome
        read(p1[0],in_string,100);
        int flag=0;
        int n=strlen(in_string);
        for(int i=0 ; i<n/2 ; ++i){
            if(in_string[i]!=in_string[n-i-1]){
                flag=1;
                break;
            }
        }
        if(flag==1){
            printf("%s is NOT a palindrome\n",in_string);
        }
        else{
            printf("YES, %s is a palindrome\n",in_string);
        }


    }
    else if(pid==0){
        char out_string[100];
        read(p1[0],out_string,100);
        int n=strlen(out_string);
        //reversing a string
        for(int i=0 ; i<n/2 ; ++i){
            char temp=out_string[i];
            out_string[i]=out_string[n-i-1];
            out_string[n-i-1]=temp; 
        }
        write(p2[1],out_string,100);
        printf("enter the string to check for palindrome(in child) : ");
        scanf("%s",out_string);
        write(p1[1],out_string,100);
    }
}