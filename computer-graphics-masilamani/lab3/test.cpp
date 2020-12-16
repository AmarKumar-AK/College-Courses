
#include<bits/stdc++.h> 
#include<GL/glut.h>
#define pi 3.142857 
using namespace std;

void myInit (void) 
{ 
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glPointSize(1.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
} 

void display (void) 
{ 
	
    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(-0.6,0.0);
        glVertex2f(0.6,0.0);
        glVertex2f(0.6,-0.6);
        glVertex2f(-0.6,-0.6);
	glEnd();
    
    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(-0.1,0.6);
        glVertex2f(0.55,0.6);
        glVertex2f(0.6,0.01);
        glVertex2f(-0.3,0.01);
	glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.73,0.73,0.73);
        glVertex2f(-0.088,0.58);
        glVertex2f(0.2,0.58);
        glVertex2f(0.2,0.03);
        glVertex2f(-0.28,0.03);
	glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.73,0.73,0.73);
        glVertex2f(0.24,0.58);
        glVertex2f(0.54,0.58);
        glVertex2f(0.59,0.03);
        glVertex2f(0.24,0.03);
	glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0,0.0,0.0);
        for(int i=0;i<1000;++i){
            glVertex3f(-0.3+cos(2*3.14159*i/1000.0)/10.0,-0.6+sin(2*3.14159*i/1000.0)/5.2,0);
        }
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0,0.0,0.0);
        for(int i=0;i<1000;++i){
            glVertex3f(0.3+cos(2*pi*i/1000.0)/10.0,-0.6+sin(2*pi*i/1000.0)/5.2,0);
        }
    glEnd();



    
	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	glutInitWindowSize(1366, 768); 
	glutInitWindowPosition(0, 0); 

	glutCreateWindow("Car"); 
	myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 
