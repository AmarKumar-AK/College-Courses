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
#define PORT 5050 
#define SA struct sockaddr 

struct tree{
    char character;
    int count;
    struct tree *lptr = NULL;
    struct tree *rptr = NULL;
};

unordered_map<char,string> datamap;

bool struct_sort(struct tree* a, struct tree* b)
{
    if(a->count >= b->count)
        return false;
    else 
        return true;
}

void recur(struct tree *temp, string s)
{
    if(temp->lptr == NULL && temp->rptr == NULL)
    {

        datamap[temp->character] = s;
        return;
    }
    recur(temp->lptr,s+'0');
    recur(temp->rptr,s+'1');
} 

void func(int sockfd) 
{ 
    vector<struct tree *> x;

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
        for(int j = 0;j < x.size();j++)
        {
            if(x[j]->character == data[i])
            {
                check = 1;
                break;
            }   
        }
        if(!check)
        {
            struct tree *temp = new struct tree;
            temp->character = data[i];
            temp->count = count(data.begin(),data.end(),data[i]);
            temp->lptr = temp->rptr = NULL;
            x.push_back(temp);
        }
    }
    while(x.size() != 1)
    {
        sort(x.begin(),x.end(),struct_sort);
        struct tree *temp = new struct tree;
        temp->character = '\n';
        temp->count = x[0]->count+x[1]->count;
        temp->lptr = x[0];
        temp->rptr = x[1];
        x.erase(x.begin(),x.begin()+2);
        x.push_back(temp);
    }

    recur(x[0],"");

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

	bzero(&servaddr, sizeof(servaddr)); 

	 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(PORT); 

	 
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
		printf("socket bind failed...\n"); 
		exit(0); 
	}  

	 
	if ((listen(sockfd, 5)) != 0) { 
		printf("Listen failed...\n"); 
		exit(0); 
	} 
 
	len = sizeof(cli); 
 
	connfd = accept(sockfd, (SA*)&cli, &len); 
	if (connfd < 0) { 
		printf("server acccept failed...\n"); 
		exit(0); 
	} 
 

	func(connfd); 

	close(sockfd); 
} 
