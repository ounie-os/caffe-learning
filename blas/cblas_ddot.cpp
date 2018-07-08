#include <vector>  
#include <iostream>  
#include <cblas.h>

using namespace std;

/*

float cblas_sdot(const int __N, const float *__X, const int __incX, const float *__Y, const int __incY);

Parameters
N
The number of elements in the vectors.

X
Vector X.

incX
Stride within X. For example, if incX is 7, every 7th element is used.

Y
Vector Y.

incY
Stride within Y. For example, if incY is 7, every 7th element is used.

*/

float X[3] = {1,2,3};
float Y[3] = {4,5,6};


int main(void)
{
	cout << cblas_sdot(3, X, 1, Y, 1) << endl;

	return 0;
}
