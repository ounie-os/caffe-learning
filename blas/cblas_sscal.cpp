#include <vector>  
#include <iostream>  
#include <cblas.h>

using namespace std;

/*
Multiplies each element of a vector by a constant (single-precision).

void cblas_sscal(const int __N, const float __alpha, float *__X, const int __incX);

Parameters
N
Number of elements to scale.

alpha
The constant to multiply by.

X
Vector x.

incX
Stride within X. For example, if incX is 7, every 7th element is multiplied by alpha.

*/

int main(void)
{
	float X[] = {0.1, 0.3, 0.7};
	int N = 3;
	float alpha = 0.4;
	
	cblas_sscal(N, alpha, X, 1);
	
	for (int i=0; i<3; i++)
		cout << X[i] << endl;
}