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


};


void * runner(void * par)
{

    struct User* u=par;
    int c_client=u->client_id;
    // close(u->server_id);
    // char buf[1024];
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
    int userCount=0;
    if(bind(s_socket,(struct sockaddr*)&server,sizeof(server))==-1)
    {
        printf("%s\n","[-]Bind error" );
        exit(1);
    }

    if(listen(s_socket,10)==0)
        printf("[+] sever listing...");

    struct User u[10];
    pthread_t tid[10];
    // clock_t ctime;
    // clock_t time=clock();
    int curr;

    while(1)
    {
        printf("%s\n","waiting!\n" );
        c_client=accept(s_socket,(struct sockaddr*)&other,&addr_size);

        // if((ctime=clock()-time)*10000/CLOCKS_PER_SEC>10)
        // {
        //     strcpy(buf,"timesUp!");
        //     send(c_client,buf,sizeof(buf),0);
        //     // close(c_client);
        //
        //     START=1;
        //
        // }
        // printf("you joined at %f\n",(float)ctime/CLOCKS_PER_SEC );
        if(c_client==-1)
        {
            printf("%s\n","error in client Connection\n" );
            exit(1);
        }
        printf("[+] conection accepted from %s:%d\n",inet_ntoa(other.sin_addr),ntohs(other.sin_port)); // print the address and port umber of client connections

        curr=userCount++;
        printf("curr:%d\n",curr );
        u[curr].client_id=c_client;
        // u[curr].t=time;
        u[curr].server_id=s_socket;
        pthread_t tid[curr];
        pthread_create(&tid[curr],NULL,runner,&u[curr]);





    }
    for(int i=0;i<=curr;i++)
        pthread_join(tid[i],NULL);
}




























