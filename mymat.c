/*
 * Program: mymat.c
 * Purpose: reads a positive integer n followed by an n-by-n matrix from the
 *  standard input and prints whether it is one of the special matrices.
 *  The input matrix must be stored in a two-dimensional array of integers
 *  dynamically allocated during run-time using malloc().
 *  sorted list of the products in the increasing of their cost/square inch.
 * Author: Mehmet Turhan
 * Date:   11/12/2021
 */
#include <stdio.h>
#include <stdlib.h>

int isdiag(int *mat, int n);
int isident(int *mat, int n);
int isuppertri(int *mat, int n);
int islowertri(int *mat, int n);
int issym(int *mat, int n);
void getmat(int *mat, int n);


void main(){
  int size;
  int *matrix;
  scanf("%d\n", &size);
  matrix = (int *) malloc(size*size*(sizeof(int)));
  getmat(matrix,size);
  if(isuppertri(matrix, size)){
    printf("It's an upper triangular matrix.\n");;
  }
  if(islowertri(matrix, size)){
    printf("It's a lower triangular matrix.\n");;
  }
  if(isdiag(matrix, size)){
    printf("It's a diagonal matrix.\n");;
  }
  if(issym(matrix, size)){
    printf("It's a symmetric matrix.\n");;
  }
  if(isident(matrix, size)){
    printf("It's an identity matrix.\n");;
  }

}

/*
 * Function: getmat
 * Purpose:   reads input matrix
 *
 * Parameters:
 *    mat: input matrix
 *    n: 1 dimensional size of the matrix
 *
 * Returns: NA
 *
 */
void getmat(int *mat, int n){
  int row, col;
  int var;

  for (row = 0; row < n; row++) {
    for (col = 0; col < n; col++) {
      scanf("%d\n", &var);
      mat[row * n + col] = var;
    }
  }
  for (row = 0; row < n; row++) {
    for (col = 0; col < n; col++) {
      printf("%d",mat[row * n + col] );
    }
    printf("\n");
  }
}

/*
 * Function: isuppertri
 * Purpose: returns 1, when the n-by-n matrix have its sub-diagonal elements are
 *  all zero and 0 otherwise.
 *
 * Parameters:
 *    mat: input matrix
 *    n: 1 dimensional size of the matrix
 *
 * Returns:
 *    1: if its sub-diagonal elements are all zero
 *    0: if its sub-diagonal elements have atleast one non-zero variable.
 */
int isuppertri(int *mat, int n){
  int row, col;
  int var;
  int check=1;
  for (row = 1; row < n; row++) {
    for (col = 0; col < row-1; col++) {
      if(mat[row * n + col] != 0){
        return 0;
      }
    }
  }
  return check;
}

/*
 * Function: islowertri
 * Purpose: returns 1, when the n-by-n matrix have its super-diagonal elements are
 *  all zero and 0 otherwise.
 *
 * Parameters:
 *    mat: input matrix
 *    n: 1 dimensional size of the matrix
 *
 * Returns:
 *    1: if its super-diagonal elements are all zero
 *    0: if its super-diagonal elements have atleast one non-zero variable.
 */
int islowertri(int *mat, int n){
  int row, col;
  int var;
  int check=1;
  for (row = 0; row < n; row++) {
    for (col = row+1; col < n-1; col++) {
      if(mat[row * n + col] != 0){
        return 0;
      }
    }
  }
  return check;
}

/*
 * Function: isdiag
 * Purpose: returns 1, when the n-by-n matrix have its off-diagonal elements are
 *  all zero and 0 otherwise.
 *
 * Parameters:
 *    mat: input matrix
 *    n: 1 dimensional size of the matrix
 *
 * Returns:
 *    1: if its off-diagonal elements are all zero
 *    0: if its off-diagonal elements have atleast one non-zero variable.
 */
int isdiag(int *mat, int n){
  if(islowertri(mat, n) && isuppertri(mat, n)){
    return 1;
  }
  else{
    return 0;
  }
}

/*
 * Function: issym
 * Purpose: returns 1, when the n-by-n matrix have M[i][j] = M[j][i]
 *  for all values of i and j
 *
 * Parameters:
 *    mat: input matrix
 *    n: 1 dimensional size of the matrix
 *
 * Returns:
 *    1: if M[i][j] = M[j][i] for all values of i and j
 *    0: if M[i][j] != M[j][i] for all values of i and j
 */
int issym(int *mat, int n){
  int row, col;
  int var1;
  int var2;
  int check=1;
  for (row = 0; row < n; row++) {
    for (col = 0; col < n; col++) {
      var1=mat[row * n + col];
      var2=mat[col * n + row];
      if(var1!=var2){
        return 0;
      }
    }
  }
  return check;
}

/*
 * Function: isident
 * Purpose: returns 1, when the n-by-n matrix is diagonal and have its diagonal elements are
 *  all one and 0 otherwise.
 *
 * Parameters:
 *    mat: input matrix
 *    n: 1 dimensional size of the matrix
 *
 * Returns:
 *    1: diagonal and if its diagonal elements are all one
 *    0: non diagonal or if its diagonal elements have atleast one non-one variable.
 */
int isident(int *mat, int n){
  int row, col;
  int var;
  int check=1;
  if(!isdiag(mat, n)){
    return 0;
  }
  for (row = 0; row < n; row++) {
    if(mat[row * n + row] != 1){
      return 0;
    }
  }
  return check;
}
