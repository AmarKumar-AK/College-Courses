
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
    float cx=-0.5, cy=0.3, R=15;
    draw_grid();
    
    float x=0, y=R;
    float h=1-R;
    draw_polygon(cx,cy);
    draw_polygon(cx+x*step,cy+y*step);
    draw_polygon(cx-x*step,cy+y*step);
    draw_polygon(cx+x*step,cy-y*step);
    draw_polygon(cx-x*step,cy-y*step);

    draw_polygon(cx+y*step,cy+x*step);
    draw_polygon(cx-y*step,cy+x*step);
    draw_polygon(cx+y*step,cy-x*step);
    draw_polygon(cx-y*step,cy-x*step);
    while(y>x){
        if(h<0) h=h+(2*x)+3;
        else{
            h=h+2*(x-y) + 5;
            y=y-1;
        }
        x=x+1;
        // cout<<"x : "<<x<<"     y : "<<y<<endl;
        draw_polygon(cx+x*step,cy+y*step);
        draw_polygon(cx-x*step,cy+y*step);
        draw_polygon(cx+x*step,cy-y*step);
        draw_polygon(cx-x*step,cy-y*step);

        draw_polygon(cx+y*step,cy+x*step);
        draw_polygon(cx-y*step,cy+x*step);
        draw_polygon(cx+y*step,cy-x*step);
        draw_polygon(cx-y*step,cy-x*step);
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
