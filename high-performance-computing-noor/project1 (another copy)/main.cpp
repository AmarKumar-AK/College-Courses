#include<bits/stdc++.h>
#include<omp.h>
#include<GL/glut.h>
using namespace std;
const int width = 1200, height = 600;
const int num_data_points = 1000;
const int num_pizza_center=8;
const int num_iteration=15;
int x[num_data_points],y[num_data_points];
int kx[num_pizza_center],ky[num_pizza_center];
vector<pair<float,float>> points[num_pizza_center];
const float colour[10][3] = {{1.0,0.0,0.0}, // red
							{0.0,1.0,0.0}, // green
							{0.0,0.0,1.0}, //blue
							{1.0,1.0,0.0}, // yellow
							{1.0,0.0,1.0}, // magenta
							{0.0,1.0,1.0}, // cyan
							{1.0,0.5,0.0}, // orange
							{0.49,0.4,1.0}, // violet
							{0.7,0.7,0.7}, // gray
							{0.0,0.0,0.0}}; // black
// vector<float>distances[num_pizza_center];

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
}
void drawPoint(int x, int y,int col_position,float point_size) {
    // glColor3f(get<0>(color),get<1>(color),get<2>(color));
	glColor3f(colour[col_position][0],colour[col_position][1],colour[col_position][2]);
    glPointSize(point_size);
	glBegin(GL_POINTS);
		glVertex3i(x, y, 0);
	glEnd();
	glFlush();
}
void displayInitialDataPoint(){
    // tuple<float,float,float>col;
    // col = make_tuple(colour[6]);
	int col_index = 9;
    for(int i=0 ; i<num_data_points ; ++i){
        drawPoint(x[i],y[i],col_index,4.0);
    }
    // col = make_tuple(1.0,0.0,0.0);
	// col_position=0;
    for(int i=0 ; i<num_pizza_center ; ++i){
        drawPoint(kx[i],ky[i],col_index,10.0);
    }
}
void displayFinalDataPoints(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	// tuple<float,float,float>col;
    // col = make_tuple(0.0,1.0,0.0);
	// for(int i=0 ; i<num_data_points ; ++i){
	// 	drawPoint(x[i],y[i],col,4.0);
	// }
	// col = make_tuple(1.0,0.0,0.0);
	// int col_position = 0;
	for(int i=0 ; i<num_pizza_center ; ++i){
		for(auto k:points[i]){
			drawPoint(k.first,k.second,i,4.0);
		}
	}
	// for(auto k:points[0]){
	// 	drawPoint(k.first,k.second,col_position,4.0);
	// }
	// // col = make_tuple(0.0,1.0,0.0);
	// col_position = 1;
	// for(auto k:points[1]){
	// 	drawPoint(k.first,k.second,col_position,4.0);
	// }
	// // col = make_tuple(0.0,0.0,1.0);
	// col_position = 2;
	// for(auto k:points[2]){
	// 	drawPoint(k.first,k.second,col_position,4.0);
	// }
	// glClearColor(1.0, 1.0, 1.0, 0.0);
	// col = make_tuple(0.0,0.0,1.0);
	int col_position = 0;
	for(int i=0 ; i<num_pizza_center ; ++i){
        drawPoint(kx[i],ky[i],col_position,10.0);
    }
}

void findUpdatedMeanPosition(){
	// cout<<"updated mean position : ";
	for(int i=0 ; i<num_pizza_center ; ++i){
		float x_avg=0,y_avg=0;
		for(auto x: points[i]){
			x_avg +=x.first;
			y_avg +=x.second;
		}
		kx[i] = x_avg/points[i].size();
		ky[i] = y_avg/points[i].size();
		// kx[i] = accumulate(points[i].begin()->first,points[i].end()->first,0.0);
		// kx[i] /= points[i].size(); 
		// ky[i] = accumulate(points[i].begin()->second,points[i].end()->second,0.0);
		// ky[i] /= points[i].size();
		// cout<<"("<<kx[i]<<","<<ky[i]<<")  ";
	}
	cout<<endl;
}
inline float calculateDistance(float x1, float y1, float x2, float y2){
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
void updateMean(){
	vector<float>dist;
	cout<<"current mean positions are : ";
	for(int i=0 ; i<num_pizza_center ; ++i){
		cout<<"("<<kx[i]<<","<<ky[i]<<")  ";	
	}
	cout<<endl;
	// cout<<"current mean position are ("<<kx[0]<<","<<ky[0]<<")  ("<<kx[1]<<","<<ky[1]<<")  (" <<kx[2]<<","<<ky[2]<<")"<<endl;
	// for(int k=0 ; k<num_iteration ; ++k){
		for(int i=0 ; i<num_data_points ; ++i){
			for(int j=0 ; j<num_pizza_center ; ++j){
				float dis = calculateDistance(kx[j],ky[j],x[i],y[i]);
				dist.push_back(dis);
			}
			// float min_dist = *min_element(dist.begin(),dist.end());
			int index = distance(dist.begin(),min_element(dist.begin(),dist.end()));
			points[index].push_back({x[i],y[i]});
			// distances[index].push_back(min_dist);
			dist.clear();
		}
		// findUpdatedMeanPosition();
		// for(int j=0 ; j<num_pizza_center ; ++i){
		// 	points[j].clear();
		// }
	// }
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
    displayInitialDataPoint();
	for(int i=0 ; i<num_iteration ; ++i){
		updateMean();
		findUpdatedMeanPosition();
		if(i!=num_iteration-1){
			for(int j=0 ; j<num_pizza_center ; ++j){
				points[j].clear();
			}
		}
	}
	// for(int i=0 ; i<num_pizza_center ; ++i){
	// 	displayFinalDataPoints();
	// }
	displayFinalDataPoints();
	glEnd();
	glFlush();
}

void readData(){
    freopen("data.txt", "r", stdin);
    for(int i=0 ; i<num_data_points ; ++i){
        cin>>x[i]>>y[i];
    }
    for(int i=0 ; i<num_pizza_center ; ++i){
        cin>>kx[i]>>ky[i];
    }
}


int main(int argc, char** argv){
	readData();
    
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