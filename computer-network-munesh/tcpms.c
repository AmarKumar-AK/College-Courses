#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
 #include <arpa/inet.h>
#include <unistd.h>

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
printf("[+] conection accepted from %s,%d",inet_ntoa(other.sin_addr),ntohs(other.sin_port)); // print the address and port umber of client connections 
if((childpid=fork())==0)  // child thread creation (if it return zero then terminate the connection or close the socket)
{
close(s_sock); 
while(1) // this infinte loop for maintining the client-server message exchage 
{
recv(c_client,buf,sizeof(buf),0);
if((buf,"end",3)==0)            //if message from client "end" terminate the client socket
break;
printf("client msg:%s",buf);
send(c_client,buf,sizeof(buf),0);
bzero(buf,sizeof(buf)); //clear the buffer every time to receive the new messages (otherwise override will give addtional past stored message)
}
}
}
close(s_sock);
return 0;
}
