#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    pid_t pid =fork();
    if(pid==0)
    {
        printf("Top\n" );
        execl("/bin/cat","cat","2.c",NULL);
        printf("error in execl\n" );
        return 0;

    }
    

}
