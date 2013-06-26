//============================================================================
// Name        : CPRIME.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <cstring>
#include <stdio.h>
#include <math.h>
#define max 100000005
#define max2 10000005
bool prime[max];
int n[max2];
inline void makePrime();
inline void init();
int main() {
	int num,i;
	float rs;
	makePrime();
	init();
	do{
		scanf("%d",&num);
		if(num==0) break;
		if(num<=max2){
			rs=(n[num]-num/log(num))/n[num]*100;

		}
		else
		{
			int nPrime=n[max2-1];
			for(i=max2;i<=num;++i)
				if(prime[i]) ++nPrime;
			rs=(nPrime-num/log(num))/nPrime*100;
		}
		if(rs<0) rs=-rs;
		printf("%.1f\n",rs);
	}while(true);

}
void makePrime(){
	memset(prime,1,max-1);
	prime[0]=0;
	prime[1]=0;
	int limit=sqrt(max-1)+1;
	int i,j;
	for(i=2;i<=limit;++i){
		if(prime[i]){
			j=i*i;
			while(j<=max-1){
				prime[j]=0;
				j+=i;
			}
		}
	}
}
void init(){
	//n[i] so so nguyen to nho hon i.
	int i;
	n[0]=0;
	n[1]=0;
	n[2]=1;
	for(i=3;i<=max2-1;i+=2)
	{
		n[i]=n[i-1]+prime[i];
		n[i+1]=n[i];
	}
}
