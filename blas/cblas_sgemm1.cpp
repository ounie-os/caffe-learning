#include <vector>  
#include <iostream>  
#include <cblas.h>

using namespace std;

/*
参数 transA和transB ：表示矩阵A，B是否进行转置。候选参数 CblasTrans 和CblasNoTrans.

参数M：表示 A或C的行数。如果A转置，则表示转置后的行数

参数N：表示 B或C的列数。如果B转置，则表示转置后的列数。

参数K：表示 A的列数或B的行数（A的列数=B的行数）。如果A转置，则表示转置后的列数。

参数LDA：填A的行数

参数LDB：填B的行数

参数LDC：始终=N
*/

  
int main() {  
    const int M=2;  
    const int N=1;  
    const int K=1;  
    const float alpha=1;  
    const float beta=0;
	
	const float A[M*K]={1,1};  
    const float B[K*N]={3};  
    float C[M*N];
	const int ldc=N; //C的列数	
	
    const int lda=K; //A的列数 
    const int ldb=N; //B的列数 
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);  
  
    for(int i=0;i<M;i++)  
    {  
       for(int j=0;j<N;j++)  
       {  
           cout<<C[i*N+j]<<" ";  
       }  
       cout<<endl;  
    }
}