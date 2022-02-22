
#include<bits/stdc++.h> 
#include<GL/glut.h>
#define pi 3.142857 
using namespace std;
const float step=0.01;

void draw_grid(){
    // for white background
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex3f(-1.0,-1.0,0);
        glVertex3f(-1.0,1.0,0);
        glVertex3f(1.0,1.0,0);
        glVertex3f(1.0,-1.0,0);
    glEnd();

    // for grid
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_LINES);
        for(float i=-1.0 ; i<=1.0 ; i+=step){
            glVertex3f(-1.0,i,0.0);
            glVertex3f(1.0,i,0.0);
        }
        for(float i=-1.0 ; i<=1.0 ; i+=step){
            glVertex3f(i,-1.0,0.0);
            glVertex3f(i,1.0,0.0);
        } 
    glEnd();

    // for x and y axis
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINES);
        glVertex3f(0.0,-1.0,0);
        glVertex3f(0.0,1.0,0);
        glVertex3f(-1.0,0.0,0);
        glVertex3f(1.0,0.0,0);
    glEnd();
}

void draw_polygon(float x1,float x2){
    // cout<<"x : "<<x1<<"   y : "<<x2<<endl;
    glBegin(GL_POLYGON);
        glColor3f(1.0,0.0,0.0);
        glVertex3f(x1,x2,0);
        glVertex3f(x1,x2+step,0);
        glVertex3f(x1+step,x2+step,0);
        glVertex3f(x1+step,x2,0);
    glEnd();
}


void myInit (void) 
{ 
	glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();

}

void display (void) 
{
    // glPointSize(10);
    draw_grid();

    float x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    // preprocessing
    if(y1>y2){
        swap(y1,y2);
        swap(x1,x2);
    }
    float m = (y2-y1)/(x2-x1);
    bool slope_is_negative=false;
    if(m<0){
        y1 = -y1;
        y2 = -y2;
        slope_is_negative = true;
    }
    bool line_not_in_1st_octant = false;
    if(m>=1){
        swap(x1,y1);
        swap(x2,y2);
        line_not_in_1st_octant = true;
    }

    bool x1_negative = false;
    bool y1_negative = false;
    if(x1<0) x1_negative = true;
    if(y1<0) y1_negative = true;
    
    if(x1_negative){
        x1 = abs(x1) + 1;
        x2 = abs(x1) + 1;
    }
     
    if(y1_negative){
        y1 = abs(y1) + 1;
        y2 = abs(y2) + 1;
    } 

    // m = (y2-y1)/(x2-x1);
    // cout<<m<<endl;
    float dy = y2-y1, dx = x2-x1;
    float d = 2*dy - dx;
    float dE=2*dy, dNE=2*(dy-dx);
 
    int x = round(x1),y=round(y1);
    

        draw_polygon(x*step,y*step);
        draw_polygon(-x*step,y*step);
        draw_polygon(x*step,-y*step);
        draw_polygon(-x*step,-y*step);
 
        draw_polygon(y*step,x*step);
        draw_polygon(-y*step,x*step);
        draw_polygon(y*step,-x*step);
        draw_polygon(-y*step,-x*step);


    while(x<x2){
        if(d<=0) d=d+dE;
        else{
            d=d+dNE;
            y=y+1;
        }
        x=x+1;
        draw_polygon(x*step,y*step);
        draw_polygon(-x*step,y*step);
        draw_polygon(x*step,-y*step);
        draw_polygon(-x*step,-y*step);
 
        draw_polygon(y*step,x*step);
        draw_polygon(-y*step,x*step);
        draw_polygon(y*step,-x*step);
        draw_polygon(-y*step,-x*step);
    }
    
    glFlush();
    
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	glutInitWindowSize(750, 750); 
	glutInitWindowPosition(0, 0); 

	glutCreateWindow("Question 2"); 
	myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 
