#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;
// rectangle coordinate
int r_x1 = 100, r_y1 = 450, r_x2 = 200, r_y2 = 500;
// triangle coordinates
int t_x1 = 650, t_y1 = 300, t_x2 = 750, t_y2 = 350, t_x3 = 700, t_y3 = 250;
// width and height of screen
int width = 1200, height = 600;

float borderCol[3] = {1.0, 0.0, 0.0};
// for checking if point lies inside triangle
float area(int x1,int y1,int x2,int y2,int x3,int y3){
    return abs((x1*(y2-y3) + x2*(y3-y1) +  x3*(y1-y2))/ 2.0);
}
bool check_inside_triangle(int px,int py) { 
    int ABC_area = area(t_x1,t_y1,t_x2,t_y2,t_x3,t_y3); 
    int PAB_area = area(px,py,t_x1,t_y1,t_x2,t_y2); 
    int PBC_area = area(px,py,t_x2,t_y2,t_x3,t_y3); 
    int PCA_area = area(px,py,t_x3,t_y3,t_x1,t_y1); 
    int total_area = PAB_area + PBC_area + PCA_area;
    if(ABC_area == total_area){
        return true;
    }else{
        return false;
    }
}
bool check_inside_rectangle(int px,int py) { 
    int rect_area = area(r_x1,r_y1,r_x1,r_y2,r_x2,r_y1) +  area(r_x2,r_y2,r_x2,r_y1,r_x1,r_y2); 
    int PAB_area = area(px,py,r_x1,r_y1,r_x1,r_y2); 
    int PBC_area = area(px,py,r_x1,r_y2,r_x2,r_y2); 
    int PCD_area = area(px,py,r_x2,r_y2,r_x2,r_y1); 
    int PAD_area = area(px,py,r_x2,r_y1,r_x1,r_y1); 
    int total_area = PAB_area + PBC_area + PCD_area + PAD_area;
    if(rect_area == total_area){
        return true;
    }else{
        return false;
    }
} 
void setPixel(int pointx, int pointy, float f[3]){
    glBegin(GL_POINTS);
        glColor3fv(f);
        glVertex2i(pointx, pointy);
    glEnd();
    glFlush();
}
void getPixel(int x, int y, float pixels[3]){
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, pixels);
}
void draw_rect(int x1, int y1, int x2, int y2){
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
        glVertex3i(x1, y1, 0);glVertex3i(x2, y1, 0);
        glVertex3i(x2, y1, 0);glVertex3i(x2, y2, 0);
        glVertex3i(x2, y2, 0);glVertex3i(x1, y2, 0);
        glVertex3i(x1, y2, 0);glVertex3i(x1, y1, 0);
    glEnd();
}
void draw_tri(int x1, int y1, int x2, int y2, int x3, int y3){
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
        glVertex3i(x1, y1, 0);glVertex3i(x2, y2, 0);
        glVertex3i(x2, y2, 0);glVertex3i(x3, y3, 0);
        glVertex3i(x3, y3, 0);glVertex3i(x1, y1, 0);
    glEnd();
}

void display(){
    // setting white backgound
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    // drawing rectangle and triangle
    draw_rect(r_x1, r_y1, r_x2, r_y2);
    draw_tri(t_x1, t_y1, t_x2, t_y2, t_x3, t_y3);

    glFlush();
}
void boundaryFill4(int x, int y, float fillColor[3], float borderColor[3]){
    float innerColor[3];
    getPixel(x, y, innerColor);
    bool check = false;
    for (int i = 0; i < 3; ++i){
        if (innerColor[i] == borderColor[i] && innerColor[i] == fillColor[i]){
            check = true;
            break;
        }
    }
    if (!check){
        setPixel(x, y, fillColor);
        boundaryFill4(x + 1, y, fillColor, borderColor);
        boundaryFill4(x - 1, y, fillColor, borderColor);
        boundaryFill4(x, y + 1, fillColor, borderColor);
        boundaryFill4(x, y - 1, fillColor, borderColor);
    }
}

void mouse(int btn, int state, int x, int y){
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)   
    { 
        float fillCol1[3] = {1.0};
        int xi = x;
        // shifting y cordinate to bottom left from top left
        int yi = (height - y);
        // check if point lies inside triangle
        if(check_inside_triangle(xi,yi)){
            fillCol1[0]=0.0;
            fillCol1[1]=1.0;
            fillCol1[2]=0.0;
            boundaryFill4(xi, yi, fillCol1, borderCol);
        }
        // check if point lies inside rectangle
        if(check_inside_rectangle(xi,yi)){
            fillCol1[0]=0.0;
            fillCol1[1]=0.0;
            fillCol1[2]=1.0;
            boundaryFill4(xi, yi, fillCol1, borderCol);
        }
    }
}
void myinit(){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, (GLdouble)width, 0, (GLdouble)height);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Boundary fill algorithm");
    glutDisplayFunc(display);
    myinit();
    // calling mouse click
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}