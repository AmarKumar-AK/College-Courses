#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<time.h>
#include<pthread.h>

struct User{
    int client_id,server_id;
    char ip[32];
    int port;

};
int userCount=0;
struct User usr[10];
pthread_t tid[10];

void * runner(void * par)
{

    struct User* u=par;
    int c_client=u->client_id;
    char ip[32],msg[1024],buf[1024];
    // close(u->server_id);
    // char buf[1024];
    while(1)
    {
        bzero(ip,sizeof(ip));
        bzero(msg,sizeof(msg));
        bzero(buf,sizeof(buf));
        recv(c_client,buf,sizeof(buf),0);
        strcpy(ip,buf);
        bzero(buf,sizeof(buf));
        recv(c_client,buf,sizeof(buf),0);
        strcpy(msg,buf);

        printf("ip:%s\n",ip );
        printf("msg:%s\n",msg );
        int index=-1;
        int port=atoi(ip);
        for(int i=0;i<userCount;i++)
        {
            printf("%s:%d\n", usr[i].ip,port);
            if(usr[i].port==port)
            {
                index=i;
                break;
            }
        }
        if(index==-1)
        {
            printf("%s\n","not found" );
            strcpy(buf,"not found!");
            send(c_client,buf,sizeof(buf),0);
        }
        else
        {
            char ownip[32];
            bzero(ownip,sizeof(ownip));
            strcpy(ownip,u->ip);
            send(usr[index].client_id,ownip,sizeof(ownip),0);
            send(usr[index].client_id,msg,sizeof(msg),0);
        }



    }


    // send(c_client,buf,sizeof(buf),0);
    // bzero(buf,sizeof(buf));

}

int main(int argc,char * argv[])
{
    int port=atoi(argv[1]);
    printf("port:%d\n",port );
    int s_socket,c_client;
    char buf[1024];
    socklen_t addr_size;
    s_socket=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server,other;
    memset(&server,0,sizeof(server));
    server.sin_family=AF_INET;
    server.sin_port=htons(port);
    server.sin_addr.s_addr=INADDR_ANY;

    if(bind(s_socket,(struct sockaddr*)&server,sizeof(server))==-1)
    {
        printf("%s\n","[-]Bind error" );
        exit(1);
    }

    if(listen(s_socket,10)==0)
        printf("[+] sever listing...");


    // clock_t ctime;
    // clock_t time=clock();
    int curr;

    while(1)
    {
        printf("%s\n","waiting!\n" );
        c_client=accept(s_socket,(struct sockaddr*)&other,&addr_size);
        if(c_client==-1)
        {
            printf("%s\n","error in client Connection\n" );
            exit(1);
        }
        printf("[+] conection accepted from %s:%d\n",inet_ntoa(other.sin_addr),ntohs(other.sin_port)); // print the address and port umber of client connections

        curr=userCount++;
        printf("curr:%d\n",curr );
        usr[curr].client_id=c_client;
        // u[curr].t=time;
        usr[curr].server_id=s_socket;
        strcpy(usr[curr].ip,inet_ntoa(other.sin_addr));
        usr[curr].port=ntohs(other.sin_port);
        pthread_t tid[curr];
        pthread_create(&tid[curr],NULL,runner,&usr[curr]);





    }
    // for(int i=0;i<=curr;i++)
    //     pthread_join(tid[i],NULL);
}
