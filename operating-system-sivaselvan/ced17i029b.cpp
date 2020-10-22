/************************************************
 * Develop an application that simulates the behaviour
 * of the linux command diff to compare two files
 * *********************************************/
#include<bits/stdc++.h>
#include<fstream>
#include<sys/types.h>
#include<unistd.h>
using namespace std;
int main(){
    string a,b;
    cout<<"enter the name of files"<<endl;
    cin>>a>>b;
    string s="diff ";
    s=s+a+" "+b;
    const char *command=s.c_str();
    system(command);
}