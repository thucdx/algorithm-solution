//============================================================================
// Name        : PAGAIN.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
#define nTest 15
int list[nTest+1];
inline bool check(int n);
inline int mod(int a,int d,int n);//a^d mod n;
int main() {
	int i,j,n,test,start;
	for(i=1;i<=nTest;i++)
		list[i]=i+4;
	scanf("%d",&test);
	for(i=1;i<=test;i++){
		scanf("%d",&n);
		start=n-1;
		if(n%2==1) --start;
		for(j=start;j>=2;--j)
			if(check(j)) {printf("%d",j);cout<<endl;break;}
	}

}

bool check(int n){
	if(n==2) return true;
	if(n%2==0) return false;
	if(n==3) return true;
	int i,x,k,s,r,a;
	bool isContinue=true;
	//srand(time(NULL));
	//Tack n-1 =2^k.s;
	//Chi check so le.
	k=0;
	s=n-1;
	while(s%2==0){
		k++;
		s=s>>1;
	}
	//cout<<n-1<<"="<<"2 my"<<k<<"."<<s<<endl;

	for(i=1;i<=nTest;i++){
		isContinue=false;
		//a=rand()%(n-3)+2; //chon 1 so ngau nhien
		//cout<<"Test "<<i<<": "<<a<<endl;
		a=list[i];
		if(a%n==0) a=a+2;
		x=mod(a,s,n);
		if(x==1 ||x==(n-1)) continue;//next test
		for(r=1;r<=k-1;r++){
			x=x*x%n;
			if(x==1) return false;
			if(x==n-1) {isContinue=true; break;}
		}
		if(isContinue) continue;
		else return false;
	}
	return true;
}

int mod(int a,int n, int m)
{
     int remain=1;
     int save=a;
     while(n!=0)
     {

        if(n%2==1)
         remain=remain*save%m;
        save=(save*save)%m;
        n=n/2;
     }
     return remain;
}
