#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        sleep(5);
        printf("Inside child.\n");
        printf("process id of parent of child : %d\n", getppid());
        printf("process id of child : %d\n", getpid());
    }
    else
    {
        printf("Inside parent.\n");
        printf("process id of parent : %d\n", getpid());
    }
}