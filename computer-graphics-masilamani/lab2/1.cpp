// BLACK 0 // BLUE 1 // GREEN 2 // CYAN	3 // RED 4// MAGENTA 5 
// BROWN 6 // LIGHTGRAY 7 // DARKGRAY 8 // LIGHTBLUE	9// LIGHTGREEN	10
// LIGHTCYAN 11 // LIGHTRED	12 // LIGHTMAGENTA	13 // YELLOW 14 // WHITE	15
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int main(){
    int option;
    int x,y;
    int x1,y1,x2,y2;
    int radius;
    int xradius,yradius;
    int x3,y3;
    int gd = DETECT, gm,color; 
    initgraph(&gd, &gm, NULL); 

    while(1){

        cout<<"what do you want to plot?"<<endl<<"1. Point\n2. Line\n3. Circle\n4. Ellipse\n5. Triangle\n6. Rectangle\n7. exit"<<endl;
        cin>>option;
		cleardevice();
        
        switch(option){
            case 1 : cout<<"enter x and y co-ordiantes of point : ";
                    
                    cin>>x>>y;
                    putpixel(x, y, YELLOW);
                    break;
            case 2 : cout<<"enter x & y co-ordinates of two points : ";
                    
                    cin>>x1>>y1>>x2>>y2;
                    line(x1,y1,x2,y2);
                    break;
            case 3 : cout<<"enter x & y co-ordiantes of circle : ";
                    
                    cin>>x>>y;
                    cout<<"enter radius of circle : ";
                    cin>>radius;
                    circle(x,y,radius);
                    break;
            case 4 : cout<<"enter x & y co-ordinates of ellipse : ";
                    cin>>x>>y;
                    cout<<"enter horizontal and vertical radius respectively : ";
                    cin>>xradius>>yradius;
                    ellipse(x, y, 0, 360, xradius, yradius);
                    break;
            case 5 : cout<<"enter 3 point co-ordinates to draw traingle : ";
                    cin>>x1>>y1>>x2>>y2>>x3>>y3;
                    line(x1,y1,x2,y2);
                    line(x2,y2,x3,y3);
                    line(x3,y3,x1,y1);
                    break;
            case 6 : cout<<"enter x & y co-ordinates of top left and bottom right points respectively : ";
                    cin>>x1>>y1>>x2>>y2;
                    rectangle(x1,y1,x2,y2);
                    break;
            case 7 : return 0;
        }
        delay(1000);
		
    }
    
    closegraph();
    return 0;
}