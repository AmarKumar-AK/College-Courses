// Given three vertices: (x1, y1), (x2, y2) and (x3, y3) of a triangle, and a point p(x, y),
// check if the point p lies inside the triangle.
#include<bits/stdc++.h>
using namespace std;


int check1(float x1,float y1,float x2,float y2,int px,int py){
    float line = ((py-y1) * (x2-x1)) - ((px-x1)*(y2-y1));
    if(line<0){
        return 1;
    }else if(line>0){
        return 0;
    }
    return 0;
}
int check2(float x1,float y1,float x2,float y2,float px,float py){
    float line = ((py-y1) * (x2-x1)) - ((px-x1)*(y2-y1));
    if(line<0){
        return 1;
    }else if(line>0){
        return 0;
    }
    return 0;
}


int main(){
    float x1,x2,x3,y1,y2,y3;;
    int px,py;
    cout<<"enter the co-ordinates of triangle"<<endl;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    cout<<"enter x and y co-ordinate of point P"<<endl;
    cin>>px>>py;

    int first = !(check1(x1,y1,x2,y2,px,py)^check2(x1,y1,x2,y2,x3,y3));
    // cout<<"first : "<<first<<endl;
    int second = !(check1(x1,y1,x3,y3,px,py)^check2(x1,y1,x3,y3,x2,y2));
    // cout<<"second : "<<second<<endl;
    int third = !(check1(x3,y3,x2,y2,px,py)^check2(x3,y3,x2,y2,x1,y1));
    // cout<<"third : "<<third<<endl;
    if( (first + second + third)==3 ){
        cout<<"Point lies inside triangle"<<endl;
    }else{
        cout<<"Point lies outside triangle"<<endl;
    }
}