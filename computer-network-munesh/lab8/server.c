#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include <unistd.h>
#include<netinet/in.h>
#include<time.h>
#include<arpa/inet.h>
#include<sys/fcntl.h>


int main(int argc, char const *argv[]){
    int port=atoi(argv[1]);
    int s_sock,cli;
    char buf[100];
    s_sock=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server,other;
    server.sin_family=AF_INET;
    server.sin_port=htons(port);
    server.sin_addr.s_addr=INADDR_ANY;
    if(bind(s_sock,(struct sockaddr*)&server,sizeof(server))==-1)
    {
        printf("bind error");
        exit(1);
    }
    listen(s_sock,5);
    socklen_t len;
    len=sizeof(other);
    cli=accept(s_sock,(struct sockaddr*)&other, &len);
    /////////////////////////////////////////////////////
    char myIpAddress[100];
    system("hostname -I>ip.txt");
    FILE *fp=fopen("ip.txt","r");
    fscanf(fp,"%s",myIpAddress);
    send(cli,&myIpAddress,sizeof(myIpAddress),0);
    // recv(c_sock,buf,sizeof(buf),0);
    return 0;
}
