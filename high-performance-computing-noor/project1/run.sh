g++ main.cpp -lGL -lGLU -lglut -fopenmp -o test
export OMP_NUM_THREADS=1;
./test
rm test