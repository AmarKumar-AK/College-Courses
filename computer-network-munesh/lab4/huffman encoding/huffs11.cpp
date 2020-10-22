#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
using namespace std;
int beg=-1,END=-1;
int etend,encodedtext[1000];


int s_server;
int s_socket=socket(AF_INET, SOCK_STREAM,0);
struct sockaddr_in server, other;

struct node
{
	char c;
	int freq;
	node *lcptr;
	node *rcptr;
	int encode[10];
}n[10];
node *hptr;

int ltable[128][10];

class huffman
{
	//char text[100];
	//int encodedtext[1000];
	//int etend;
	public:
		void read();
		void htree();
		void code(struct node *ptr,int arr[],int top);
		void printencodedtext();
		void decode();
};

bool freqsort(node n1,node n2)
{
	return(n1.freq<n2.freq);
}

void huffman::htree()
{
	while(END-beg>0)
	{
		sort(n+beg,n+(END+1),freqsort);
		END++;
		n[END].freq=n[beg].freq+n[beg+1].freq;
		n[END].c='\0';
		for(int i=0;i<10;i++)
			n[END].encode[i]=-666;
		n[END].lcptr=&n[beg];
		n[END].rcptr=&n[beg+1];
		beg+=2;
	}
	hptr=&n[beg];  //beg=END

}

void huffman::code(struct node *ptr,int arr[],int top)
{
	if(ptr->lcptr)
	{	arr[top]=0;
		code(ptr->lcptr,arr,top+1);
	}

	if(ptr->rcptr)
	{
		arr[top]=1;
		code(ptr->rcptr,arr,top+1);
	}

	if(ptr->lcptr==NULL && ptr->rcptr==NULL)
	{
		for(int i=0;i<top;i++)
			ptr->encode[i]=arr[i];
	}


}

void huffman::decode()
{
	struct node *ptr=hptr;

	for(int i=0;i<etend;i++)
	{
		if(encodedtext[i]==0)
		{
			ptr=ptr->lcptr;
		}
		else
		{
			ptr=ptr->rcptr;
		}
		if(ptr->lcptr==NULL && ptr->rcptr==NULL)
		{
			cout<<ptr->c;
			ptr=hptr;
		}

	}

}

void print(struct node *ptr)
{
 if(ptr!=NULL)
 {
 	print(ptr->lcptr);
 	cout<<ptr->c<<"---"<< ptr->freq<<"---";
 	for(int i=0;i<10;i++)
 	{
 		ltable[(int)ptr->c][i]=ptr->encode[i];
 		if(ptr->encode[i]!=-666)
 			cout<<ptr->encode[i];
 		else
 			break;
 	}
 	cout<<endl;
 	print(ptr->rcptr);
 }
}

void printlookup()
{
	int i,j;
	for(i=0;i<128;i++)
	{
		for(j=0;j<10;j++)
			if(ltable[i][j]!=-666)
				cout<<ltable[i][j];
		cout<<" ";
	}
	cout<<endl;

}
int main()
{

  memset(&server,0,sizeof(server));
  memset(&other,0,sizeof(other));
  server.sin_family=AF_INET;
  server.sin_port=htons(9009);
  server.sin_addr.s_addr=INADDR_ANY;
  bind(s_socket,(struct sockaddr*)&server,sizeof(server));
  listen(s_socket,5);
  socklen_t add;
  add=sizeof(other);
  s_server=accept(s_socket,(struct sockaddr*)&other,&add);
  cout<<"Connection Accepted"<<endl;

	bzero(&beg,sizeof(beg));
	recv(s_server,&beg,sizeof(beg),0);
	//cout<<"beg: "<<beg<<endl;
	bzero(&END,sizeof(END));
	recv(s_server,&END,sizeof(END),0);
	//cout<<"end: "<<END<<endl;

  bzero(&etend,sizeof(etend));
  recv(s_server,&etend,sizeof(etend),0);
  //cout<<"etend recieved: "<<etend<<endl;
  bzero(&encodedtext,sizeof(encodedtext));
  recv(s_server,&encodedtext,sizeof(encodedtext),0);
	cout<<"Received Encoded Text: ";
  for(int i=0;i<etend;i++)
    cout<<encodedtext[i];
  cout<<endl;

  bzero(&n,sizeof(n));
  recv(s_server,&n,sizeof(n),0);
  // for(int i=0;i<10;i++)
  // {
  //   cout<<n[i].c<<" "<<n[i].freq<<endl;
  // }


 for(int i=0;i<128;i++)
	{
		for(int j=0;j<128;j++)
			ltable[i][j]=-666;
	}

	int a[10];
	huffman h;

	h.htree();
	h.code(hptr,a,0);
	//print(hptr);
	//cout<<"----------------------"<<endl;
	//printlookup();
	//cout<<endl;
	cout<<"Decoded Text: ";
  h.decode();
	cout<<endl;
  close(s_socket);
}
