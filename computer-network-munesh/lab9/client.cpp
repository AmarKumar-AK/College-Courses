#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<thread>
#include<time.h>
using namespace std;
struct packet
{
    char msg[100];
    char source[INET_ADDRSTRLEN];
    char dest[INET_ADDRSTRLEN];
}p,p1;

  
void recvThread(int c_socket)
{
  while(1)
  {
    bzero(&p,sizeof(p));
    recv(c_socket,&p,sizeof(p),0);
    cout<<"From: "<<p.source<<"\tMsg: "<<p.msg<<endl;
  }
}
int main(int argc , char *argv[])
{
    int c_socket;
    string ips="192.168.43.104";
    char buf[500];
    c_socket=socket(AF_INET, SOCK_STREAM,0);
    struct sockaddr_in client;
    memset(&client,0,sizeof(client));
    client.sin_family=AF_INET;
    client.sin_port=htons(atoi(argv[1]));
    client.sin_addr.s_addr=inet_addr("192.168.43.92");
    if(connect(c_socket,(struct sockaddr*)&client,sizeof(client))==-1)
    {
        printf("Error in connection\n");
        return 0;
    }
    else
    {
      cout<<"Connection Established.......\nconnected accepted from "<<ips<<endl;
    }
    thread clt(recvThread,c_socket);
    clt.detach();
    cout<<"To chat enter the destination ip and the msg"<<endl;
    while(1)
    {

        cin>>p1.dest>>p1.msg;
        strcpy(p1.source,"192.168.43.107");
        if(strcmp(p1.msg,"exit")==0 || strcmp(p1.msg,"exit\n")==0)
           break;
        send(c_socket,&p1,sizeof(p1),0);
    }

    close(c_socket);
}
