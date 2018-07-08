#include <vector>  
#include <iostream>  
#include <cblas.h>

using namespace std;

/*
矩阵与向量相乘

Parameters
Order
Specifies row-major (C) or column-major (Fortran) data ordering.

TransA
Specifies whether to transpose matrix A.

M
Number of rows in matrix A.

N
Number of columns in matrix A.

alpha
Scaling factor for the product of matrix A and vector X.

A
Matrix A.

lda
The size of the first dimention of matrix A; if you are passing a matrix A[m][n], the value should be m.

X
Vector X.

incX
Stride within X. For example, if incX is 7, every 7th element is used.

beta
Scaling factor for vector Y.

Y
Vector Y

incY
Stride within Y. For example, if incY is 7, every 7th element is used.

Y←αAX + βY

void cblas_sgemv(const enum CBLAS_ORDER __Order, const enum CBLAS_TRANSPOSE __TransA, const int __M, const int __N, const float __alpha, const float *__A, const int __lda, const float *__X, const int __incX, const float __beta, float *__Y, const int __incY);
*/

/*
没有转置前：
A = M * N = 3 * 2, 即
     1  2               4
A =  3  4   此时， X =  
     5  6               5
转置之后：
     1  3  5               4
A =           此时， X =   5
     2  4  6               6
*/

int main(void)
{
	int M = 3;
	int N = 2;
	float alpha =1.;
	float A[M*N] = {1,2,3,4,5,6};
	int lda = N;
	float X[M] = {4,5,6};
	int incX = 1;
	float beta = 0;
	float Y[M];
	int incY = 1;
	
	cblas_sgemv(CblasRowMajor, CblasNoTrans, M, N, alpha, A, lda, X, incX, beta, Y, incY);
	
	cout << Y[0] << endl;
	cout << Y[1] << endl;
	cout << Y[2] << endl;
	
	cblas_sgemv(CblasRowMajor, CblasTrans, M, N, alpha, A, lda, X, incX, beta, Y, incY);
	
	cout << Y[0] << endl;
	cout << Y[1] << endl;

	return 0;
}
