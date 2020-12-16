// Given two points (x1, y1) and (x2, y2) of a line, and also a point p (x, y),
// check if p lies below or above  or on  the line
#include<bits/stdc++.h>
using namespace std;


int check(float x1,float y1,float x2,float y2,int px,int py){
    float line = ((py-y1) * (x2-x1)) - ((px-x1)*(y2-y1));
    if(line<0){
        cout<<"point P lies below the line"<<endl;
    }else if(line>0){
        cout<<"point P lies above the line"<<endl;
    }else{
        cout<<"point P lies on the line"<<endl;
    }
    return 0;
}


int main(){
    float x1,y1,x2,y2;
    int px,py;
    cout<<"enter co-ordinates of two points of a line"<<endl;
    cin>>x1>>y1>>x2>>y2;
    cout<<"enter x and y co-ordinate of point P"<<endl;
    cin>>px>>py;
    check(x1,y1,x2,y2,px,py);
}