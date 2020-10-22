#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    printf("Top\n" );
    char *cmd[]={"ls","-l",NULL};
    execvp("ls",cmd);

    printf("error in execvp\n" );
    return 0;
}
