
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
	glPointSize(1.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
} 

void display (void) 
{ 
    int a=10, b=5;
    
    float step=0.002;
    glPointSize(4);
    // glBegin(GL_POINTS);
    //     glColor3f(0.56,0.56,0.56);
        
    //     glVertex3f(0.0,0.0,0);
    //     glVertex3f(0.01,0.01,0);
    //     glVertex3f(-0.1,0.1,0);
    //     glVertex3f(0.1,-0.1,0);
    //     glVertex3f(-0.1,-0.1,0);

    // glEnd();
    glBegin(GL_POINTS);
    // 1 pixel = 0.01 
        glColor3f(0.56,0.56,0.56);
         for(float i=0;i<1;i+=step){
            float x=a*cos(2*pi*i)/10,y=b*sin(2*pi*i)/10;
            x=rounds(x),y=rounds(y);
            // cout<<x<<" "<<y<<endl;
            glVertex3f(x,y,0);
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

	glutCreateWindow("Question 2"); 
	myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 
