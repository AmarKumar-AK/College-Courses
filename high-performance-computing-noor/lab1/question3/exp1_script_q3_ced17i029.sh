g++ exp1_generate_random_number_ced17i029.cpp -o q1
./q1>exp1_output_random_number_q3_ced17i029.txt
g++ exp1_q3_ced17i029.cpp -fopenmp -o q3
export OMP_NUM_THREADS=1;
./q3<exp1_output_random_number_q3_ced17i029.txt >> exp1_execution_time_q3_ced17i029.txt;
export OMP_NUM_THREADS=2;
./q3<exp1_output_random_number_q3_ced17i029.txt >> exp1_execution_time_q3_ced17i029.txt;
export OMP_NUM_THREADS=4;
./q3<exp1_output_random_number_q3_ced17i029.txt >> exp1_execution_time_q3_ced17i029.txt;
export OMP_NUM_THREADS=6;
./q3<exp1_output_random_number_q3_ced17i029.txt >> exp1_execution_time_q3_ced17i029.txt;
export OMP_NUM_THREADS=8;
./q3<exp1_output_random_number_q3_ced17i029.txt >> exp1_execution_time_q3_ced17i029.txt;
export OMP_NUM_THREADS=10;
./q3<exp1_output_random_number_q3_ced17i029.txt >> exp1_execution_time_q3_ced17i029.txt;
export OMP_NUM_THREADS=12;
./q3<exp1_output_random_number_q3_ced17i029.txt >> exp1_execution_time_q3_ced17i029.txt;
export OMP_NUM_THREADS=14;
./q3<exp1_output_random_number_q3_ced17i029.txt >> exp1_execution_time_q3_ced17i029.txt;
export OMP_NUM_THREADS=16;
./q3<exp1_output_random_number_q3_ced17i029.txt >> exp1_execution_time_q3_ced17i029.txt;
export OMP_NUM_THREADS=20;
./q3<exp1_output_random_number_q3_ced17i029.txt >> exp1_execution_time_q3_ced17i029.txt;
export OMP_NUM_THREADS=24;
./q3<exp1_output_random_number_q3_ced17i029.txt >> exp1_execution_time_q3_ced17i029.txt;