//counting lines,word,characters
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>
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
    int characters=0;
    int lines=0;
    int words=0;
    FILE *fp=fopen("input.txt","r");
    pid_t pid=fork();
    
    
    if(pid<0){
        perror("forking error");
        return 1;
    }
    else if(pid>0){
        
        char str[1000];
        if(fp==NULL){
            perror("error in opening file\n");
            return 1;
        }

        close(p1[0]);
        while(fgets(str,1000,fp)){
            lines++;
            write(p1[1],str,1000);
        }
        close(p1[1]);
        printf("number of lines : %d\n",lines);
        
    }
    else if(pid==0){
        close(p1[1]);
        int x;
        char str[1000];
        while((x=read(p1[0],str,1000))>0){
            for(int i=0 ; i<strlen(str); ++i){
                characters++;
                if(str[i]=='\n' || str[i]==' '){
                    words++;
                }
            }
        }
        printf("number of words : %d\n",words);
        printf("number of characters : %d\n",characters);
        close(p1[0]);

    }
    fclose(fp);
    return 0;
}