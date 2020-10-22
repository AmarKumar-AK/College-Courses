#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#define MS 200
using namespace std;

int main()
{
	int s_server;
	int s_socket=socket(AF_INET, SOCK_STREAM,0);
	struct sockaddr_in server, other;

  memset(&server,0,sizeof(server));
  memset(&other,0,sizeof(other));
  server.sin_family=AF_INET;
  server.sin_port=htons(9000);
  server.sin_addr.s_addr=INADDR_ANY;
  bind(s_socket,(struct sockaddr*)&server,sizeof(server));
  listen(s_socket,5);
  socklen_t add;
  add=sizeof(other);
  s_server=accept(s_socket,(struct sockaddr*)&other,&add);
  cout<<"Connection Accepted"<<endl;
	char buff[100];
	int count=0,fid;
	while(1)
	{
		bzero(&buff,sizeof(buff));
		recv(s_server,&buff,sizeof(buff),0);
		bzero(&fid,sizeof(fid));
		recv(s_server,&fid,sizeof(fid),0);
		if(strlen(buff)!=0 && count!=2 )
		{

			cout<<buff<<endl;
			cout<<fid<<" sent"<<endl;
			send(s_server,&fid,sizeof(fid),0);
		}
		count++;
	}

  close(s_socket);
}
