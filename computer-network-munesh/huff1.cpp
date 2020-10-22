#include<bits/stdc++.h>
#define SIZE 5
using namespace std;
struct node
{
    char ch;
    int freq;
    struct node *left,*right;
    string encode;
};
void read();
void print(struct node*);
void code(struct node*,string);
void huffman();
// vector<int>vecf;
int sizes=SIZE;

struct node nod[SIZE+SIZE];
struct node *head=NULL;
////////////////////////////////////////////
void read()
{
    ifstream infile("file.txt");
    char c; int count,z=0;
    for(char ch='a'; ch<='z'; ch++)
    {
        count=0;
        while(!infile.eof())
        {
            infile.get(c);
            if(c==ch)  count++;
        }
        if(count>0) 
        {
            nod[z].ch=ch;  nod[z].freq=count;   ++z;    //vecf.push_back(count);
        }
        infile.clear();
        infile.seekg(0);
    }
    for(int i=0 ; i<SIZE ; ++i)
    {
        cout<<nod[i].ch<<" : "<<nod[i].freq<<endl;
    }
}
////////////////////////////////////////////

void code(struct node *head,string arr)
{   
    if(head!=NULL)
    {
        if(head->left!=NULL)
        {
            code(head->left,arr+'0');
        }
        if(head->right!=NULL)
        {
            code(head->right,arr+'1');
        }
        if(head->left==NULL && head->right==NULL)
        {   
             head->encode=arr;
        }
        
    }
    // for(int i=0 ; i<size ; ++i)
    // {
    //     cout<<nod[i].ch<<"--> "<<nod[i].freq<<endl;
    // }
}
///////////////////////////////////////////
void sorting(int size)
{
    for(int i=1 ; i<size ; ++i)
    {
        for(int j=i ; j>0 ; --j)
        {
            if(nod[j].freq<nod[j-1].freq)
            {
                swap(nod[j].freq,nod[j-1].freq);
                swap(nod[j].ch,nod[j-1].ch);
            }
            // if(vecf[j]<vecf[j-1])
            // {
            //     swap(vecf[j],vecf[j-1]);
            // }
        }
    }
}
///////////////////////////////////////////
void huffman()
{
    int i=0,j=SIZE-1,sum;
    int beg=i;
    int end=j;
    
    while(beg<end-1)
    {
        sorting(sizes);
        beg=i;
        end=j;
        //cout<<"nod[i] : "<<nod[i].freq<<endl<<"nod[i+1] : "<<nod[i+1].freq<<endl;
        sum=nod[i].freq+nod[i+1].freq;
        nod[sizes].freq=sum;
        nod[sizes].left=&nod[i];
        //cout<<"nodeleftfreq  "<<nod[sizes].left->freq<<endl;
        nod[sizes].right=&nod[i+1];
        //cout<<"noderightfreq  "<<nod[sizes].right->freq<<endl;
        nod[sizes].ch=' ';
        head=&nod[sizes];
        //cout<<"head  "<<head->freq<<endl;
        head->left=nod[sizes].left;
        //cout<<"headleft  "<<head->left->freq<<endl;
        head->right=nod[sizes].right;
        //cout<<"headright  "<<head->right->freq<<endl;
        i=i+2;
        j=j+1;
        sizes=sizes+1;
    }
    //cout<<"head : "<<head->left->freq<<endl;
    string arr;
    code(head,arr);
    
    

}
//////////////////////////////////////////
void print(struct node *head)
{
   if(head!=NULL)
   {
    if(head->left)
        print(head->left);
    cout<<head->ch<<"-"<<head->encode<<endl;
    if(head->right)
        print(head->right);

   }
  

}
int main()
{
    read();
    huffman();
    cout<<endl;
    print(head);
   
}