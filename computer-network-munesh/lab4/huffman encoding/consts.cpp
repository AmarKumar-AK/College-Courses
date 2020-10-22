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
  server.sin_port=htons(9009);
  server.sin_addr.s_addr=INADDR_ANY;
  bind(s_socket,(struct sockaddr*)&server,sizeof(server));
  listen(s_socket,5);
  socklen_t add;
  add=sizeof(other);
  s_server=accept(s_socket,(struct sockaddr*)&other,&add);
  cout<<"Connection Accepted"<<endl;

	vector<char> s(MS);
	int nob,size;
	char encoded[100];
	bzero(&s[0],s.size());
	recv(s_server,&s[0],s.size(),0);
	cout<<"Received Text: ";
  for(int i=0;i<s.size();i++)
    cout<<s[i];
	cout<<endl;
	bzero(&nob,sizeof(nob));
	recv(s_server,&nob,sizeof(nob),0);
	cout<<nob<<endl;
	bzero(&size,sizeof(size));
	recv(s_server,&size,sizeof(size),0);
	cout<<size<<endl;
	bzero(&encoded,100);
	recv(s_server,&encoded,100,0);
	for(int i=0;i<100;i++)
	cout<<encoded[i];
	cout<<endl;
	for(int i=0;i<size;i+=nob)
	{
		int sum=0; int l=0;
		for(int j=i+nob-1;j>=i;j--)
		{
			sum+=(encoded[j]-'0')*pow(2,l++);
			//cout<<sum<<" "<<encoded[j]<<" "<<j<<" "<<j-i<<" "<<pow(2,j-i)<<endl;
		}
	//	cout<<sum<<" "<<s[sum]<<endl;
	cout<<s[sum];
	}
	 cout<<endl;



  close(s_socket);
}
