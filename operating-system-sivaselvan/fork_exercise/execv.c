#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    printf("Top\n" );
    char *cmd[]={"ls",NULL};
    execv("/bin/ls",cmd);
    printf("error in execv\n" );


}
