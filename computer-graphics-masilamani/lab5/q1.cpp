
#include<bits/stdc++.h> 
#include<GL/glut.h>
#define pi 3.142857 
using namespace std;

float rounds(float var) 
{ 
    float value = (int)(var * 100 + .5); 
    return (float)value / 100; 
} 

void myInit (void) 
{ 
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
} 

void display (void) 
{
    float step=0.002;
    glPointSize(4);
    glBegin(GL_LINES);
    
        glVertex3f(0.0,-1.0,0);
        glVertex3f(0.0,1.0,0);
        glVertex3f(-1.0,0.0,0);
        glVertex3f(1.0,0.0,0);
      
    glEnd();

    
    
    // glPointSize(4);
    // slope 1
    glBegin(GL_POINTS);
        float x1=0.9,y1=0.9, x2=-0.9,y2=-0.9;
        float m = (y2-y1)/(x2-x1);
        float c = y1 - m*x1;
        cout<<"slope : "<<m<<"  |  intercept "<<c<<endl;
        for(float x=x2 ; x<x1 ; x+=step){
            float y = m*x + c;
            float tempx = rounds(x);
            y=rounds(y);
            glVertex3f(tempx,y,0.0);
        } 
    glEnd();
    // slope >1
    glBegin(GL_POINTS);
        x1=0.7,y1=0.9, x2=-0.9,y2=-0.9;
        m = (y2-y1)/(x2-x1);
        c = y1 - m*x1;
        cout<<"slope : "<<m<<"  |  intercept "<<c<<endl;
        for(float x=x2 ; x<x1 ; x+=step){
            float y = m*x + c;
            float tempx = rounds(x);
            y=rounds(y);
            glVertex3f(tempx,y,0.0);
        } 
    glEnd();
    // slope<1
    glBegin(GL_POINTS);
        x1=0.9,y1=0.7, x2=-0.9,y2=-0.9;
        m = (y2-y1)/(x2-x1);
        c = y1 - m*x1;
        cout<<"slope : "<<m<<"  |  intercept "<<c<<endl;
        for(float x=x2 ; x<x1 ; x+=step){
            float y = m*x + c;
            float tempx = rounds(x);
            y=rounds(y);
            glVertex3f(tempx,y,0.0);
        } 
    glEnd();
    // slope = 0
    glBegin(GL_POINTS);
        x1=0.9,y1=0.3, x2=-0.9,y2=0.3;
        m = (y2-y1)/(x2-x1);
        c = y1 - m*x1;
        cout<<"slope : "<<m<<"  |  intercept "<<c<<endl;
        for(float x=x2 ; x<x1 ; x+=step){
            float y = m*x + c;
            float tempx = rounds(x);
            y=rounds(y);
            glVertex3f(tempx,y,0.0);
        } 
    glEnd();
    // slope = inf
    glBegin(GL_POINTS);
        x1=0.3,y1=0.9, x2=0.3,y2=-0.9;
        m = (y2-y1)/(x2-x1);
        c = y1 - m*x1;
        cout<<"slope : "<<m<<"  |  intercept "<<c<<endl;
        for(float x=-0.9 ; x<0.9 ; x+=step){
            float y = m*x + c;
            float tempx = rounds(x);
            y=rounds(y);
            glVertex3f(tempx,y,0.0);
        } 
    glEnd();



    
	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	glutInitWindowSize(750, 750); 
	glutInitWindowPosition(0, 0); 

	glutCreateWindow("Question 1"); 
	myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 
