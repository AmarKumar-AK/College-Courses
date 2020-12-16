// Given three vertices: (x1, y1), (x2, y2) and (x3, y3) of a triangle,
// find integer coordinates of all points inside or on the triangle
#include<bits/stdc++.h>
using namespace std;

float area(float x1,float y1,float x2,float y2,float x3,float y3){
    return abs((x1*(y2-y3) + x2*(y3-y1) +  x3*(y1-y2))/ 2.0);
}

float tri_area(int x1,int y1,float x2,float y2,float x3,float y3){
    return abs((x1*(y2-y3) + x2*(y3-y1) +  x3*(y1-y2))/ 2.0);
}

int printPoints(float x1,float y1,float x2,float y2,float x3,float y3) { 
    
    vector <float>vx,vy;
    vx.push_back(x1);
    vx.push_back(x2);
    vx.push_back(x3);
    vy.push_back(y1);
    vy.push_back(y2);
    vy.push_back(y3);
    int min_range_x = floor(*min_element(vx.begin(),vx.end()));
    int max_range_x = ceil(*max_element(vx.begin(),vx.end()));
    int min_range_y = floor(*min_element(vy.begin(),vy.end()));
    int max_range_y = ceil(*max_element(vy.begin(),vy.end()));
    cout<<"range_x : "<<min_range_x<<" "<<max_range_x<<endl;
    cout<<"range_y : "<<min_range_y<<" "<<max_range_y<<endl;

    float ABC_area = area(x1,y1,x2,y2,x3,y3);

    for(int i = min_range_x ; i <= max_range_x ; ++i){
        for(int j = min_range_y ; j <= max_range_y ; ++j){
            float PAB_area = tri_area(i,j,x1,y1,x2,y2); 
            float PBC_area = tri_area(i,j,x2,y2,x3,y3); 
            float PCA_area = tri_area(i,j,x3,y3,x1,y1); 
            float total_area = PAB_area + PBC_area + PCA_area;
            if(ABC_area == total_area){
                cout<<"i : "<<i<<" j : "<<j<<endl;
            }
        }
    }
     
    return 0;
    
} 

int main(){

    float x1,x2,x3,y1,y2,y3;;
    cout<<"enter the co-ordinates of triangle"<<endl;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    printPoints(x1,y1,x2,y2,x3,y3);
}