## for running program, you must have openGL and openMP library installed



## for compiling the program, type : 
g++ main.cpp -lGL -lGLU -lglut -fopenmp -o test



## then type :
export OMP_NUM_THREADS=1; 
## for taking the input of number of threads



## then type :
./test
## to run the program 