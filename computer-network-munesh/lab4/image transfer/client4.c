#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

int main(){
    int c_socket;
    //char buf[1000] = "Client Connected!";
    c_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in client;
    memset(&client, 0, sizeof(client));
    client.sin_family = AF_INET;
    client.sin_port=htons(9009);
    client.sin_addr.s_addr = INADDR_ANY;
    if(connect(c_socket,(struct sockaddr*)&client,sizeof(client))==-1){
        printf("Connect issue");
        return 0;
    }
    //recv(c_socket,buf,sizeof(buf),0);
    //printf("Msg from server: %s\n",buf);
    
    FILE *fp;
    char c;

    fp = fopen("M.BMP", "rb");
    for(int i=0 ; i<4264316 ; ++i){
    	c=fgetc(fp);
    	send(c_socket,&c,sizeof(c),0);
    }



    close(c_socket);
    return 0;
}
