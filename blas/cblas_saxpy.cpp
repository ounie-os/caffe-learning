#include <vector>  
#include <iostream>  
#include <cblas.h>

using namespace std;

/*
Computes a constant times a vector plus a vector (single-precision).

void cblas_saxpy(const int __N, const float __alpha, const float *__X, const int __incX, float *__Y, const int __incY);

Parameters
N
Number of elements in the vectors.

alpha
Scaling factor for the values in X.

X
Input vector X.

incX
Stride within X. For example, if incX is 7, every 7th element is used.

Y
Input vector Y.

incY
Stride within Y. For example, if incY is 7, every 7th element is used.

Discussion
On return, the contents of vector Y are replaced with the result. The value computed is (alpha * X[i]) + Y[i].

*/

int main(void)
{
	int N = 3;
	float alpha = 2;
	float X[] = {0.1, 0.2, 0.3};
	float Y[] = {0.5, 0.6, 0.7};
	
	cblas_saxpy(N, alpha, X, 1, Y, 1);
	cout << Y[0] << endl;
	cout << Y[1] << endl;
	cout << Y[2] << endl;
}