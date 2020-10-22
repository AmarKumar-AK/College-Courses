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
struct table
{
  char ip[INET_ADDRSTRLEN];
  int sockfd;
};
vector<table> t1;

struct packet
{
    char msg[100];
    char source[INET_ADDRSTRLEN];
    char dest[INET_ADDRSTRLEN];
};

void serverThread(int s_server,struct sockaddr_in other,int s_socket)
{
  cout<<"Connection Accepted From : "<<inet_ntoa(other.sin_addr)<<":"<<ntohs(other.sin_port)<<endl;
  while(1)
  {
    read(s_server,&p,sizeof(p));
    //check
    for(int i=0;i<t1.size();i++)
    {
      if(strcmp(t1.ip,p.dest)==0)
      {
        send(t1.sockfd,&p,sizeof(p),0);
      }
    }
  }


}

int main(int argc,char* argv[])
{
  int s_server;
  int s_socket=socket(AF_INET, SOCK_STREAM,0);
  struct sockaddr_in server, other;
  memset(&server,0,sizeof(server));
  memset(&other,0,sizeof(other));
  server.sin_family=AF_INET;
  server.sin_port=htons(atoi(argv[1]));
  server.sin_addr.s_addr=INADDR_ANY;
  bind(s_socket,(struct sockaddr*)&server,sizeof(server));
  listen(s_socket,5);
  socklen_t add;
  add=sizeof(other);


  //fcntl(s_socket, F_SETFL, O_NONBLOCK);
  while(1)
  {
    s_server=accept(s_socket,(struct sockaddr*)&other,&add);
    struct table t;
    strcpy(t.ip,inet_ntoa(other.sin_addr));
    t.sockfd=s_server;
    t1.push_back(t);
    thread server1(serverThread,s_server,other,s_socket);
    server1.detach();
  }
  close(s_socket);



  return 0;

}
