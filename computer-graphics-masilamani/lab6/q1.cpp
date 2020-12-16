
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
    glColor3f(1.0,0.0,0.0);
    glVertex3f(x1,x2,0);
    glVertex3f(x1,x2+step,0);
    glVertex3f(x1+step,x2+step,0);
    glVertex3f(x1+step,x2,0);
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
    float m = (y2-y1)/(x2-x1);
    float rm = (x2-x1)/(y2-y1);
    // cout<<"m : "<<m<<endl;

    int x = round(x1),y=round(y1);
    float yf = y1,xf=x1;
    glBegin(GL_POLYGON);
        draw_polygon(x*step,y*step);
    glEnd();

    
    if(fabs(m)<=1){
        // cout<<"hello : "<<x<<"    "<<x2<<endl;
        while(x<x2){
            x=x+1; yf=yf+m;
            y=round(yf);
            glBegin(GL_POLYGON);
                // cout<<"x : "<<x<<"   y : "<<y<<endl;
                draw_polygon(x*step,y*step);
            glEnd();
        }
    }
    else{
        while(y<y2){
            y=y+1; xf=xf+rm;
            x=round(xf);
            glBegin(GL_POLYGON);
                // cout<<"x : "<<x<<"   y : "<<y<<endl;
                draw_polygon(x*step,y*step);
            glEnd();
        }
    }
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
