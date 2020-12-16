
#include<bits/stdc++.h>
#include<omp.h>
#include<GL/glut.h>
using namespace std;
// width and height of the screen which plots the data points
const int width = 1200, height = 600;
// total number of data points
const int num_data_points = 1000;
// number of pizza centers required to open
// maximum number of pizza center should be 10 as i have added only 10 colours and 10 locations of pizza center
const int num_pizza_center=10;
// number of iteration for finding the best possible location for pizza center in order to deliver a location fastest
const int num_iteration=1000;
// x and y coordinates of the data points
int x[num_data_points],y[num_data_points];
// initial mean of the data points(generated using random.randInt in gen_dataset.py file)
int kx[num_pizza_center],ky[num_pizza_center];
// data points belonging to the k pizza centers
vector<pair<float,float>> points[num_pizza_center];
// for storing distance of a location from every pizza center
vector<float>dist;
// colours used for plotting points
const float colour[10][3] = {{1.0,0.0,0.0}, // red
							{0.0,1.0,0.0}, // green
							{0.0,0.0,1.0}, //blue
							{1.0,1.0,0.0}, // yellow
							{1.0,0.0,1.0}, // magenta
							{0.0,1.0,1.0}, // cyan
							{1.0,0.5,0.0}, // orange
							{0.7,0.7,0.7}, // gray
							{0.15,0.86,0.48}, // some variant of green
							{0.0,0.0,0.0}}; // black

// this function initializes the background colour, pointer size , pointer color etc.
void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
}

// given the coordinates of a point, its colour index and point size
// this function draw that point
void drawPoint(int x, int y,int col_position,float point_size) {
	glColor3f(colour[col_position][0],colour[col_position][1],colour[col_position][2]);
    glPointSize(point_size);
	glBegin(GL_POINTS);
		glVertex3i(x, y, 0);
	glEnd();
	glFlush();
}

// this function displays initial data points
void displayInitialDataPoint(){
	int col_index = 9;
	#pragma omp parallel for shared(x,y) schedule(static)
    for(int i=0 ; i<num_data_points ; ++i){
		// for displaying locations
        drawPoint(x[i],y[i],col_index,4.0);
    }

    for(int i=0 ; i<num_pizza_center ; ++i){
		// for displaying pizza center location
        drawPoint(kx[i],ky[i],col_index,10.0);
    }
}
// this function is displaying pizza center location and location which comes under a particular pizza center 
void displayFinalDataPoints(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	for(int i=0 ; i<num_pizza_center ; ++i){
		for(auto k:points[i]){
			// for displaying locations according to the area under it in different colour
			drawPoint(k.first,k.second,i,4.0);
		}
		// for displaying pizza center location
		drawPoint(kx[i],ky[i],i,10.0);
	}
}

// this function finds the updated pizza center location
void findUpdatedMeanPosition(){
	float x_avg,y_avg;
	#pragma omp parallel for reduction(+:x_avg,y_avg)
	for(int i=0 ; i<num_pizza_center ; ++i){
		x_avg=0,y_avg=0;
		for(auto x: points[i]){
			x_avg +=x.first;
			y_avg +=x.second;
		}
		kx[i] = x_avg/points[i].size();
		ky[i] = y_avg/points[i].size();
	}
	// cout<<endl;
}

// this function calculates the euclidean distance of a particular location and a pizza center
float calculateDistance(float x1, float y1, float x2, float y2){
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
void printMean(){
	cout<<"current mean positions are : ";
	for(int i=0 ; i<num_pizza_center ; ++i){
		cout<<"("<<kx[i]<<","<<ky[i]<<")  ";	
	}
	cout<<endl;
}
// this function calculates which location should belong to which pizza center so that distance between them is minimum
void pizzaCenterAreaCovered(){
	// printMean();
	for(int i=0 ; i<num_data_points ; ++i){
		float temp1 = x[i], temp2 = y[i]; 
		for(int j=0 ; j<num_pizza_center ; ++j){
			// calculating distance of each location from pizza centers
			dist.push_back(calculateDistance(kx[j],ky[j],temp1,temp2));
		}
		// finding the index of pizza center which has least distance from a particular location
		int index = distance(dist.begin(),min_element(dist.begin(),dist.end()));
		// inserting the coordinates of location which has least distance from a particular pizza center
		points[index].push_back({x[i],y[i]});
		// clearing distance because when pizza center location is updated according to the algorithm then its distance from each points may also change
		dist.clear();
	}
}

// this function is used to display purpose
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
    displayInitialDataPoint();
	double start = omp_get_wtime();
	for(int i=0 ; i<num_iteration ; ++i){
		pizzaCenterAreaCovered();
		findUpdatedMeanPosition();
		// each location may be assigned to a particular pizza center, so it should be cleared
		// not clearing last points because we need to plot the location and final pizza center after applying algorithm
		if(i!=num_iteration-1){
			#pragma omp parallel for shared(points) schedule(static)
			for(int j=0 ; j<num_pizza_center ; ++j){
				points[j].clear();
			}
		}
	}
	double end = omp_get_wtime();
	cout<<"execution time : "<<end-start<<"sec"<<endl;

	displayFinalDataPoints();
	glEnd();
	glFlush();
}

void readData(){
	// opening datasets(data.txt) in read mode
    freopen("data.txt", "r", stdin);
	// reading data points from file
    for(int i=0 ; i<num_data_points ; ++i){
        cin>>x[i]>>y[i];
    }
	// reading pizza center coordinates
    for(int i=0 ; i<num_pizza_center ; ++i){
        cin>>kx[i]>>ky[i];
    }
}


int main(int argc, char** argv){
	readData();
    
	// initializing glut(graphics library), window size, window position, title of windows etc.
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("K-Mean clustering implementation(openMP)");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}