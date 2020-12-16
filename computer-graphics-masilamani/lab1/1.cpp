// Given four corners of a rectangle, and also a point p, check if p lies inside the rectangle
#include<bits/stdc++.h>
using namespace std;

float area(float x1,float y1,float x2,float y2,float x3,float y3){
    return abs((x1*(y2-y3) + x2*(y3-y1) +  x3*(y1-y2))/ 2.0);
}

float tri_area(int x1,int y1,float x2,float y2,float x3,float y3){
    return abs((x1*(y2-y3) + x2*(y3-y1) +  x3*(y1-y2))/ 2.0);
}

bool check(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,int px,int py) { 

    float rect_area = area(x1,y1,x2,y2,x3,y3) +  area(x1,y1,x3,y3,x4,y4); 
  
    float PAB_area = tri_area(px,py,x1,y1,x2,y2); 
    float PBC_area = tri_area(px,py,x2,y2,x3,y3); 
    float PCD_area = tri_area(px,py,x3,y3,x4,y4); 
    float PAD_area = tri_area(px,py,x1,y1,x4,y4); 
    float total_area = PAB_area + PBC_area + PCD_area + PAD_area;
    if(rect_area == total_area){
        return true;
    }else{
        return false;
    }
} 

int main(){
    float x1,x2,x3,x4,y1,y2,y3,y4;
    int px,py;
    cout<<"enter the co-ordinates of rectangle"<<endl;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    
    cout<<"enter x and y co-ordinate of point P"<<endl;
    cin>>px>>py;

    if(check(x1,y1,x2,y2,x3,y3,x4,y4,px,py)){
        cout<<"Point lies inside rectangle"<<endl;
    }else{
        cout<<"Point lies outside rectangle"<<endl;
    }
}