#include<unistd.h>
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <netinet/in.h>
#include <arpa/inet.h>

#include<bits/stdc++.h>

using namespace std;

#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

unordered_map<string,char> datamap;

void func(int sockfd) 
{ 
	int len;
	read(sockfd,&len,sizeof(len));
	char data[len];
    read(sockfd,&data,sizeof(data));
    read(sockfd,&datamap,datamap.size());
	int maplen;
	read(sockfd,&maplen,sizeof(maplen));
	for(int i=0;i<maplen;i++)
	{
		int len;
		read(sockfd,&len,sizeof(len));
		char temp[len],temp1;
		read(sockfd,&temp,sizeof(temp));
		read(sockfd,&temp1,sizeof(temp1));
		datamap[temp] = temp1; 
	}
    for(auto i : datamap)
        cout<<i.first<<" "<<i.second<<"\n";

	cout<<"\n"<<data<<"\n\n";

	string s="";

	for(int i=0;i<sizeof(data);i++)
	{
		s += data[i];
		if(datamap.find(s) != datamap.end())
		{
			cout<<datamap[s];
			s = "";
		}
	}
	cout<<"\n";
} 

int main() 
{ 
	int sockfd, connfd; 
	struct sockaddr_in servaddr, cli; 
 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(PORT); 

	 
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		printf("connection with the server failed...\n"); 
		exit(0); 
	} 
	else
		printf("connected to the server..\n"); 

 
	func(sockfd); 
 
	close(sockfd); 
} 
