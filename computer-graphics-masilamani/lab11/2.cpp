// #define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

// Reason Codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

int x_max, y_max, x_min, y_min;

struct point {
    float x1, y1, x2, y2;
};

// function to initialize
void myInit(void) {
    // making background color black as first
    // 3 arguments all are 0.0
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // making picture color green (in RGB mode), as middle argument is 1.0
    glColor3f(0.0, 1.0, 0.0);

    // breadth of picture boundary is 1 pixel
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // setting window dimension in X- and Y- direction
    gluOrtho2D(-780, 780, -420, 420);
}

vector<point> points;

// Function to compute region code for a point(x, y)
int computeCode(float x, float y) {
    // initialized as being inside
    int code = INSIDE;

    if (x < x_min)
        code |= LEFT;
    else if (x > x_max)
        code |= RIGHT;
    if (y < y_min)
        code |= BOTTOM;
    else if (y > y_max)
        code |= TOP;

    return code;
}

void cohenSutherlandClip(float x1, float y1, float x2, float y2) {
    // Compute region codes for P1, P2
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    // Initialize line as outside the rectangular window
    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            // If both endpoints lie within rectangle
            accept = true;
            break;
        } else if (code1 & code2) {
            // If both endpoints are outside rectangle so we don't need to take
            // this point.
            break;
        } else {
            // Partial inside
            int code_out;
            float x, y;

            // At least one endpoint is outside the rectangle, pick it.
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            // Find intersection point using the relation y = mx + c
            if (code_out & TOP) {
                // point is above the clip rectangle
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (code_out & BOTTOM) {
                // point is below the rectangle
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (code_out & RIGHT) {
                // point is to the right of rectangle
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (code_out & LEFT) {
                // point is to the left of rectangle
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            // Now intersection point x, y is found
            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept) {
        points.push_back({x1, y1, x2, y2});
    }
}

void draw_line() {
    for (int i = 0; i < points.size(); i++) {
        cout << points[i].x1 << " " << points[i].y1 << " " << points[i].x2
             << " " << points[i].y2 << endl;
        glBegin(GL_LINES);
        glVertex2f(points[i].x1, points[i].y1);
        glVertex2f(points[i].x2, points[i].y2);
        glEnd();
    }
}

void display(void) {
    cout << "Enter the xmin, ymin, xmax, ymax: ";
    cin >> x_min >> y_min >> x_max >> y_max;

    cout << "Enter the value of n: ";
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Enter the cordinate x1,y1, x2, y2 for the " << i << " line: ";
        float x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cohenSutherlandClip(x1, y1, x2, y2);
    }

    draw_line();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // giving window size in X- and Y- direction
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(0, 0);

    // Giving name to window
    glutCreateWindow("Question 2");
    myInit();

    glutDisplayFunc(display);
    glutMainLoop();
}