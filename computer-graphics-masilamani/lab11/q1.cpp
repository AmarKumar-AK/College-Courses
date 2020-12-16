#include<bits/stdc++.h>
#include<GL/glut.h>
using namespace std;

// width and height of screen
const int width = 1200, height = 600;
int xmin = 200, ymin = 200;
int xmax = 500, ymax = 500;
vector<pair<int,int>>points;
void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
}

void DrawPoint(float x, float y) {
    glPointSize(2.0);
	glBegin(GL_POINTS);
		glVertex3f(x, y, 0);
	glEnd();
	glFlush();
}

void DrawRectangle(float x1, float y1, float x2, float y2){
    for(int i = xmin ; i<xmax ; ++i){
        DrawPoint(i,ymin);
        DrawPoint(i,ymax);
    }
    for(int i = ymin ; i<ymax ; ++i){
        DrawPoint(xmin,i);
        DrawPoint(xmax,i);
    }
}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
    DrawRectangle(xmin, ymin, xmax, ymax);
	for(auto p: points){
        if(p.first <xmax && p.first>xmin && p.second<ymax && p.second>ymin){
            DrawPoint(p.first,p.second);
        }
    }
	glEnd();
	glFlush();
}

int main(int argc, char** argv){
    for(int i=0 ; i<100 ; ++i){
        int x = rand()%1200;
        int y = rand()%600;
        points.push_back({x,y});
    }
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("1st question");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}