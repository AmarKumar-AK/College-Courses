/************************************************
 * Develop an application that first lists all the
 * processes running on the system, then searches
 * for a particular pattern (key) among the previous
 * process list returned and finally display the
 * results from the search task in all CAPITALS.
 * (cannot use pipes at command line)
************************************************/
#include<bits/stdc++.h>
#include<fstream>
#include<sys/types.h>
#include<unistd.h>
using namespace std;
int main(){
    cout<<"list of all process running on the system"<<endl;
    system("ps -e");
    //a.txt contains output of "ps -e" command
    system("ps -e>a.txt");

    fstream file;
    file.open("a.txt");
    string w,x,y,z;
    //a,b,c,d is storing PID(process id), TTY, TIME, CMD(process name) respectively 
    string a[1000],b[1000],c[1000],d[1000];
    int i=0;
    while(!file.eof()){
        file>>w>>x>>y>>z;
        a[i]=w;
        b[i]=x;
        c[i]=y;
        d[i]=z;
        ++i;
    }

    ofstream out;
    //b.txt contains process name
    out.open("b.txt");
    for(int k=1 ; k<i ; ++k){
        //writing process name to the file "b.txt"
        out<<d[k]<<endl;
    }
    string pattern;
    cout<<endl<<endl<<"enter the pattern to search in process list"<<endl;
    cin>>pattern;


    string s="grep -i ";
    s=s+pattern+" b.txt";
    const char *command1=s.c_str();
    

    cout<<endl<<endl<<"searching a pattern "<<pattern <<" among process list"<<endl;
    system(command1);

    
    string upp="grep -i ";
    upp=upp+pattern+" b.txt | tr [:lower:] [:upper:]";
    const char *command2=upp.c_str();

    
    cout<<endl<<"changing searched task in all CAPITALS"<<endl;
    system(command2);
    
    file.close();
    out.close();
    return 0;
}