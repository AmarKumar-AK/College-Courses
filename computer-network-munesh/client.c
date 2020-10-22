#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<ctype.h>

int main()
{
  int c_socket;
  char buf[100]="Hello server!\n";
  int num1,num2,option;
  c_socket=socket(AF_INET, SOCK_STREAM,0);
  struct sockaddr_in client;
  memset(&client,0,sizeof(client));
  client.sin_family=AF_INET;
  client.sin_port=htons(9009);
  // client.sin_addr.s_addr=inet_addr("172.16.18.90");
  client.sin_addr.s_addr=inet_addr("127.0.0.1");
  if(connect(c_socket,(struct sockaddr*)&client,sizeof(client))==-1)
  {
      printf("error");
      return 0;
  }

  // bzero(buf,100);
  // recv(c_socket,buf,sizeof(buf),0);
  // printf("msg from server: %s",buf);
	while(1){
	send(c_socket,buf,sizeof(buf),0);
	  recv(c_socket,buf,sizeof(buf),0);
	  printf("server--\t%s\n",buf); 
	}
   

  close(c_socket);
  return 0;
}
