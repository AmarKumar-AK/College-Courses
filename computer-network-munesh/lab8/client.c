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
    int c_sock;
    char buf[100];
    c_sock = socket(AF_INET, SOCK_STREAM,0);
    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_port = htons(port);
    // client.sin_addr.s_addr = INADDR_ANY;
    client.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(connect(c_sock,(struct sockaddr*)&client,sizeof(client))==-1)
    {
        printf("connection error");
        exit(1);
    }
    ////////////////////////////////////////////////

    
    recv(c_sock,buf,sizeof(buf),0);
    // send(cli,&buf,sizeof(buf),0);
    printf("%s",buf);
    return 0;
}
