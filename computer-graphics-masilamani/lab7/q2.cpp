
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
    float cx=-0.5, cy=0.2;
    draw_grid();

    int a=20, b=30;
    int x=0,y=b;
    int sa= a*a, sb=b*b;
    int d1 = sb-sa*b+0.25*sa;
    draw_polygon(cx,cy);
    draw_polygon(cx+x*step,cy+y*step);
    draw_polygon(cx-x*step,cy+y*step);
    draw_polygon(cx-x*step,cy-y*step);
    draw_polygon(cx+x*step,cy-y*step);
    // region r1
    while(sa*(y-0.5) > sb*(x+1)){
        // choose e
        if(d1<0) d1 = d1+sb*((x<<1)+3);
        else{
            d1 = d1+sb*((x<<1)+3) + sa*(-(y<<1)+2);
            y--;
        }
        x++;
        draw_polygon(cx+x*step,cy+y*step);
        draw_polygon(cx-x*step,cy+y*step);
        draw_polygon(cx-x*step,cy-y*step);
        draw_polygon(cx+x*step,cy-y*step);
    }

    int d2=sb*pow((x+0.5),2) + sa*pow((y-1),2) -sa*sb;
    // region r2
    while(y>0){
        // choose se
        if(d2<0){
            d2 = d2 + sb*((x<<1)+2) + sa*(-(y<<1)+3);
            x++;
        }
        else d2 = d2 + sa*(-(y<<1)+3);
        y--;
        draw_polygon(cx+x*step,cy+y*step);
        draw_polygon(cx-x*step,cy+y*step);
        draw_polygon(cx-x*step,cy-y*step);
        draw_polygon(cx+x*step,cy-y*step);
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
