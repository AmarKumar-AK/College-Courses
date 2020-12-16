g++ exp1_generate_random_number_ced17i029.cpp -o q1
./q1>exp1_output_random_number_q2_ced17i029.txt
g++ exp1_q2_ced17i029.cpp -fopenmp -o q2
export OMP_NUM_THREADS=1;
./q2<exp1_output_random_number_q2_ced17i029.txt >> exp1_execution_time_q2_ced17i029.txt;
export OMP_NUM_THREADS=2;
./q2<exp1_output_random_number_q2_ced17i029.txt >> exp1_execution_time_q2_ced17i029.txt;
export OMP_NUM_THREADS=4;
./q2<exp1_output_random_number_q2_ced17i029.txt >> exp1_execution_time_q2_ced17i029.txt;
export OMP_NUM_THREADS=6;
./q2<exp1_output_random_number_q2_ced17i029.txt >> exp1_execution_time_q2_ced17i029.txt;
export OMP_NUM_THREADS=8;
./q2<exp1_output_random_number_q2_ced17i029.txt >> exp1_execution_time_q2_ced17i029.txt;
export OMP_NUM_THREADS=10;
./q2<exp1_output_random_number_q2_ced17i029.txt >> exp1_execution_time_q2_ced17i029.txt;
export OMP_NUM_THREADS=12;
./q2<exp1_output_random_number_q2_ced17i029.txt >> exp1_execution_time_q2_ced17i029.txt;
export OMP_NUM_THREADS=14;
./q2<exp1_output_random_number_q2_ced17i029.txt >> exp1_execution_time_q2_ced17i029.txt;
export OMP_NUM_THREADS=16;
./q2<exp1_output_random_number_q2_ced17i029.txt >> exp1_execution_time_q2_ced17i029.txt;
export OMP_NUM_THREADS=20;
./q2<exp1_output_random_number_q2_ced17i029.txt >> exp1_execution_time_q2_ced17i029.txt;
export OMP_NUM_THREADS=24;
./q2<exp1_output_random_number_q2_ced17i029.txt >> exp1_execution_time_q2_ced17i029.txt;