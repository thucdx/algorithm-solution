//============================================================================
// Name        : SQUARES.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
using namespace std;
int n;
bool prime[1000005];
int phi(int i);
void makePrime();
int main() {
	long long result=0,i;
	scanf("%d",&n);
	makePrime();
	//cout<<"Done make Prime"<<endl;
	for(i=1;i<=(n-1);i++){
		if(n%i==0)
			result+=(phi(n/i+1)>>1);
	}
	result+=1;
	cout<<result<<endl;
}
int phi(int i){
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
void makePrime(){
	int i,j,limit=sqrt(n)+1;
	memset(prime,1,n);
	prime[0]=0;
	prime[1]=0;
	for(i=2;i<=limit;i++){
		if(prime[i]){
			j=i*i;
			while(j<=n){
				prime[j]=0;
				j+=i;
			}
		}

	}
	//cout<<"DONE";
}
