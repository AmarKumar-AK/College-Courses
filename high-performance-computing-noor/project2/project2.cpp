#include<bits/stdc++.h>
#include<mpi.h>
#define MASTER 0
using namespace std;
// total number of data_points
const int num_data_points = 100000;
// number of pizza centers required to open
// maximum number of pizza centers should be 100 as i have added only and 100 locations of pizza centers
const int num_pizza_center = 100;
// number of iteration for finding the best possible location for pizza center in order to deliver a location fastest
const int num_iteration = 50;
// x and y coordinates of the data points
int x[num_data_points], y[num_data_points];

int kx[num_pizza_center], ky[num_pizza_center];
// data points belonging to the k pizza centers
vector<pair<float, float>> points[num_pizza_center];
// for storing distance of a location from every pizza center
vector<float>dist;

float calculateDistance(float x1, float y1, float x2, float y2){
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

void printMean(){
	cout<<"current mean positions are : ";
	for(int i=0 ; i<num_pizza_center ; ++i){
		cout<<"("<<kx[i]<<","<<ky[i]<<") ";
	}
	cout<<endl;

}

void readData(){
	freopen("data1.txt", "r", stdin);
	for(int i=0 ; i<num_data_points ; ++i){
		cin>>x[i]>>y[i];
	}
	for(int i=0 ; i<num_pizza_center ; ++i){
		cin>>kx[i]>>ky[i];
	}

}
int main(int argc, char *argv[]){
	int rank, total_proc;
	int namelen;
	int n_per_proc;
	int s,s0, si, ei;
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &total_proc);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Get_processor_name(processor_name, &namelen);
	if(rank == MASTER){
		// for calculating number of tasks per processor
		s = (int)floor(num_data_points/total_proc);
		// total number of tasks done by master process
		s0 = s + num_data_points%total_proc;
	}	
	MPI_Bcast(&s, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
	MPI_Bcast(&s0, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
	// starting index of worker
	si = s0 + (rank-1)%s;
	// ending index of worker
	ei = si + s;
	readData();
	double start;
	if(rank == MASTER){
		// starting wall clock time
		start = MPI_Wtime();
	}
	for(int i=0 ; i<num_iteration ; ++i){
	//	pizzaCenterAreaCovered();/////////////////////////////////////////////////////////////////
//		printMean();	
		if(rank == MASTER){	
			for(int i=0 ; i<s0 ; ++i){
				float temp1 = x[i], temp2 = y[i];
				for(int j=0 ; j<num_pizza_center ; ++j){
					dist.push_back(calculateDistance(kx[j],ky[j],temp1,temp2));
				}
				int index = distance(dist.begin(),min_element(dist.begin(),dist.end()));
				points[index].push_back({x[i], y[i]});
				dist.clear();
			}			
		}
		else{
			for(int i=si ; i<ei ; ++i){
				float temp1 = x[i], temp2 = y[i];
				for(int j=0 ; j<num_pizza_center ; ++j){
					dist.push_back(calculateDistance(kx[j],ky[j],temp1,temp2));
				}	
				int index = distance(dist.begin(),min_element(dist.begin(),dist.end()));
				points[index].push_back({x[i], y[i]});
				dist.clear();
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////
		//findUpdatedMeanPosition();////////////////////////////////////////////////////////
		float x_avg, y_avg;
		vector<pair<float,float> >::iterator j;
		for(int i=0; i<num_pizza_center; ++i){
			x_avg=0, y_avg=0;
			for(auto x: points[i]){
				x_avg +=x.first;
				y_avg +=x.second;
			}
			kx[i] = x_avg/points[i].size();
			ky[i] = y_avg/points[i].size();
		}
		///////////////////////////////////////////////////////////////////////////////////
		if(i != num_iteration-1){
			for(int j=0 ; j<num_pizza_center ; ++j){
				points[j].clear();
			}
		}
	}
	double end;
	if(rank == MASTER){
		// ending wall clock time
		end = MPI_Wtime();
		cout<<"execution time : "<<end-start<<"sec"<<endl;
	}	
	MPI_Finalize();
	return 0;
}
