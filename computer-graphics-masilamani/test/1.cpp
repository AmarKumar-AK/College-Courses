#include<bits/stdc++.h>
#include <GL/glut.h>
using namespace std;
// width and height of screen
const int width = 1200, height = 600;
int pts[5][2] = {{50,200},{200,50},{350,200},{350,400},{50,400}};
void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
}

void DrawPoint(int x, int y) {
	glBegin(GL_POINTS);
		glVertex3i(x, y, 0);
	glEnd();
	glFlush();
}
void Drawline(int x1, int y1, int x2, int y2){
	glBegin(GL_LINES);
		glVertex3i(x1,y1,0);
		glVertex3i(x2,y2,0);
	glEnd();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i=0 ; i<5 ; ++i){
		Drawline(pts[i%5][0],pts[i%5][1],pts[(i+1)%5][0],pts[(i+1)%5][1]);
	}
	glEnd();
	glFlush();
}

int main(int argc, char** argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("1st question");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}