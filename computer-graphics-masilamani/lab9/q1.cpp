#include<bits/stdc++.h>
#include <GL/glut.h>
using namespace std;
// width and height of screen
const int width = 1200, height = 600;
int num_vertices;
struct edge {
	// ymax -> highest y coordinate of the edge
	// ymin -> lowest y coordinate of the edge
	// xmin -> x coordinate of point whose y was ymin (it will change as we move on the scanline)
	// orxmin -> for keeping original value of xmin
	int ymax, xmin, ymin, orxmin;
	// delx -> absolute difference of x1 and x2
	// dely -> absolute difference of y1 and y2
	int delx, dely;
	// sign_of_slope - Either 1 or -1 based on whether the line is like "/" or "\"
	int sign_of_slope;
};
// scanline[i] -> contains all the edges whose ymin = i
vector<edge> scanline[width];
// highest y coordinate and lowest y coordinate in the polygon(figure drawn)
int lowest_y = 100000;
int highest_y = -100000;

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

// for storing properties of an edge
edge create_edge(pair<int, int> p1, pair<int, int> p2) {
	int x1 = p1.first, y1 = p1.second;
	int x2 = p2.first, y2 = p2.second;
	edge temp;
	temp.ymax = max(y1, y2),		temp.ymin = min(y1, y2);
	temp.xmin = (y1<y2) ? x1 : x2, 	temp.orxmin = temp.xmin;
	temp.delx = abs(x2 - x1), 		temp.dely = abs(y2 - y1);
	// if line is vertical the sign of slope doesn't matter
	// since slope is just for updating the x coordinate 
	int sign_of_slope;
	if(x1 != x2) temp.sign_of_slope = ((float(y2 - y1) / float(x2 - x1)) < 0) ? -1 : 1;
	
	return temp;
}

// for drawing points i.e horizontal line between two points
void display_line(float x0, float y0, float x1, float y1) {
	if (x0 > x1) {
		swap(x0, x1);
		swap(y0, y1);
	}	
	int x = round(x0),	y = round(y0);
	for(int i = x0; i < x1; ++i) DrawPoint(i, y);
}

// Scanline starts
void driver() {
	cout << "Running driver function\n";
	// aet is the Active edge table which consists of active edge undergoing scanline algorithm
	vector<edge> aet;
	// Sort each scanline[i] edges based on xmin coordinate
	for (int i = 0; i < width; i++)
		sort(scanline[i].begin(), scanline[i].end(), [](edge A,edge B){
			return A.xmin < B.xmin;
		});
	// i is basically the y coordinate of current scanline
	for (int i = lowest_y; i <= highest_y; i++) {
		// At each i update the active edge table
		for (int j = 0; j < aet.size(); j++){
			// For all edges in aet we have finished drawing, remove them
			if (aet[j].ymax <= i) {
				aet.erase(aet.begin() + j);
				j--;
			}
			// If the edge is a vertical line no need to update xmin
			// Update the xmin using the line equation and the current y coordinate we are on
			// using x = x1 + (y - y1)/m
			if (aet[j].delx != 0){
				float x1 = aet[j].orxmin, y1 = aet[j].ymin;
				float sign = aet[j].sign_of_slope;
				float m = (float(aet[j].dely)/float(aet[j].delx));
				aet[j].xmin  = x1 + sign*(i - y1) / m;
			}
		}
		// inserting active scanline to active edge table
		aet.insert(aet.end(), scanline[i].begin(), scanline[i].end());
		// insertion may change the order, so we are sorting again
		sort(aet.begin(), aet.end(), [](edge A,edge B){
			return A.xmin < B.xmin;
		});

		// if size of aet is greater than 2 then only we have to draw otherwise it will be blank space
		if (aet.size() >=2) {
			// lines should be drawn alternatively because if size of aet is 4 then we have a gap between two scanline which do not have to be drawn 
			int x1,y1,x2,y2;
			for (int l = 0; l < aet.size() - 1; l+=2) {
				x1 = aet[l].xmin; y1 = i;
				x2 = aet[l+1].xmin; y2 = i;				
				display_line(x1, y1, x2, y2);
			}
		}
	}
	cout << "\nDone\n";
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	driver();
	glEnd();
	glFlush();
}

int main(int argc, char** argv){
	// reading vertices
	freopen("input2.txt", "r", stdin);
	int temp1, temp2, tempymin;
	edge temp;
	// storing points
	vector<pair<int, int>> points;
	// reading number of vertices from input file
	cin >> num_vertices;
	for (int i = 0; i < num_vertices; i++) {
		cin >> temp1 >> temp2;
		points.push_back(make_pair(temp1, temp2));
		// update the highest y value and lowest y value encountered till now
		lowest_y = min(temp2, lowest_y);
		highest_y = max(temp2, highest_y);
	}

	for (int i = 1; i < num_vertices; i++) {
		// we need to create edge only when it is not horizontal
		if ((points[i].second - points[i-1].second)) {
			// cout<<"points[i] : "<<points[i].first<<" , "<<points[i].second<<"  points[i-1] : "<<points[i-1].first<<" , "<<points[i-1].second<<endl;
			temp = create_edge(points[i], points[i-1]);
			// cout<<"xmin : "<<temp.xmin<<"  ymax : "<<temp.ymax<<" delx : "<<temp.delx<<" dely : "<<temp.dely<<" ymin : "<<temp.ymin<<" orxmin : "<<temp.orxmin<<endl; 
			// insert that edge at the scanline at lowest y coordinate among the points
			tempymin = min(points[i].second,points[i-1].second);
			// cout<<"tepymin : "<<tempymin<<endl;
			// insert this edge to the scanline with index of least y
			scanline[tempymin].push_back(temp);
		}
	}
	// Seperate case for creating edge between 0 and (n - 1)
	if ((points[0].second - points[num_vertices-1].second)) {
		temp = create_edge(points[0], points[num_vertices-1]);
		tempymin = min(points[0].second,points[num_vertices-1].second);
		scanline[tempymin].push_back(temp);
	}

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