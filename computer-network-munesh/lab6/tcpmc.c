#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include <unistd.h>
#include<netinet/in.h>

int main()
{
    int c_sock;
    char buf[100];
    c_sock=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in client;
    memset(&client, 0,sizeof(client));
    client.sin_family=AF_INET;
    client.sin_port=htons(5055); // Port should be similar to the server port for communication
    client.sin_addr.s_addr=inet_addr("172.16.16.144"); //loopback adress of client machine (you choose internet IP)
    if(connect(c_sock,(struct sockaddr*)&client,sizeof(client))==-1)
    {
        printf("[+] error in connection");
        exit(1);
    }
    printf("[+] connected to server");
    strcpy(buf,"hi");
    send(c_sock,buf,sizeof(buf),0);
    bzero(buf,sizeof(buf));
    while(1)                     // infinete loop to continue the client-server communication
    {
        // printf("client to server");
        // fgets(buf,100,stdin);        //get message into the buffer to be send to server


        recv(c_sock,buf,sizeof(buf),0);
        printf("\n%s\n",buf );
        if(!strcmp(buf,"Better luck next time"))
        {
            bzero(buf,sizeof(buf));
            recv(c_sock,buf,sizeof(buf),0);
            printf("%s\n",buf);
            break;
        }
        // fgets(buf,100,stdin);
        scanf("%s",buf);

        send(c_sock,buf,sizeof(buf),0);
        bzero(buf,sizeof(buf));

    }
    close(c_sock);
    return 0;
}
