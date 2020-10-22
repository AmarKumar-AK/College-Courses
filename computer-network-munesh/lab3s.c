#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

int main()
{
    int s_sock,cli;
    char buf[100];
    s_sock=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server,other;
    server.sin_family=AF_INET;
    server.sin_port=htons(9000);
    server.sin_addr.s_addr=INADDR_ANY;
    if(bind(s_sock,(struct sockaddr*)&server,sizeof(server))==-1)
    {
        printf("bind error");
        exit(1);
    }
    listen(s_sock,5);
    socklen_t len;
    len=sizeof(other);
    cli=accpet(s_sock,(struct sockaddr*)&other, &len);
    read(cli,buf,sizeof(buf));
    FILE *fp;
    fp=open("add.txt","w");
    fprintf(fp,"%s",buf);
    printf("file received successfully");
    printf("data copied in add.txt file");
    fclose(fp);
    close(s_sock);
    return 0;

}