#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<thread>
using namespace std;
struct packet
{
    char msg[100];
    struct sockaddr_in source;
    struct sockaddr_in dest;
};
const char* ip[]={"192.168.43.107","192.168.43.104"};
void sendThread(packet p,int c_socket)
{
    while(1)
    {
      //printf("\n Type a message ...... ");
      //fflush(stdout);
      fgets(p.msg,100,stdin);

      send(c_socket,&p,sizeof(p),0);
      printf("\nMessage sent!!!\n");

    }
}
void recvThread(packet p,int c_socket)
{
  while(1)
  {
      bzero(&p,sizeof(p));
      recv(c_socket,&p,sizeof(p),0);
      char str[INET_ADDRSTRLEN];
      inet_ntop(AF_INET,&((p.source).sin_addr),str,INET_ADDRSTRLEN);
      cout<<p.msg<<"\tfrom : "<<str<<endl;//<<"      destination"<<p.dest<<endl;
  }
}
void client(int i,char* port)
{
    //system("clear");
    packet p;
    inet_pton(AF_INET,ip[i],&((p.source).sin_addr));
    int c_socket;
    char buf[100];
    c_socket=socket(AF_INET, SOCK_STREAM,0);
    struct sockaddr_in client;
    memset(&client,0,sizeof(client));
    client.sin_family=AF_INET;
    client.sin_port=htons(atoi(port));
    client.sin_addr.s_addr=inet_addr(ip[i]);
    if(connect(c_socket,(struct sockaddr*)&client,sizeof(client))==-1)
    {
        printf("Error in connection\n");
        return;
    }
    else
        cout<<"Connection Established......."<<endl;

    thread t1(recvThread,p,c_socket);
    thread t2(sendThread,p,c_socket);
    t1.detach();
    t2.detach();
    while(1);
    close(c_socket);
}
int main(int argv,char* argc[])
{
  char internalIp[]={"9001"};
  thread t1(client,0,internalIp);
  thread t2(client,1,argc[1]);
  t1.detach();
  t2.detach();
  while(1);
  return 0;
}
