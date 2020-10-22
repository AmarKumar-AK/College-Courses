#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

int main()
{
  int s_socket,s_server;
  char buf[100]="hello client\n";
  s_socket=socket(AF_INET, SOCK_STREAM,0);
  struct sockaddr_in server, other;
  memset(&server,0,sizeof(server));
  memset(&other,0,sizeof(other));
  
  server.sin_family=AF_INET;
  server.sin_port=htons(9009);
  server.sin_addr.s_addr=INADDR_ANY;
  
  bind(s_socket,(struct sockaddr*)&server,sizeof(server));
  listen(s_socket,5);
  socklen_t add;
  add=sizeof(other);
  s_server=accept(s_socket,(struct sockaddr*)&other,&add);
while(1)
{
  recv(s_server,buf,sizeof(buf),0);
  printf("client--\t%s\n",buf);
  scanf("%s",buf);
  //bzero(buf,100);
  //fgets(buf,100,stdin);
  send(s_server,buf,sizeof(buf),0);}
  close(s_server);
  return 0;



}
