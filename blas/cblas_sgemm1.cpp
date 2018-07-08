#include <vector>  
#include <iostream>  
#include <cblas.h>

using namespace std;

/*
���� transA��transB ����ʾ����A��B�Ƿ����ת�á���ѡ���� CblasTrans ��CblasNoTrans.

����M����ʾ A��C�����������Aת�ã����ʾת�ú������

����N����ʾ B��C�����������Bת�ã����ʾת�ú��������

����K����ʾ A��������B��������A������=B�������������Aת�ã����ʾת�ú��������

����LDA����A������

����LDB����B������

����LDC��ʼ��=N
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
	const int ldc=N; //C������	
	
    const int lda=K; //A������ 
    const int ldb=N; //B������ 
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