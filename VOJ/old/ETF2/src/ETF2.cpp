//============================================================================
// Name        : ETF2.cpp
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
#define max 1000005
bool p[max+2];
int numPrime=0;
int list[max+2];
int n;
void makePrime();
int calc();
int main() {
	int nTest,i;
	makePrime();
	scanf("%d",&nTest);
	for(i=1;i<=nTest;++i){
		scanf("%d",&n);
		printf("%d\n",calc());
	}

}
void makePrime(){
	int i,j,lim=sqrt(max)+1;
	numPrime=0;
	memset(p,1,max+1);
	p[0]=0;p[1]=0;
	for(i=2;i<=lim;++i){
		if(p[i]){
			++numPrime;
			list[numPrime-1]=i;
			j=i*i;
			while(j<=max){
				p[j]=false;
				j+=i;
			}
		}
	}
	for(i=lim+1;i<=max;++i){
		if(p[i])
		{
			++numPrime;
			list[numPrime-1]=i;
		}
	}
}
int calc(){
	if(p[n]) return (n-1);
	int result=n,i,lim=n>>1;
/*
	for(i=2;i<=lim;++i){
		if(p[i]&&(n%i==0)){
			result=result*(i-1)/i;
		}
	}
	*/
	i=0;
	while(list[i]<=lim){
		if(n%list[i]==0)
			result=result*(list[i]-1)/list[i];
		i++;
	}
	return result;
}
