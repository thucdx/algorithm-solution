//============================================================================
// Name        : GCDSUM.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
#include <cstring>
#define max 1000005

bool prime[max+1];
int a[max+1];
long long G[max+1];
int n;
long result=0;
void makePrime();
void makeA();
void calc();
int gcd(int a, int b);
int main() {
	makePrime();
	makeA();
	calc();
	int n;
	do{
		scanf("%d",&n);
		if(n==0) break;
		cout<<G[n]<<endl;
	}
	while(true);
}
int gcd(int a, int b){
	int tmp;
	while(b!=0){
		tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;
}
void calc(){
	int i,j,m,u;
	memset(G,0,max);

	for(i=2;i<=max;++i){
		if(prime[i]){
			G[i]=i-1;
			for(j=(i<<1);j<=max;j+=i){
				if(G[j]!=0) continue;
				m=j/i;
				if(G[m]==0) continue;
				u=gcd(j,a[i]);
				G[j]=G[m]*i+(i-1)*m+ G[j/u]* (i-1)*(u/i);
			}
		}
	}
	for(i=2;i<=max;i++)
		G[i]+=G[i-1];
}
void makePrime(){
	int i,j,limit=1001;
	memset(prime,1,max);
	prime[0]=0;
	prime[1]=0;
	for(i=2;i<=limit;i++){
		if(prime[i]){
			j=i*i;
			while(j<=max){
				prime[j]=false;
				j+=i;
			}
		}
	}

}
void makeA(){
	int i;
	for(i=2;i<=max;i++){
		if(prime[i]){ //i la so nguyen to
			a[i]=(int)pow((int)i,(int)(log(max)/log(i)));
			///cout<<i<<' '<<a[i]<<endl;
		}
	}
}
/*
 *void init(){
	int i,j;
	int add;
	rs[1]=1;
	rs[2]=4;
	for(i=3;i<=1000000;i++){
		add=0;
		for(j=1;j<=(i>>1);++j){
			if(i%j==0)
				add+=j*phi[n/j];
		}
		add+=i;
		rs[i]=rs[i-1]+add;

	}

}
void makePhi(){
	int i;
	phi[1]=0;
	for(i=2;i<=10000;++i){
		phi[i]=cphi(i);
	}
}
int cphi(int i){
	if(prime[i]) return (i-1);
	int result=i,limit=i/2,j;
	for(j=2;j<=limit;++j){
		if(prime[j]){
			if(i%j==0){
				result=result/j*(j-1);
			}
		}
	}
	return result;
}
 * */


