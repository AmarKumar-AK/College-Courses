#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int xp,yp;
    int x1,x2,y1,y2,px,py;
    scanf("(%d,%d) (%d,%d) (%d,%d) (%d,%d)",&xp,&yp,&x1,&y1,&x2,&y2,&px,&py);

    float radius = xp*xp + yp*yp;
    float innerRing,outerRing;
    float point_distance = px*px + py*py;
    if(x1*x1 + y1*y1 <= x2*x2 + y2*y2 ){
        innerRing = x1*x1 + y1*y1;
        outerRing = x2*x2 + y2*y2;
    }
    else{
        innerRing = x2*x2 + y2*y2;
        outerRing = x1*x1 + y1*y1;
    }
    if(point_distance >= 0 && point_distance <=radius ){
        cout<<"SPHERE\n";
    }
    else if(point_distance >=innerRing && point_distance <= outerRing){
        cout<<"RING\n";
    }
    else{
        cout<<"NONE\n";
    }
}