#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
 #include <arpa/inet.h>
#include <unistd.h>
#include<time.h>


int main()
{
    int s_sock,c_client;
    char buf[100];
    pid_t childpid;       //pid_t data type defines within the types.h header file(it create a childpid for multitasking operation"
    socklen_t addr_size;
    s_sock=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server,other;
    memset(&server,0,sizeof(server));
    server.sin_family=AF_INET;
    server.sin_port=htons(4442); // port is the point of communication between the client and server
    server.sin_addr.s_addr=INADDR_ANY; // Any address means server can host to any client with valid IP


    if(bind(s_sock,(struct sockaddr*)&server,sizeof(server))==-1)
    {
        printf("[+] bind error");
        exit(1);
    }
    printf("[+] server is bind%d\n",4442);
    if(listen(s_sock,10)==0)
    printf("[+] sever listing...");
    while(1) // infinte loop needed to accept the mutliclient connection to a server
    {
        c_client=accept(s_sock,(struct sockaddr*)&other,&addr_size);
        if(c_client==-1)
            exit(1);
        printf("[+] conection accepted from %s,%d\n",inet_ntoa(other.sin_addr),ntohs(other.sin_port)); // print the address and port umber of client connections



        if((childpid=fork())==0)  // child thread creation (if it return zero then terminate the connection or close the socket)
        {
            clock_t time[4],ttime;
            time[0] =clock();
            close(s_sock);
            // while(1) // this infinte loop for maintining the client-server message exchage
            // {
                recv(c_client,buf,sizeof(buf),0);
                bzero(buf,sizeof(buf));
                strcpy(buf,"what is your name?\n1.sp 2.aa 3.sd 4.dsd\nYour Ans.:");
                send(c_client,buf,sizeof(buf),0);


                bzero(buf,sizeof(buf));
                recv(c_client,buf,sizeof(buf),0);
                time[1] =clock();
                printf(":%f\n",(float)time[1]*10000/CLOCKS_PER_SEC );
                // printf("\n%s\n",buf );
                // printf(".%d\n",strcmp(buf,"1") );
                int check=strcmp(buf,"1");
                printf("..%d\n",check );
                if(check)
                {
                    strcpy(buf,"Better luck next time");
                    send(c_client,buf,sizeof(buf),0);
                    bzero(buf,sizeof(buf));
                    // printf("%s\n","");
                    break;
                }

                strcpy(buf,"what is your age?\n1.40 2.23 3.12 4.21\nYour Ans.:");
                send(c_client,buf,sizeof(buf),0);
                time[0] =clock();
                bzero(buf,sizeof(buf));
                recv(c_client,buf,sizeof(buf),0);

                time[2] =clock()-time[0];
                printf(":%f\n",(float)time[2]*10000/CLOCKS_PER_SEC );
                check=strcmp(buf,"4");
                printf("%d\n",check );
                if(check)
                {
                    strcpy(buf,"Better luck next time");
                    send(c_client,buf,sizeof(buf),0);
                    bzero(buf,sizeof(buf));
                    // printf("%s\n","");
                    break;
                }

                strcpy(buf,"what is your branch?\n1.mec 2.ece 3.ces 4.met\nYour Ans.:");
                send(c_client,buf,sizeof(buf),0);
                time[0] =clock();
                bzero(buf,sizeof(buf));
                recv(c_client,buf,sizeof(buf),0);
                time[3] =clock()-time[0];
                printf(":%f\n",(float)time[3]*10000/CLOCKS_PER_SEC );
                check=strcmp(buf,"3");
                printf("%d\n",check );
                if(check)
                {
                    strcpy(buf,"Better luck next time");
                    send(c_client,buf,sizeof(buf),0);
                    bzero(buf,sizeof(buf));
                    // printf("%s\n","");
                    break;
                }

                strcpy(buf,"end");
                send(c_client,buf,sizeof(buf),0);
                strcpy(buf,"thanks");
                bzero(buf,sizeof(buf));
                float avg=((float)time[1]/CLOCKS_PER_SEC+(float)time[1]/CLOCKS_PER_SEC+(float)time[1]/CLOCKS_PER_SEC)/3;
                printf("%f\n",avg*10000 );

                // send(c_client,buf,sizeof(buf),0);
                // bzero(buf,sizeof(buf));recv(c_client,buf,sizeof(buf),0)
                //
                // send(c_client,buf,sizeof(buf),0);
                // bzero(buf,sizeof(buf));recv(c_client,buf,sizeof(buf),0)
                //
                // send(c_client,buf,sizeof(buf),0);
                // bzero(buf,sizeof(buf));recv(c_client,buf,sizeof(buf),0)
                //
                // send(c_client,buf,sizeof(buf),0);
                // bzero(buf,sizeof(buf));recv(c_client,buf,sizeof(buf),0)
                //
                // send(c_client,buf,sizeof(buf),0);
                // bzero(buf,sizeof(buf));recv(c_client,buf,sizeof(buf),0)
                //
                // send(c_client,buf,sizeof(buf),0);
                // bzero(buf,sizeof(buf));recv(c_client,buf,sizeof(buf),0)
                //
                // send(c_client,buf,sizeof(buf),0);
                // bzero(buf,sizeof(buf));recv(c_client,buf,sizeof(buf),0)
                //
                // send(c_client,buf,sizeof(buf),0);
                // bzero(buf,sizeof(buf));recv(c_client,buf,sizeof(buf),0)
                //
                // send(c_client,buf,sizeof(buf),0);
                // bzero(buf,sizeof(buf));recv(c_client,buf,sizeof(buf),0)
                //
                // send(c_client,buf,sizeof(buf),0);
                // bzero(buf,sizeof(buf));recv(c_client,buf,sizeof(buf),0)
                //
                // send(c_client,buf,sizeof(buf),0);
                // bzero(buf,sizeof(buf));recv(c_client,buf,sizeof(buf),0)
                //
                // send(c_client,buf,sizeof(buf),0);
                // bzero(buf,sizeof(buf));recv(c_client,buf,sizeof(buf),0)
                //
                // send(c_client,buf,sizeof(buf),0);
                // bzero(buf,sizeof(buf));recv(c_client,buf,sizeof(buf),0)
                //
                // send(c_client,buf,sizeof(buf),0);
                // bzero(buf,sizeof(buf));recv(c_client,buf,sizeof(buf),0)

                // recv(c_client,buf,sizeof(buf),0);
                // if((buf,"end",3)==0)            //if message from client "end" terminate the client socket
                // break;
                // printf("client msg:%s",buf);
                // send(c_client,buf,sizeof(buf),0);
                // bzero(buf,sizeof(buf)); //clear the buffer every time to receive the new messages (otherwise override will give addtional past stored message)
            // }
        }
    }
    close(s_sock);
    return 0;
}
