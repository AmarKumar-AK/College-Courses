#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
void main()
{
    pid_t pid;
    pid = fork();
    if (pid > 0)
    {
        sleep(3);
        printf("I am parent.\n");
        printf("pid of parent : %d\n", getpid());
    }

    else
    {
        printf("I am child.\n");
        printf("pid of parent of child : %d\n", getppid());
        printf("child completed\n");
        exit(0);
    }
}