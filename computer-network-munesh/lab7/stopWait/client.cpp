#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include <unistd.h>
#include<netinet/in.h>
#include<time.h>
#include<arpa/inet.h>
#include<sys/fcntl.h>
using namespace std;
int START=1;
int once;
void * timer (void * par)
{
    START =1;
    if(once==2)
    {
        START =0;
        pthread_exit(0);
    }
    clock_t time=clock(),tt;
    while(tt=(clock()-time)/CLOCKS_PER_SEC<10);

    START=0;

}


int main(int argc, char const *argv[])
{
    int port=atoi(argv[1]);
    int c_sock;
    char buf[100];
    c_sock = socket(AF_INET, SOCK_STREAM,0);
    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_port = htons(port);
    // client.sin_addr.s_addr = INADDR_ANY;
    client.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(connect(c_sock,(struct sockaddr*)&client,sizeof(client))==-1)
    {
        printf("connection error");
        exit(1);
    }
    int i=2;
    int ack=-1;
    // send(c_sock,argv[i],sizeof(argv[i]),0);
    while(1){
        START =1;
        cout<<argv[i]<<endl;
        strcpy(buf,argv[i]);
        pthread_t tid;
        
        
        if(i==2) 
        {
            once = 2;           
        }
        else
        {
            once =0;
        }
        
        pthread_create(&tid,NULL,timer,NULL);
        while(START);
        // cout<<"out\n";
        send(c_sock,buf,sizeof(buf),0);
        ++i;
        recv(c_sock,&ack,sizeof(ack),0);
        if(ack==0)
        {
            cout<<"error\n";
            i--;   
        } 
        
        if(i==argc){
            send(c_sock,"break",sizeof("break"),0);
            // cout<<"break\n";
            break;
        }
    }

    return 0;
}