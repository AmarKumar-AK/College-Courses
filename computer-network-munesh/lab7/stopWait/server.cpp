#include<bits/stdc++.h>
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
using namespace std;
int main(int argc, char const *argv[])
{
    int port=atoi(argv[1]);
    int s_sock,cli;
    char buff[100]="hello";
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
    int ack=-1;
    int counter=0;
    // fcntl(c_sock,F_SETFL,O_NONBLOCK);
    // recv(cli,&buff,sizeof(buff),0);
    // cout<<buff<<endl;
    while(1){
        counter++;
        bzero(buff,sizeof(buff));
        int nb=recv(cli,&buff,sizeof(buff),0);
        if(nb>0) ack =1;
        else ack =0;
        if(counter==3)
            {
                ack =0;
                
            }
        send(cli,&ack,sizeof(ack),0);
        if(!strcmp(buff,"break")){
            break;
        }
        
        cout<<buff<<endl;
    }
    
    return 0;
}