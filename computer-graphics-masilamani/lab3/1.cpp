
#include<bits/stdc++.h> 
#include<GL/glut.h> 
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
	// for rectangle
    glBegin(GL_POLYGON);
        glColor3f(0.294,0.67,0.721);
        glVertex2f(-0.3,0.1);
        glVertex2f(0.3,0.1);
        glVertex2f(0.3,-0.8);
        glVertex2f(-0.3,-0.8);
	glEnd();
    // for roof
    glBegin(GL_TRIANGLES);
      glColor3f(0.901,0.262,0.325);
      glVertex2f(-0.3,0.11);
      glVertex2f(0.3,0.11);
      glVertex2f(0.0,0.8);
    glEnd();
    // for door
    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(-0.05,-0.3);
        glVertex2f(0.05,-0.3);
        glVertex2f(0.05,-0.79);
        glVertex2f(-0.05,-0.79);
	glEnd();
    // for left window
    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(-0.22,-0.3);
        glVertex2f(-0.13,-0.3);
        glVertex2f(-0.13,-0.45);
        glVertex2f(-0.22,-0.45);
	glEnd();
    // for right window
    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(0.22,-0.3);
        glVertex2f(0.13,-0.3);
        glVertex2f(0.13,-0.45);
        glVertex2f(0.22,-0.45);
	glEnd();
	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	glutInitWindowSize(1366, 768); 
	glutInitWindowPosition(0, 0); 
	
	glutCreateWindow("House"); 
	myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 
