#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<thread>
#include<bits/stdc++.h>
#include<arpa/inet.h>
#include <fcntl.h>
#define MS 1024
using namespace std;
struct packet
{
    char msg[100];
    struct sockaddr_in source;
    struct sockaddr_in dest;
};
packet common;
int lockk=0;
void recvThread(int s_server,  struct sockaddr_in other)
{
      packet p;
      l1:
      while(1)
      {
        bzero(&p,sizeof(p));
        if(recv(s_server,&p,sizeof(p),0)>0 || lockk!=0)
          break;
      }
      if(lockk!=1)
      {
        char str[INET_ADDRSTRLEN];
        inet_ntop(AF_INET,&((p.source).sin_addr),str,INET_ADDRSTRLEN);
        cout<<"Packet:"<<p.msg<<"\t"<<str<<endl;
        common=p;
        lockk=1;
      }
      else
      {
        send(s_server,&common,sizeof(common),0);
        lockk=0;
      }
      goto l1;

}

void serverThread(int port)
{
      int s_server;
      int s_socket=socket(AF_INET, SOCK_STREAM,0);
      struct sockaddr_in server, other;
      memset(&server,0,sizeof(server));
      memset(&other,0,sizeof(other));
      server.sin_family=AF_INET;
      server.sin_port=htons(port);
      server.sin_addr.s_addr=INADDR_ANY;
      bind(s_socket,(struct sockaddr*)&server,sizeof(server));
      listen(s_socket,5);
      socklen_t add;
      add=sizeof(other);
      s_server=accept(s_socket,(struct sockaddr*)&other,&add);
      cout<<"Connection Accepted From : "<<inet_ntoa(other.sin_addr)<<":"<<ntohs(other.sin_port)<<endl;
      cout<<"Port"<<port<<endl;
      fcntl(s_server, F_SETFL, O_NONBLOCK);
      thread rec(recvThread,s_server,other);
      rec.join();
}
int main(int argc,char* argv[])
{
      thread server1(serverThread,atoi(argv[1]));
      thread server2(serverThread,atoi(argv[2]));
      server1.detach();
      server2.detach();
      while(1);
      return 0;

}
