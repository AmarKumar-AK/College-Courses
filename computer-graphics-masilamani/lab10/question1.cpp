#include<bits/stdc++.h>
#include <GL/glut.h>
using namespace std;
// width and height of screen
const int width = 1200, height = 600;
float pts[5][2] = {{50,200},{200,50},{350,200},{350,400},{50,400}};
void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
}

void DrawPoint(float x, float y) {
	glBegin(GL_POINTS);
		glVertex3f(x, y, 0);
	glEnd();
	glFlush();
}
void Drawline(float x1, float y1, float x2, float y2){
	glBegin(GL_LINES);
		glVertex3f(x1,y1,0);
		glVertex3f(x2,y2,0);
	glEnd();
}
void translate(int a, int b){
    for(int i=0 ; i<sizeof(pts)/sizeof(pts[0]); ++i){
        pts[i][0] +=a;
        pts[i][1] +=b;
    }
}
vector<int> find_center(){
    int minx = pts[0][0], miny = pts[0][1];
    int maxx = pts[0][0], maxy = pts[0][1];
    for(int i=0 ; i<sizeof(pts)/sizeof(pts[0]) ; ++i){
        maxx = (maxx<pts[i][0])? pts[i][0] : maxx;
        maxy = (maxx<pts[i][1])? pts[i][1] : maxx;
        minx = (minx<pts[i][0])? minx : pts[i][0];
        miny = (minx<pts[i][1])? minx : pts[i][1];
    }
    vector<int>v;
    // (minx+maxx)/2,(miny+maxy)/2
    v.push_back((minx+maxx)/2);
    v.push_back((miny+maxy)/2);
    return v;

}
void scale_image(float factor){
    vector<int>v;
    v = find_center();
    translate(-v[0],-v[1]);
    for(int i=0 ; i<sizeof(pts)/sizeof(pts[0]); ++i){
        pts[i][0] *=factor;
        pts[i][1] *=factor;
    }
    translate(v[0],v[1]);
    // cout<<v[0]<<" "<<v[1]<<endl;
}
void draw_polygon(){
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i=0 ; i<sizeof(pts)/sizeof(pts[0]) ; ++i){
		Drawline(pts[i%5][0],pts[i%5][1],pts[(i+1)%5][0],pts[(i+1)%5][1]);
	}
}

void rotate_image(float deg){
    vector<int>v;
    v = find_center();
    translate(-v[0],-v[1]);
    float tempx,tempy;
    for(int i=0 ; i<sizeof(pts)/sizeof(pts[0]); ++i){
        tempx = pts[i][0];
        tempy = pts[i][1];
        float theta = deg*3.14159/180;
        pts[i][0] = tempx*cos(theta) - tempy*sin(theta);
        pts[i][1] = tempy*cos(theta) + tempx*sin(theta);
    }
    translate(v[0],v[1]);
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	draw_polygon();
    translate(100,100);
    draw_polygon();
    scale_image(0.5);
    draw_polygon();
    rotate_image(30);
    draw_polygon();
	glEnd();
	glFlush();
}

int main(int argc, char** argv){
    
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