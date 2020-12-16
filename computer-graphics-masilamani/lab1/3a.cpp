// Given three vertices: (x1, y1), (x2, y2) and (x3, y3) of a triangle, and a point p(x, y),
// check if the point p lies inside the triangle.
#include<bits/stdc++.h>
using namespace std;

float area(float x1,float y1,float x2,float y2,float x3,float y3){
    return abs((x1*(y2-y3) + x2*(y3-y1) +  x3*(y1-y2))/ 2.0);
}

float tri_area(int x1,int y1,float x2,float y2,float x3,float y3){
    return abs((x1*(y2-y3) + x2*(y3-y1) +  x3*(y1-y2))/ 2.0);
}

bool check(float x1,float y1,float x2,float y2,float x3,float y3,int px,int py) { 

    float ABC_area = area(x1,y1,x2,y2,x3,y3); 
  
    float PAB_area = tri_area(px,py,x1,y1,x2,y2); 
    float PBC_area = tri_area(px,py,x2,y2,x3,y3); 
    float PCA_area = tri_area(px,py,x3,y3,x1,y1); 
    float total_area = PAB_area + PBC_area + PCA_area;
    if(ABC_area == total_area){
        return true;
    }else{
        return false;
    }
} 

int main(){
    float x1,x2,x3,y1,y2,y3;;
    int px,py;
    cout<<"enter the co-ordinates of triangle"<<endl;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    cout<<"enter x and y co-ordinate of point P"<<endl;
    cin>>px>>py;

    if(check(x1,y1,x2,y2,x3,y3,px,py)){
        cout<<"Point lies inside triangle"<<endl;
    }else{
        cout<<"Point lies outside triangle"<<endl;
    }
}