#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

int main(){
    int c_sock;
    char buf[100];
    c_sock = socket(AF_INET, SOCK_STREAM,0);
    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_port = htons(9000);
    // client.sin_addr.s_addr = INADDR_ANY;
    client.sin_addr.s_addr = inet_addr("172.16.18.90");
    if(connect(c_sock,(struct sockaddr*)&client,sizeof(client))==-1)
    {
        printf("connection error");
        exit(1);
    }


    FILE *fp;
    fp = fopen("text.txt", "r");
    fscanf(fp, "%s",buf);
    write(c_sock, buf, sizeof(buf));
    printf("file send succesfully");
    fclose(fp);
    close(c_sock);
    return(0);
}