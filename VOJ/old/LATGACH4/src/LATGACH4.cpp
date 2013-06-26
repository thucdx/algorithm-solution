//============================================================================
// Name        : LATGACH4.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * Dat W_k la ma tran 2x1( 2 dong,1 cot) [F_(k+1),F_k]^(-1)
 * thi co cong thuc: W_k= A. W_(k-1) voi A =[1,1]
 * _________________________________________[1,0]
 * => W_n=A^(n-2). W_2 .
 *
 *  W_2 biet roi nen chi can tinh A^(n-2) bang phuong phap chia doi.
 */
#include <iostream>
#include <stdio.h>
#define REMAIN 111539786
using namespace std;
struct matrix{
	long long a11,a12,a21,a22;
	void operator=(matrix b){
		a11=b.a11;
		a12=b.a12;
		a21=b.a21;
		a22=b.a22;
	}
};
inline matrix mu(matrix mat, long long n);
inline matrix nhan(matrix A, matrix B);
int main() {
	matrix a,b;
	int i,nTest,n;
	a.a11=1;
	a.a12=1;
	a.a21=1;
	a.a22=0;
	scanf("%d",&nTest);
	for(i=1;i<=nTest;++i){
		scanf("%d",&n);
		switch(n){
		case 1: printf("%d\n",1);break;
		case 2: printf("%d\n",2);break;
		default:
			b=mu(a,n-2);
			printf("%d\n",((b.a11<<1)+b.a12)%REMAIN);
			break;
		}
	}

}
matrix mu(matrix mat, long long n){
	if(n==1) return mat;
	matrix tmp,result;
	tmp=mu(mat,n>>1);
	result=nhan(tmp,tmp);
	if(n&1)//n le
		result=nhan(result,mat);
	return result;
}
matrix nhan(matrix A, matrix B){
	matrix result;
	result.a11= (A.a11*B.a11+A.a12*B.a21)%REMAIN;
	result.a12= (A.a11*B.a21+A.a12*B.a22)%REMAIN;
	result.a21= (A.a21*B.a11+A.a22*B.a21)%REMAIN;
	result.a22= (A.a21*B.a12+A.a22*B.a22)%REMAIN;
	return result;
}
