#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<ctype.h>
#include<arpa/inet.h>
#include<fstream>
#include<fcntl.h>
using namespace std;
char buff[6][100];
int ack,last_ack=-1;
vector<clock_t>t;
void sendWindow(int start,int c_socket)
{
  for(int i=start;i<start+3;i++)
  {
    if(i<6)
    {
      cout<<"i = "<<buff[i]<<endl;
      send(c_socket,&buff[i],sizeof(buff[i]),0);
      send(c_socket,&i,sizeof(i),0);
      t.push_back(clock());
    }
    else break;

  }
}
int main()
{
  int c_socket;
	c_socket=socket(AF_INET, SOCK_STREAM,0);
	struct sockaddr_in client;
	memset(&client,0,sizeof(client));
	client.sin_family=AF_INET;
	client.sin_port=htons(9000);
	client.sin_addr.s_addr=inet_addr("127.0.0.1");
	if(connect(c_socket,(struct sockaddr*)&client,sizeof(client))==-1)
	{
			printf("error firoz");
			return 0;
	}

  for(int i=0; i<6; i++)
    cin>>buff[i];

  clock_t in;
  fcntl(c_socket, F_SETFL, O_NONBLOCK);


  sendWindow(0,c_socket);
  int count=0;

  for(int i=last_ack+1; i<6; i=last_ack+1)
  {
    
    label:
    bzero(&ack,sizeof(ack));

    while(((clock()-t[0])/CLOCKS_PER_SEC)<10)
    {
      recv(c_socket,&ack,sizeof(ack),0);
      if(ack==last_ack+1)
      {

        cout<<"Acknowlegment : "<<ack<<endl;
        ack++;
        last_ack++;
        t.erase(t.begin());
        if(ack+2<6)
        {
          cout<<"i = "<<buff[ack+2]<<endl;
          send(c_socket,buff[ack+2],sizeof(buff[ack+2]),0);
          int fid=ack+2;
          send(c_socket,&fid,sizeof(fid),0);
          t.push_back(clock());
        }
        break;
      }
    }
    if(!ack)
    {
      t.clear();
      cout<<"error"<<endl;
      sendWindow(last_ack+1,c_socket);
    }


  }

	close(c_socket);

}
