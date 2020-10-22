#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

int main(){
    int s_socket, s_server;
    //char buf[1000]="Connected to the Server!";
    s_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server, other;
    memset(&server, 0, sizeof(server));
    memset(&other, 0, sizeof(other));

    server.sin_family = AF_INET;
    server.sin_port=htons(5151);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(s_socket, (struct sockaddr*)&server, sizeof(server));
    listen(s_socket,5);
    socklen_t add;
    add = sizeof(other);
    s_server = accept(s_socket, (struct sockadddr*)&other, &add);







    return 0;
}