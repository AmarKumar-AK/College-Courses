// BLACK 0 // BLUE 1 // GREEN 2 // CYAN	3 // RED 4// MAGENTA 5 
// BROWN 6 // LIGHTGRAY 7 // DARKGRAY 8 // LIGHTBLUE	9// LIGHTGREEN	10
// LIGHTCYAN 11 // LIGHTRED	12 // LIGHTMAGENTA	13 // YELLOW 14 // WHITE	15
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int main(){
    
    int gd = DETECT, gm,color; 
    initgraph(&gd, &gm, NULL); 

    int x = 200 , y = 200, r = 120;

    setbkcolor(15);
    setcolor(BLACK);
    circle(x,y,r+10);
    floodfill(x, x-r+1, BLACK);

    setcolor(YELLOW);
    circle(x,y,r);
    floodfill(x, y, YELLOW);

    setcolor(BLACK);
    circle(x-40,y-40,20);
    floodfill(x-40, y-40, BLACK);

    circle(x+40,y-40,20);
    floodfill(x+40, y-40, BLACK);

    rectangle(x-70,y+40,x+70,y+50);
    floodfill(x-70+1, y+40+1, BLACK);
    delay(50000);
    closegraph();
    return 0;
}