#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    printf("Top\n" );
    execlp("ls","ls",NULL);
    printf("error in execl\n" );


}
