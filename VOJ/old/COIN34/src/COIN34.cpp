//============================================================================
// Name        : COIN34.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct COIN{
	long long val; //gia tri
	int nCoin;//so coin.
};
long long coinValue[35];
long long mu[35];
COIN first[(1<<20)+1];
COIN last[(1<<14)+1];
int cmp(const void * a, const void *b){
	COIN* ia=(COIN*)a,*ib=(COIN*)b;
	int rs=ia->val - ib->val;
	if (rs>0) return 1;
	else if(rs<0) return -1;
	else return (ia->nCoin- ib->nCoin);
}
void init();
int main() {
	int i,nTest,n;
	init();
	//Tinh toan.
	/*
	scanf("%d",&nTest);
	for(i=1;i<=nTest;++i){
		scanf("%d",&n);
		//in ket qua luon.

	}

	cout<<"TEst coin\n"<<endl;
	for(i=1;i<=35;i++)
		cout<<coinValue[i]<<endl;
	cout<<"TEST Mu\n"<<endl;
		for(i=1;i<=34;i++)
			cout<<mu[i]<<endl;
	cout<<"TEST FIRST\n"<<endl;
			for(i=1;i<=30;i++)
				cout<<first[i].val<<' '<<first[i].nCoin<<endl;
	cout<<"TEST LASTT\n"<<endl;
			for(i=1;i<=30;i++)
				cout<<last[i].val<<' '<<last[i].nCoin<<endl;
	*/
	cout<<"XONG";
}
void init(){

	int i,j;
	//Khoi tao coinValue[]
	coinValue[1]=2;
	coinValue[2]=3;
	coinValue[3]=5;
	for(i=4;i<=34;++i)
		coinValue[i]=coinValue[i-1]+coinValue[i-2]+coinValue[i-3];
	//khoi tao mu[]
	mu[0]=1;
	for(i=1;i<=34;++i)
		mu[i]=mu[i-1]<<1;
	//Khoi tao first;
	long long lim=(1<<20);
	int numCoin=0;
	long long tVal=0;
	for(i=1;i<=lim;++i){
		numCoin=0;//so coin
		tVal=0;//gia tri
		for(j=0;j<=19;++j){
			if((i&mu[j])!=0)//bit thu j cua i la 1.
			{
				++numCoin;
				tVal+=coinValue[j+1];
			}
		}
		first[i].val=tVal;
		first[i].nCoin=numCoin;
	}
	qsort(first,lim,sizeof(COIN),cmp);
	//Khoi tao mang Last
	lim=mu[14];
	for(i=1;i<=lim;++i){
		numCoin=0;
		tVal=0;
		for(j=0;j<=14;++j){
			if((i&mu[j])!=0)//bit thu j cua i la 1.
			{
				++numCoin;
				tVal+=coinValue[20+j+1];
			}
		}
		last[i].val=tVal;
		last[i].nCoin=numCoin;
	}
	qsort(last,lim,sizeof(COIN),cmp);
}
