// BLACK 0 // BLUE 1 // GREEN 2 // CYAN	3 // RED 4// MAGENTA 5 
// BROWN 6 // LIGHTGRAY 7 // DARKGRAY 8 // LIGHTBLUE	9// LIGHTGREEN	10
// LIGHTCYAN 11 // LIGHTRED	12 // LIGHTMAGENTA	13 // YELLOW 14 // WHITE	15
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int main(){
    
    int gd = DETECT, gm,color; 
    initgraph(&gd, &gm, NULL); 
    setbkcolor(15);
    int x = 150 , y = 100, r = 40;
    int x1,x2,x3,y1,y2,y3;
    x1 = x , y1 = y - r;
    x2 = x - (sqrt(3)*r)/2 , y2 = y +  r/2;
    x3 = x + (sqrt(3)*r)/2 , y3 = y +  r/2;
    setcolor(2);
    circle(x,y,r);

    setcolor(1);
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);

    setcolor(2);
    circle(x,y,r/2);
    
    delay(50000);
    closegraph();
    return 0;
}