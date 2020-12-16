#include<bits/stdc++.h>
#include<GL/glut.h>
using namespace std;
#define min(a,b) (a<b)?a:b
#define max(a,b) (a>b)?a:b

int x1, x2, y3, y2;
float u1=0,u2=1;
int xmin=-50,ymin=-50,xmax=50,ymax=50;
double p[4],q[4];

void init(){
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-320,320,-240,240);
}

void drawLine(int x1, int y1, int x2, int y2){
    glBegin(GL_LINES);
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
    glEnd();
}

void drawRectangle(){
    drawLine(xmin,ymin,xmax,ymin);
    drawLine(xmax,ymin,xmax,ymax);
    drawLine(xmax,ymax,xmin,ymax);
    drawLine(xmin,ymax,xmin,ymin);
}
void LiangBarsky(int x1,int y1,int x2,int y2){
    int dx=x2-x1, dy=y2-y1;
    double u;

    p[0]=-dx; q[0]=x1-xmin;
    p[1]=dx; q[1]=xmax-x1;
    p[2]=-dy; q[2]=y1-ymin;
    p[3]=dy; q[3]=ymax-y1;

    for(int k=0;k<4;++k){
        // case1
        if(p[k]==0 && q[k]<0) return;
        u=(q[k])/(p[k]);
        // case2
        if(p[k]<0) u1 = max(u,u1);
        // case3
        else if(p[k]>0) u2 = min(u,u2);
    }
    if(u1<u2){
        x1=x1+u1*(x2-x1);
        y1=y1+u1*(y2-y1);
        x2=x1+u2*(x2-x1);
        y2=y1+u2*(y2-y1);
        drawLine(x1,y1,x2,y2);
        glFlush();
    }
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    // drawing clipping rectangle
    drawRectangle();
    glColor3f(1.0,0.0,0.0);
    // calling function to clip line
    
    LiangBarsky(x1,y3,x2,y2);
    glFlush();
}
int main(int argc,char ** argv){
    cout<<"enter the points p1 and p2"<<endl;
    cin>>x1>>y3>>x2>>y2;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Line Clipping");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}