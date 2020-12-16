#include<bits/stdc++.h>
#include <GL/glut.h>
using namespace std;
// rectangle coordinate
int r_x1 = 100, r_y1 = 450, r_x2 = 200, r_y2 = 500;
int width = 1200, height = 600;  
float intCol[3] = {1.0,0.0,0.0};   
float fillCol[3] = {0.0,0.9,0.0}; 
void setPixel(int pointx, int pointy, float f[3])  
{  
    glBegin(GL_POINTS);  
    glColor3fv(f);  
    glVertex2i(pointx,pointy);  
    glEnd();  
    glFlush();  
}  
void getPixel(int x, int y, float pixels[3])  
{  
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,pixels);  
}  
void draw_rect(int x1, int y1, int x2, int y2)  
{       
    glColor3f(1,0,0);  
    glBegin(GL_LINES);  
        glVertex3i(x1, y1, 0);glVertex3i(x2, y1, 0);
        glVertex3i(x2, y1, 0);glVertex3i(x2, y2, 0);
        glVertex3i(x2, y2, 0);glVertex3i(x1, y2, 0);
        glVertex3i(x1, y2, 0);glVertex3i(x1, y1, 0);  
    glEnd();  
    for(int i=x1;i<=x2-1;i++){
        for(int j=y1;j<=y2-1;j++){
            setPixel(i,j,intCol);
        }
    }

    glFlush();  
}   

void display()  
{  
    // setting white backgound
    glClearColor(1,1,1,1);  
    glClear(GL_COLOR_BUFFER_BIT);  
    draw_rect(r_x1,r_y1,r_x2,r_y2);
    glFlush();  
}  

void floodfill4(int x,int y,float oldcolor[3],float newcolor[3])   
{   
    float innerColor[3];   
    getPixel(x,y,innerColor);
    bool check = false;
    for (int i = 0; i < 3; ++i){
        if (innerColor[i] != oldcolor[i]){
            check = true;
            break;
        }
    } 
    if(!check)   
    {   
        setPixel(x,y,newcolor);   
        floodfill4(x+1,y,oldcolor,newcolor);   
        floodfill4(x-1,y,oldcolor,newcolor);   
        floodfill4(x,y+1,oldcolor,newcolor);   
        floodfill4(x,y-1,oldcolor,newcolor);   
    }   
} 

void mouse(int btn, int state, int x, int y)  
{  
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)   
    {  
        int xi = x;  
        int yi = (height-y);  
        floodfill4(xi,yi,intCol,fillCol);   
    }    
}  
void myinit()  
{      
    glViewport(0,0,width,height);  
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();  
    gluOrtho2D(0,(GLdouble)width,0,(GLdouble)height);  
    glMatrixMode(GL_MODELVIEW);  
}  
int main(int argc, char** argv)  
{  
    glutInit(&argc,argv);  
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowSize(width,height);  
    glutCreateWindow("Flood Fill Algorithm");  
    glutDisplayFunc(display);  
    myinit();  
    glutMouseFunc(mouse);  
    glutMainLoop();  
    return 0;  
}