// struct ranklist
// {
//         int client;
//         int rank;
//         float average;
// };
//
// void * kbc(void * argv )
// {
//     // clock_t time[4],ttime;
//     // time[0] =clock();
//         close(s_sock);
//     // while(1) // this infinte loop for maintining the client-server message exchage
//     // {
//         strcpy(r[uc].ip,inet_ntoa(other.sin_addr));
//         r[uc].rank=0;
//         recv(c_client,buf,sizeof(buf),0);
//
//         bzero(buf,sizeof(buf));
//         strcpy(buf,"what is your name?\n1.sp 2.aa 3.sd 4.dsd\nYour Ans.:");
//         send(c_client,buf,sizeof(buf),0);
//
//
//         bzero(buf,sizeof(buf));
//         recv(c_client,buf,sizeof(buf),0);
//         // time[1] =clock();
//         // printf(":%f\n",(float)time[1]*10000/CLOCKS_PER_SEC );
//         // printf("\n%s\n",buf );
//         // printf(".%d\n",strcmp(buf,"1") );
//         int check=strcmp(buf,"1");
//         printf("..%d\n",check );
//         if(check)
//         {
//             strcpy(buf,"Better luck next time");
//             send(c_client,buf,sizeof(buf),0);
//             bzero(buf,sizeof(buf));
//             // printf("%s\n","");
//             break;
//         }
//
//
//         strcpy(buf,"what is your age?\n1.40 2.23 3.12 4.21\nYour Ans.:");
//         send(c_client,buf,sizeof(buf),0);
//         // time[0] =clock();
//         bzero(buf,sizeof(buf));
//         recv(c_client,buf,sizeof(buf),0);
//
//         // time[2] =clock()-time[0];
//         // printf(":%f\n",(float)time[2]*10000/CLOCKS_PER_SEC );
//         check=strcmp(buf,"4");
//         printf("%d\n",check );
//         if(check)
//         {
//             strcpy(buf,"Better luck next time");
//             send(c_client,buf,sizeof(buf),0);
//             bzero(buf,sizeof(buf));
//             // printf("%s\n","");
//             break;
//         }
//
//         strcpy(buf,"what is your branch?\n1.mec 2.ece 3.ces 4.met\nYour Ans.:");
//         send(c_client,buf,sizeof(buf),0);
//         // time[0] =clock();
//         bzero(buf,sizeof(buf));
//         recv(c_client,buf,sizeof(buf),0);
//         // time[3] =clock()-time[0];
//         // printf(":%f\n",(float)time[3]*10000/CLOCKS_PER_SEC );
//         chec5053k=strcmp(buf,"3");
//         printf("%d\n",check );
//         if(check)
//         {
//             strcpy(buf,"Better luck next time");
//             send(c_client,buf,sizeof(buf),0);
//             bzero(buf,sizeof(buf));
//             // printf("%s\n","");
//             break;
//         }
//
//         strcpy(buf,"end");
//         send(c_client,buf,sizeof(buf),0);
//         bzero(buf,sizeof(buf));
//         float aa=0;//average from client
//         recv(c_client,&aa,sizeof(aa),0);
//         printf("avg::%f\n",aa );
//         r[uc].value=aa;
//
//         // while(r[uc].rank==0);
//         int rankk=r[uc].rank;
//         printf("%d\n",rankk );
//         send(c_client,&rankk,sizeof(rankk),0);
//         // printf("\nRank:%d\n",r[uc].rank);
//
//
//
//         // float avg=((float)time[1]/CLOCKS_PER_SEC+(float)time[1]/CLOCKS_PER_SEC+(float)time[1]/CLOCKS_PER_SEC)/3;
//         // printf("%f\n",avg*10000 );
//
//         exit(1);
// }
//
// int main()
// {
//     int s_sock,c_client;
//     char buf[100];
//     pid_t childpid;       //pid_t data type defines within the types.h header file(it create a childpid for multitasking operation"
//     socklen_t addr_size;
//     s_sock=socket(AF_INET,SOCK_STREAM,0);
//     struct sockaddr_in server,other;
//     memset(&server,0,sizeof(server));
//     server.sin_family=AF_INET;
//     server.sin_port=htons(5053); // port is the point of communication between the client and server
//     server.sin_addr.s_addr=INADDR_ANY; // Any address means server can host to any client with valid IP
//     int total=10;
//     struct ranklist r[total];
//     int userCount=0;
//     pthread_t tid[total];
//
//     if(bind(s_sock,(struct sockaddr*)&server,sizeof(server))==-1)
//     {
//         printf("[+] bind error");
//         exit(1);
//     }
//     printf("[+] server is bind%d\n",5053);
//     if(listen(s_sock,10)==0)
//     printf("[+] sever listing...");
//     clock_t time =clock(),ctime;
//
//     while(1) // infinte loop needed to accept the mutliclient connection to a server
//     {
//
//         printf("time@ %f\n",((float)(ctime=clock()-time)*10000/CLOCKS_PER_SEC));
//         c_client=accept(s_sock,(struct sockaddr*)&other,&addr_size);
//
//         // pthread_create(&tid, NULL, myThreadFun, );
//         // printf("%s\n","xxxx\n   " );
//
//
//
//         if(((ctime=clock()-time)*10000/CLOCKS_PER_SEC)>10)
//         {
//             strcpy(buf,"timesUp!");
//             send(c_client,buf,sizeof(buf),0);
//             // close(c_client);
//             exit(1);
//         }
//         if(c_client==-1)
//             {
//                 printf("%s\n","errorn in ..\n   " );
//                 exit(1);
//             }
//         printf("[+] conection accepted from %s,%d\n",inet_ntoa(other.sin_addr),ntohs(other.sin_port)); // print the address and port umber of client connections
//         int uc=(userCount++);
//         r[uc].client=c_client;
//         pthread_create(&tid, NULL, myThreadFun, &r[uc]);
//
//         if((childpid=fork())==0)  // child thread creation (if it return zero then terminate the connection or close the socket)
//         {
//
//             // clock_t time[4],ttime;
//             // time[0] =clock();
//                 close(s_sock);
//             // while(1) // this infinte loop for maintining the client-server message exchage
//             // {
//                 strcpy(r[uc].ip,inet_ntoa(other.sin_addr));
//                 r[uc].rank=0;
//                 recv(c_client,buf,sizeof(buf),0);
//
//                 bzero(buf,sizeof(buf));
//                 strcpy(buf,"what is your name?\n1.sp 2.aa 3.sd 4.dsd\nYour Ans.:");
//                 send(c_client,buf,sizeof(buf),0);
//
//
//                 bzero(buf,sizeof(buf));
//                 recv(c_client,buf,sizeof(buf),0);
//                 // time[1] =clock();
//                 // printf(":%f\n",(float)time[1]*10000/CLOCKS_PER_SEC );
//                 // printf("\n%s\n",buf );
//                 // printf(".%d\n",strcmp(buf,"1") );
//                 int check=strcmp(buf,"1");
//                 printf("..%d\n",check );
//                 if(check)
//                 {
//                     strcpy(buf,"Better luck next time");
//                     send(c_client,buf,sizeof(buf),0);
//                     bzero(buf,sizeof(buf));
//                     // printf("%s\n","");
//                     break;
//                 }
//
//
//                 strcpy(buf,"what is your age?\n1.40 2.23 3.12 4.21\nYour Ans.:");
//                 send(c_client,buf,sizeof(buf),0);
//                 // time[0] =clock();
//                 bzero(buf,sizeof(buf));
//                 recv(c_client,buf,sizeof(buf),0);
//
//                 // time[2] =clock()-time[0];
//                 // printf(":%f\n",(float)time[2]*10000/CLOCKS_PER_SEC );
//                 check=strcmp(buf,"4");
//                 printf("%d\n",check );
//                 if(check)
//                 {
//                     strcpy(buf,"Better luck next time");
//                     send(c_client,buf,sizeof(buf),0);
//                     bzero(buf,sizeof(buf));
//                     // printf("%s\n","");
//                     break;
//                 }
//
//                 strcpy(buf,"what is your branch?\n1.mec 2.ece 3.ces 4.met\nYour Ans.:");
//                 send(c_client,buf,sizeof(buf),0);
//                 // time[0] =clock();
//                 bzero(buf,sizeof(buf));
//                 recv(c_client,buf,sizeof(buf),0);
//                 // time[3] =clock()-time[0];
//                 // printf(":%f\n",(float)time[3]*10000/CLOCKS_PER_SEC );
//                 check=strcmp(buf,"3");
//                 printf("%d\n",check );
//                 if(check)
//                 {
//                     strcpy(buf,"Better luck next time");
//                     send(c_client,buf,sizeof(buf),0);
//                     bzero(buf,sizeof(buf));
//                     // printf("%s\n","");
//                     break;
//                 }
//
//                 strcpy(buf,"end");
//                 send(c_client,buf,sizeof(buf),0);
//                 bzero(buf,sizeof(buf));
//                 float aa=0;//average from client
//                 recv(c_client,&aa,sizeof(aa),0);
//                 printf("avg::%f\n",aa );
//                 r[uc].value=aa;
//
//                 // while(r[uc].rank==0);
//                 int rankk=r[uc].rank;
//                 printf("%d\n",rankk );
//                 send(c_client,&rankk,sizeof(rankk),0);
//                 // printf("\nRank:%d\n",r[uc].rank);
//
//
//
//                 // float avg=((float)time[1]/CLOCKS_PER_SEC+(float)time[1]/CLOCKS_PER_SEC+(float)time[1]/CLOCKS_PER_SEC)/3;
//                 // printf("%f\n",avg*10000 );
//
//                 exit(1);
//         }
//     }
//     close(s_sock);
//
//     return 0;
// }
