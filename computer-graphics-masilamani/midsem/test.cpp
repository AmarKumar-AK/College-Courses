#include<bits/stdc++.h>
#include <GL/glut.h>
using namespace std;
// width and height of screen
const int width = 600, height = 600;


void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-300, 300, -300, 300);
}

void DrawPoint(int x, int y) {
	glBegin(GL_POINTS);
		glVertex3i(x, y, 0);
	glEnd();
	glFlush();
}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINES);
        glVertex3i(-300, 0, 0);
        glVertex3i(300, 0, 0);
        glVertex3i(0, -300, 0);
        glVertex3i(0, 300, 0);
    glEnd();
	float x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(y1>y2){
        float temp1 = y1;
        y1 = y2;
        y2 = temp1;
        float temp2 = x1;
        x1 = x2;
        x2 = temp2;
    }
    if(y1==y2 && x1!=x2){
        glBegin(GL_LINES);
            glVertex3i(x1, y1, 0);
            glVertex3i(x2, y2, 0);
        glEnd();
        
    }
    else if(x1==x2 && y1!=y2){
        glBegin(GL_LINES);
            glVertex3i(x1, y1, 0);
            glVertex3i(x2, y2, 0);
        glEnd();
        // return 0;
    }
    else{
        // preprocessing
        // move x1,y1 to origin
        if(y1>y2){
            float temp1 = y1;
            y1 = y2;
            y2 = temp1;
            float temp2 = x1;
            x1 = x2;
            x2 = temp2;
        }
        float storex1 = x1;
        x1 = x1 - x1;
        x2 = x2 - x1;
        float storey1 = y1;
        y1 = y1 - y1;
        y2 = y2 - y1;
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        float m = (y2-y1)/(x2-x1);
        bool slope_is_negative=false;
        if(m<0){
            x2 = -x2;
            slope_is_negative = true;
            cout<<"slope_is_negative"<<endl;
            m = (y2-y1)/(x2-x1);
            cout<<"slope : "<<m<<endl;
            cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        }
        bool line_not_in_1st_octant = false;
        if(m>=1){
            float temp1 = x2;
            x2 = y2;
            y2 = temp1;
            line_not_in_1st_octant = true;
            cout<<"not_in_1st_octant"<<endl;
            m = (y2-y1)/(x2-x1);
            cout<<"slope : "<<m<<endl;
            cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        }

        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        cout<<(y2-y1)/(x2-x1)<<endl;
        float dy = y2-y1, dx = x2-x1;
        float d = 2*dy - dx;
        float dE=2*dy, dNE=2*(dy-dx);
        int x = round(x1),y=round(y1);
        vector<pair<int,int>>v;
        v.push_back({x,y});
        // int tempx = x, tempy =y;
        // if(line_not_in_1st_octant){
        //     int temp1 = tempx;
        //     tempx = tempy;
        //     tempy = temp1;
        // }
        // if(slope_is_negative){
        //     tempx = -tempx;
        // }
        // tempx = tempx + storex1;
        // tempy = tempy + storey1;
        // DrawPoint(tempx,tempy);
        // DrawPoint(x,y);
        while(x<x2){
            if(d<=0) d=d+dE;
            else{
                d=d+dNE;
                y=y+1;
            }
            x=x+1;
            v.push_back({x,y});
            // if(line_not_in_1st_octant){
            //     int temp1 = tempx;
            //     tempx = tempy;
            //     tempy = temp1;
            // }
            // if(slope_is_negative){
            //     tempx = -tempx;
            // }
            // tempx = tempx + storex1;
            // tempy = tempy + storey1;
            // DrawPoint(tempx,tempy);
            // DrawPoint(x,y);
        }

        int count = 0;
        for(auto &p:v){
            
            if(line_not_in_1st_octant){
                int temp1 = p.first;
                p.first = p.second;
                p.second = temp1;
            }
            if(slope_is_negative){
                p.first = -p.first;
            }
            p.first += storex1;
            p.second += storey1; 
        }
        
        for(auto &p:v){
            DrawPoint(p.first,p.second);
        }
    }
    
	glEnd();
	glFlush();
}

int main(int argc, char** argv){
	

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("1st question");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}