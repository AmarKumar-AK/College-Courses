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
    // string a,b;
    // cout<<"enter the name of files"<<endl;
    // cin>>a>>b;
    // string s="diff ";
    // s=s+a+" "+b;
    // const char *command=s.c_str();
    // system(command);
    ifstream file1("1.txt");
    ifstream file2("2.txt");
    string str1,str2;
    while (getline(file1, str1) && getline(file2,str2)) {
        if(str1!=str2){
            cout<<"1.txt -> "<<str1<<endl;
            cout<<"2.txt -> "<<str2<<endl;
            cout<<endl;
        }
    }
}