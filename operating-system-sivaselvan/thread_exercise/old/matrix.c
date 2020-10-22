//matrix inverse using determinant
#include<stdio.h>
#include<math.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#define N 4
struct node{
    int **a;
};

void readMatrix(int order, float (*matrix)[order]){
    printf("enter %d X %d matrix\n",order,order);
    for(int i=0 ; i<order ; ++i){
        for(int j=0 ; j<order ; ++j){
            scanf("%f",&matrix[i][j]);
        }
    }
}
void printMatrix(int order,float (*matrix)[order]){
    printf("\nmatrix is : \n");
    for(int i=0 ; i<order ; ++i){
        for(int j=0 ; j<order ; ++j){
            printf("%f ",matrix[i][j]);
        }
        printf("\n");
    }
}


  
// Function to get cofactor of mat[p][q] in temp[][]. n is current 
// dimension of mat[][] 
void getCofactor(float mat[N][N], float temp[N][N], int p, int q, int n) 
{ 
    int i = 0, j = 0; 
  
    // Looping for each element of the matrix 
    for (int row = 0; row < n; row++) 
    { 
        for (int col = 0; col < n; col++) 
        { 
            //  Copying into temporary matrix only those element 
            //  which are not in given row and column 
            if (row != p && col != q) 
            { 
                temp[i][j++] = mat[row][col]; 
  
                // Row is filled, so increase row index and 
                // reset col index 
                if (j == n - 1) 
                { 
                    j = 0; 
                    i++; 
                } 
            } 
        } 
    } 
} 
  
/* Recursive function for finding determinant of matrix. 
   n is current dimension of mat[][]. */
float determinantOfMatrix(float mat[N][N], int n) { 
    float D = 0; // Initialize result 
    //  Base case : if matrix contains single element 
    if (n == 1) 
        return mat[0][0]; 
    // float temp[N][N]; // To store cofactors 
    int sign = 1;  // To store sign multiplier 
     // Iterate for each element of first row 
    for (int f = 0; f < n; f++) { 
        // Getting Cofactor of mat[0][f] 
        // getCofactor(mat, temp, 0, f, n); 
        D += sign * mat[0][f] * determinantOfMatrix(temp, n - 1); 
  
        // terms are to be added with alternate sign 
        sign = -sign; 
    } 
    return D; 
} 

int main(int argc, char const *argv[]){
    int order;
    printf("enter the order of matrix : ");
    scanf("%d",&order);
    float matrix[order][order];

    readMatrix(order,matrix);
    printMatrix(order,matrix);
    float det = determinantOfMatrix(matrix,order);
    printf("determinant is %f\n",det);
    // if(det == 0){
    //     printf("Inverse of the matrix is not possible\n");
    // }
    // else{
    //     cofactor(matrix, order);
    // }
    return 0;
}







































// float findDeterminant(int order, float (*matrix)[order]){
//     float sign = 1, det = 0, b[order][order];
//     int m, n;
//     if (order == 1){
//      return (matrix[0][0]);
//     }
//     else{
//         det = 0;
//         for (int c = 0; c < order; c++){
//             m = 0;
//             n = 0;
//             for (int i = 0;i < order; i++){
//                 for (int j = 0 ;j < order; j++){
//                     b[i][j] = 0;
//                     if (i != 0 && j != c){
//                         b[m][n] = matrix[i][j];
//                         if (n < (order - 2)){
//                             n++;
//                         }
//                         else{
//                             n = 0;
//                             m++;
//                         }
//                     }
//                 }
//             }
//             det = det + sign * (matrix[0][c] * findDeterminant(order-1, b));
//             sign = -1 * sign;
//         }
//     }
//     return (det);
// }

// void transpose(int order, float fac[order][order], float (*matrix)[order] ){
//     int i, j;
//     float b[order][order], inverse[order][order], d;
//     for (i = 0;i < order; i++){
//         for (j = 0;j < order; j++){
//          b[i][j] = fac[j][i];
//         }
//     }
//     d = findDeterminant(order,matrix);
//     for (i = 0;i < order; i++){
//         for (j = 0;j < order; j++){
//             inverse[i][j] = b[i][j] / d;
//         }
//     }
//     printf("\n\n\nThe inverse of matrix is : \n");
//     for (i = 0;i < order; i++){
//         for (j = 0;j < order; j++){
//             printf("\t%f", inverse[i][j]);
//         }
//         printf("\n");
//     }
// }


// void cofactor(int order, float (*matrix)[order]){
//     float b[order][order], fac[order][order];
//     int p, q, m, n, i, j;
//     for (q = 0;q < order; q++){
//         for (p = 0;p < order; p++){
//             m = 0;
//             n = 0;
//             for (i = 0;i < order; i++){
//                 for (j = 0;j < order; j++){
//                     if (i != q && j != p){
//                         b[m][n] = matrix[i][j];
//                         if (n < (order - 2)){
//                             n++;
//                         }
//                         else{
//                             n = 0;
//                             m++;
//                         }
//                     }
//                 }
//             }
//             fac[q][p] = pow(-1, (q + p)) * findDeterminant(order - 1, b);
//         }
//     }
//   transpose(order, fac, matrix);
// }

