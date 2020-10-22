#include <unistd.h>
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <netinet/in.h>
#include <arpa/inet.h>

#include <bits/stdc++.h>

using namespace std;

#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

unordered_map<char,string> datamap;

void func(int sockfd) 
{ 
    string word,data="";
    fstream file;
    file.open("Input.txt");

    while(file >> word)
    {
        data += word + " ";
    }

    for( int i = 0; i < data.length(); i++ )
    {
        int check = 0;
        for(auto j = datamap.begin();j != datamap.end();j++)
        {
            if( j->first == data[i])
            {
                check = 1;
                break;
            }   
        }
        if(!check)
        {
            datamap[data[i]] = "";
        }
    }

    int bit_len  = ceil(log2(datamap.size())),num = 0;
     
    for(auto i = datamap.begin(); i != datamap.end() ; i++)
    {
        i->second = bitset<32>(num).to_string();
        i->second = i->second.substr(i->second.length()-bit_len,i->second.length());
        num++;
    }

    string data_true = data;
    data = "";
    for(int i=0;i<data_true.length();i++)
    {
        data += datamap[data_true[i]];
    }
    
    int len = data.length() + 1;
    char data1[len] ;
    strcpy(data1,data.c_str());
    write(sockfd,&len,sizeof(len));
    write(sockfd,&data1,sizeof(data1));
    int maplen = datamap.size();
    write(sockfd,&maplen,sizeof(maplen));
    for( auto i : datamap)
    {
        char temp1 = i.first;
        int len = i.second.length()+1;
        char temp[len];
        strcpy(temp,i.second.c_str());
        write(sockfd,&len,sizeof(len));
        write(sockfd,&temp,sizeof(temp));
        write(sockfd,&temp1,sizeof(temp1));
        cout<<i.first<<" "<<i.second<<"\n";
    }
} 

 
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int sockfd, connfd;
    socklen_t len; 
	struct sockaddr_in servaddr, cli; 


	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	// else
	// 	// printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(PORT); 

	 
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
		printf("socket bind failed...\n"); 
		exit(0); 
	} 
	// else
	// 	// printf("Socket successfully binded..\n"); 

	 
	if ((listen(sockfd, 5)) != 0) { 
		printf("Listen failed...\n"); 
		exit(0); 
	} 
	// else
	// 	// printf("Server listening..\n"); 
	len = sizeof(cli); 
 
	connfd = accept(sockfd, (SA*)&cli, &len); 
	if (connfd < 0) { 
		printf("server acccept failed...\n"); 
		exit(0); 
	} 
	// else
	// 	// printf("server acccept the client...\n"); 

	func(connfd); 

	close(sockfd); 
} 
