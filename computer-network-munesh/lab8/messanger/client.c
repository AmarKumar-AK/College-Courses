#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include <unistd.h>
#include<netinet/in.h>
#include<time.h>
#include<pthread.h>
void * runner(void * par)
{
    int * c_sock = par;
    char buf[1024];
    while(1)
    {

        bzero(buf,sizeof(buf));
        recv(*c_sock,buf,sizeof(buf),0);
        printf("from Ip:%s\n",buf );
        if(!strcmp(buf,"not found!"))
            continue;
        bzero(buf,sizeof(buf));
        recv(*c_sock,buf,sizeof(buf),0);
        printf("msg: %s\n",buf );
    }
}
int main(int argc,char* argv[])
{
    int port = atoi(argv[1]);
    printf("port:%d\n", port);
    int c_sock;
    char buf[1024];
    c_sock=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in client;
    memset(&client, 0,sizeof(client));
    client.sin_family=AF_INET;
    client.sin_port=htons(port); // Port should be similar to the server port for communication
    // client.sin_addr.s_addr=inet_addr("172.16.16.144"); //loopback adress of client machine (you choose internet IP)
    client.sin_addr.s_addr=inet_addr("172.16.18.90");
    if(connect(c_sock,(struct sockaddr*)&client,sizeof(client))==-1)
    {
        printf("[+] error in connection");
        exit(1);
    }
    printf("[+] connected to server\n");
    // printf("%s:%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port) );
    pthread_t tid;

    pthread_create(&tid,NULL,runner,&c_sock);

    while(1)
    {
        bzero(buf,sizeof(buf));
        scanf("%s",buf);
        send(c_sock,buf,sizeof(buf),0);
        bzero(buf,sizeof(buf));
        scanf("%s",buf);
        send(c_sock,buf,sizeof(buf),0);


        // bzero(buf,sizeof(buf));
        // recv(c_sock,buf,sizeof(buf),0);


    }
    // printf("%s\n", "wait for result");
    // bzero(buf,sizeof(buf));
    //
    // recv(c_sock,buf,sizeof(buf),0);
    // printf("rank:%s\n",buf );


}
