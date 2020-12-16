#include<bits/stdc++.h>
#include<GL/glut.h>
#define IN 0 //0000
#define L 1 //0001
#define R 2 //0010
#define U 8 //1000
#define D 4 //0100
using namespace std;

// width and height of screen
const int width = 1200, height = 600;
int xmin, ymin;
int xmax, ymax;
int num_line;

struct point {
    double x1, y1, x2, y2;
};

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
}
// Function to compute region code for a point(x, y)
int region_code(double x, double y) {
    int code = IN;
    int b1 = (y-ymax) > 0 ? 1 : 0;
    int b2 = (ymin-y) > 0 ? 1 : 0;
    int b3 = (x-xmax) > 0 ? 1 : 0;
    int b4 = (xmin-x) > 0 ? 1 : 0;

    if(b1) code |= U;
    if(b2) code |= D;
    if(b3) code |= R;
    if(b4) code |= L;

    return code;
}

void cohen_suther(double x1, double y1, double x2, double y2) {
    int code1 = region_code(x1, y1);
    int code2 = region_code(x2, y2);
    
    bool accepted = 0;
    vector<point> points;
    while (true) {
        if((code1 == 0) && (code2 == 0)) {
            // if both points lie inside
            accepted = 1;
            break;
        }else if (code1 & code2) {
            // if both point lie outside
            break;
        }else {
            // if neither case1 nor case2
            int outside_point;
            double x, y;
            // checking whether point is outside one by one
            // if both is outside then check for first point followed by second
            outside_point = (code1 != 0) ? code1 : code2;
            float m = (y2 - y1)/(x2 - x1);
            // find intersecting point 
            if (outside_point & U) {
                // point is above
                x = x1 +  (ymax - y1) /m ;
                y = ymax;
            } else if (outside_point & D) {
                // point is below
                x = x1 + (ymin - y1)/m;
                y = ymin;
            } else if (outside_point & R) {
                // point is right
                y = y1 + m*(xmax - x1);
                x = xmax;
            } else if (outside_point & L) {
                // point is left
                y = y1 + m*(xmin - x1);
                x = xmin;
            }
            
            // change the coodinate of point which was outside
            if(outside_point == code1) {
                x1 = x;
                y1 = y;
                code1 = region_code(x1, y1);
            }else if(outside_point == code2){
                x2 = x;
                y2 = y;
                code2 = region_code(x2, y2);
            }
        }
    }
    if(accepted) {
        glBegin(GL_LINES);
            glVertex3f(x1,y1,0);
            glVertex3f(x2,y2,0);
        glEnd();
    }else {
        cout <<"line from ("<<x1<<","<<y1<<") to ("<<x2<<","<<y2<<") is outside"<<endl;
    }
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
    double x1, y1, x2, y2;
	for (int i = 1; i <= num_line; i++) {
        cin>>x1>>y1>>x2>>y2;
        cohen_suther(x1, y1, x2, y2);
    }
	glEnd();
	glFlush();
}
int main(int argc, char **argv) {
    freopen("input.txt", "r", stdin);
    cin >> xmin >> ymin >> xmax >> ymax;
    cin >> num_line;

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("2nd question");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
    return 0;
}