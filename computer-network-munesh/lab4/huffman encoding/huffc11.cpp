#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
using namespace std;
int beg=-1,END=-1;
int c_socket;
struct node
{
	char c;
	int freq;
	node *lcptr;
	node *rcptr;
	int encode[10];
}n[10],n1[10];
node *hptr;

int ltable[128][10];

class huffman
{
	char text[100];
	int encodedtext[1000];
	int etend;
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

void huffman::read()
{
	cout<<"Enter the text\n";
	cin>>text;
	int i,j,check=0;
	for(i=0;i<strlen(text);i++)
	{
		check=0;
		for(j=0;j<=END;j++)
		{
			if(n[j].c==text[i])
			{
				n[j].freq++;				n1[j].freq++;
				check=1;
				break;
			}
		}
		if(beg==-1)
			beg=0;
		if(check==0)
		{
			END++;
			n[END].c=text[i];n1[END].c=text[i];
			n[END].freq=1;n1[END].freq=1;
			n[END].lcptr=NULL;n1[END].lcptr=NULL;
			n[END].rcptr=NULL;n1[END].rcptr=NULL;
			for(int i=0;i<10;i++)
			{	n[END].encode[i]=-666;n1[END].encode[i]=-666;
			}
		}
	}
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

void huffman::printencodedtext()
{
	int i=0,j=0,k=0;
	for(;i<1000;i++)
		encodedtext[i]=-666;
	cout<<"Given text:\t"<<text<<endl<<"Encoded text:\t";
	i=0;
	while(i<strlen(text))
	{
		for(j=0;j<10;j++)
			if(ltable[(text[i])][j]!=-666)
			{	cout<<ltable[(text[i])][j];
				encodedtext[k]=ltable[(text[i])][j];
				k++;
			}
		i++;
	}
	cout<<endl;
	send(c_socket,&k,sizeof(k),0);
	send(c_socket,&encodedtext,sizeof(encodedtext),0);

	etend=k;
	cout<<endl;
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
 	cout<<ptr->c<<":";
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


  // int ch,d;
  // float a,b,c;
  char buf[100];
  c_socket=socket(AF_INET, SOCK_STREAM,0);
  struct sockaddr_in client;
  memset(&client,0,sizeof(client));
  client.sin_family=AF_INET;
  client.sin_port=htons(9009);
  client.sin_addr.s_addr=inet_addr("192.168.43.104");
  if(connect(c_socket,(struct sockaddr*)&client,sizeof(client))==-1)
  {
      printf("Error in connection");
      return 0;
  }












	for(int i=0;i<128;i++)
	{
		for(int j=0;j<128;j++)
			ltable[i][j]=-666;
	}

	int a[10];
	huffman h;
	h.read();
	send(c_socket,&beg,sizeof(beg),0);
	send(c_socket,&END,sizeof(END),0);
	h.htree();
	h.code(hptr,a,0);
	print(hptr);
	//cout<<"----------------------"<<endl;
	//printlookup();
	//cout<<endl;
	h.printencodedtext();

	send(c_socket,&n1,sizeof(n1),0);
	cout<<"msg Sent!!"<<endl;
	//h.decode();
	cout<<endl;

}
