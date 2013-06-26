//============================================================================
// Name        : ETFSol3.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
#include <cstring>
#include <math.h>
int calc(int );
int main() {
	int nTest,i,n;
		scanf("%d",&nTest);
		for(i=1;i<=nTest;++i){
			scanf("%d",&n);
			printf("%d\n",calc(n));
		}
}

int calc(int n){
	int lim=sqrt(n)+1,i,result=n;
	for(i=2;i<=lim;++i){
		if(i>n) break;
		if(n%i==0){
			result-=result/i;
		}
		while(n%i==0) n/=i;
	}
	if(n>1) result-=result/n;
	return result;
}
