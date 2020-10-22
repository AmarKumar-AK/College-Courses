#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
int main()
{
//   int binToDec(int a)
//   {
//     int num=a ;
//     int dec_value = 0;
//     // Initializing base value to 1, i.e 2^0
//     int base = 1;
//     int temp = num;
//     while (temp) {
//         int last_digit = temp % 10;
//         temp = temp / 10;
//         dec_value += last_digit * base;
//         base = base * 2;
//     }
//     return dec_value;
//   }

//   void decToBinary(int n)
//   {
//     // array to store binary number
//     int binaryNum[32];
//     // counter for binary array
//     int i = 0;
//     while (n > 0) {
//         // storing remainder in binary array
//         binaryNum[i] = n % 2;
//         n = n / 2;
//         i++;
//     }

//     // printing binary array in reverse order
//     for (int j = i - 1; j >= 0; j--)
//         printf("%d",binaryNum[j]);
//   }
//   int key=13;




  int s_socket,s_server;
  char buf[100];
  s_socket=socket(AF_INET, SOCK_STREAM,0);
  struct sockaddr_in server, other;
  memset(&server,0,sizeof(server));
  memset(&other,0,sizeof(other));
  server.sin_family=AF_INET;
  server.sin_port=htons(4548);
  server.sin_addr.s_addr=INADDR_ANY;
  bind(s_socket,(struct sockaddr*)&server,sizeof(server));
  listen(s_socket,5);
  socklen_t add;
  add=sizeof(other);
  s_server=accept(s_socket,(struct sockaddr*)&other,&add);



  
  char data[32],key[32];
  recv(s_server,data,sizeof(data),0);
  printf("data received is %s\n",data);
// for error
data[1]='1';
//   if(data[0]=='0'){
//       data[0]='1';
//   }
//   else{
//       data[0]=='0';
//   }
  printf("enter key : ");
  scanf("%s",key);

  int k[strlen(key)];
  for(int i=0;i<strlen(key);i++)
        k[i]=key[i]-48;
  int d[strlen(data)];
  for(int i=0;i<strlen(data);i++){
            d[i]=data[i]-48;

  }
  
  
  int l=0;
  for(int i=0;i<(strlen(data)-strlen(key)+1);i++)
    {

        if(d[i]==1)
        {
            for(int j=i;j<i+strlen(key);j++)
            {
                // printf("%d:%d\n",d[i],k[l] );
                d[j]=d[j]^k[l];
                l++;
            }
            l=0;
            // for(int ii=0;ii<strlen(data);ii++)
            //     printf("%d",d[ii]);
            // printf("\n");


        }
    }
    int flag=0;
    for(int k=0 ; k<strlen(key)-1 ; ++k ){
        if(d[strlen(data)-k-1]!=0 ){
            flag=1;
            printf("error\n");
            break;
        }
    }
    if(flag==0){
        send(s_server,"no error in data",sizeof("no error in data"),0);
    }
    else{
        send(s_server,"error in data",sizeof("error in data"),0);
    }
  // printf("client--\t%s\n",buf);
//   if((binToDec(store)%key)==0)
//   {
//     char err[10]="No_error";
//     send(s_server,err,sizeof(err),0);
//   } else {
//     char err[10]="Error";
//     send(s_server,err,sizeof(err),0);
//     }


  close(s_server);
  return 0;



}







// int func()
// {
//     char data[32],key[32];
//     scanf("%s%s",data,key);
//     for(int i=0;i<strlen(key)-1;i++)
//     {
//         strcat(data,"0");
//     }
//     int d[strlen(data)],k[strlen(key)];
//     int dnew[strlen(data)];
//     for(int i=0;i<strlen(data);i++)
//         {
//             d[i]=data[i]-48;
//             dnew[i]=d[i];
//         }
//     for(int i=0;i<strlen(key);i++)
//         k[i]=key[i]-48;

//     int l=0;
//     for(int i=0;i<(strlen(data)-strlen(key)+1);i++)
//     {

//         if(d[i]==1)
//         {
//             for(int j=i;j<i+strlen(key);j++)
//             {
//                 printf("%d:%d\n",d[i],k[l] );
//                 d[j]=d[j]^k[l];
//                 l++;
//             }
//             l=0;
//             for(int ii=0;ii<strlen(data);ii++)
//                 printf("%d",d[ii]);
//             printf("\n");


//         }


//     }

//     int itr = strlen(data)-1;
//     for(int jj=strlen(data)-1;jj>strlen(data)-strlen(key);jj--)
//         {
//             dnew[jj]=d[jj];

//         }
//         for(int i=0;i<strlen(data);i++)
//             printf("%d",d[i]);
//         printf("\n");
//         for(int i=0;i<strlen(data);i++)
//             printf("%d",dnew[i]);
//         printf("\n");


// }

