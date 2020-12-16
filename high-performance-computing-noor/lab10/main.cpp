
#include<bits/stdc++.h>
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

// this function finds the updated pizza center location
void findUpdatedMeanPosition(){
	float x_avg,y_avg;
	// #pragma omp parallel for reduction(+:x_avg,y_avg)
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

	for(int i=0 ; i<num_iteration ; ++i){
		// printMean();
		pizzaCenterAreaCovered();
		findUpdatedMeanPosition();
		// each location may be assigned to a particular pizza center, so it should be cleared
		// not clearing last points because we need to plot the location and final pizza center after applying algorithm
		if(i!=num_iteration-1){
			for(int j=0 ; j<num_pizza_center ; ++j){
				points[j].clear();
			}
		}
	}
	return 0;
}