#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include <unistd.h>
#include<netinet/in.h>
#include<time.h>

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
    client.sin_addr.s_addr=inet_addr("172.16.16.144"); //loopback adress of client machine (you choose internet IP)
    if(connect(c_sock,(struct sockaddr*)&client,sizeof(client))==-1)
    {
        printf("[+] error in connection");
        exit(1);
    }
    printf("[+] connected to server\n");
    printf("%s\n","Game will start in 10sec" );

    while(1)
    {
        bzero(buf,sizeof(buf));
        recv(c_sock,buf,sizeof(buf),0);
        printf("%s\n",buf );
        if(!strcmp(buf,"Better luck next time"))
        {
            exit(0);
            // pthread_exit(0);
        }
        if(!strcmp(buf,"end"))
        {
            break;
        }
        if(!strcmp(buf,"timesUp!"))
        {
            printf("%s\n","you are late!!" );
            return(0);
            // break;
        }


        bzero(buf,sizeof(buf));
        scanf("%s",buf);
        send(c_sock,buf,sizeof(buf),0);


    }
    printf("%s\n", "wait for result");
    // bzero(buf,sizeof(buf));
    int rank;
    recv(c_sock,&rank,sizeof(rank),0);
    printf("rank:%d\n",rank );


}
    // strcpy(buf,"hi");
    // send(c_sock,buf,sizeof(buf),0);
    // bzero(buf,sizeof(buf));
    // // clock_t time=clock(),ctime;
    // float ttime=0,avg;
    // while(1)                     // infinete loop to continue the client-server communication
    // {
    //     // printf("client to server");
    //     // fgets(buf,100,stdin);        //get message into the buffer to be send to server
    //     bzero(buf,sizeof(buf));
    //     clock_t time=clock(),ctime;
    //     recv(c_sock,buf,sizeof(buf),0);
    //     printf("\n%s\n",buf );
    //     if(!strcmp(buf,"Better luck next time"))
    //     {
    //         bzero(buf,sizeof(buf));
    //         recv(c_sock,buf,sizeof(buf),0);
    //         printf("%s\n",buf);
    //         break;
    //     }
    //     if(!strcmp(buf,"timesUp!"))
    //     {
    //         close(c_sock);
    //         break;
    //     }
    //     if(!strcmp(buf,"end"))
    //     {
    //         avg=ttime/3;
    //         printf("avgc::%f\n",avg);
    //         send(c_sock,&avg,sizeof(avg),0);
    //         bzero(buf,sizeof(buf));
    //         int rank=0;
    //         recv(c_sock,&rank,sizeof(rank),0);
    //         printf("result:%d\n",rank );
    //         break;
    //
    //     }
    //     // fgets(buf,100,stdin);
    //     scanf("%s",buf);
    //
    //     send(c_sock,buf,sizeof(buf),0);
    //     ctime=clock()-time;
    //     ttime=ttime+(float)ctime/CLOCKS_PER_SEC*10000;
    //     printf("%f\n",ttime );
    //     bzero(buf,sizeof(buf));
    //
    // }
    // close(c_sock);
    // return 0;
// }
