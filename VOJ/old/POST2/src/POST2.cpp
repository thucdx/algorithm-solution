//============================================================================
// Name        : POST2.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
#define max 250000
int A[10001],B[10001];
bool f[max];
int num=0;
int n;
#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int i,j,c;
	scanf("%d",&n);
	//memset(f,0,n+1);
	for(i=1;i<=n;++i){
		scanf("%d",&A[i]);
	}
	for(i=1;i<=n;++i){
			scanf("%d",&B[i]);
	}
	for(i=1;i<=n;++i){
			scanf("%d",&c);
			f[c+50000]=true;
	}
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j){
			if(f[A[i]+B[j]+50000]) ++num;
		}
	printf("%d\n",num);
	return 0;
}
