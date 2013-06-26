//============================================================================
// Name        : FINDNUM.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;
#define max 1005
bool prime[max+1];
int p[max+1];
int listGCD[max+1];
int num;
long long result;
int n;
long long mu(int ,int);//a^b;
void makePrime();
void calc();
int main() {
	//cin>>n;
	for(int i=1;i<=1000;++i)
		{
		num=0;result=1;
		n=i;
		makePrime();
		cout<<"TEST n="<<i<<' '<<prime[i]<<endl;
		calc();
		cout<<endl;
		}
}
void makePrime(){
	int i,j,lim=sqrt(n)+1;
	for(i=0;i<=n;i++){
		prime[i]=true;
	}
	prime[0]=false;
	prime[1]=false;
	for(i=2;i<=lim;++i){
		if(prime[i]){
			p[num]=i;
			++num;
			j=i*i;
			while(j<=n){
				prime[j]=false;
				j+=i;
			}
		}
	}
	for(i=lim+1;i<=n;++i)
		if(prime[i])
		{
			p[num]=i;
			++num;
		}
}
long long mu(int a,int b){
	if (b==0) return 1L;
	if(b==1) return a;
	long long tmp=mu(a,b/2);
	if(b%2==0) {
		return tmp*tmp;
	}
	else return (a*tmp*tmp);
}
void calc(){
	int tmp=n,i;
	int nPrime=0;
	i=2;
	while(i<=tmp){
		if(tmp%i==0){
			listGCD[nPrime]=i;
			++nPrime;
			tmp/=i;
			//cout<<i<<' '<<tmp<<endl;
		}
		else ++i;
	}
	//Tinh
	result=1;
	if(nPrime==0) result=mu(2,n-1);
	else{
		for(i=0;i<nPrime;++i){
			result*=mu(p[i],listGCD[nPrime-1-i]-1);
		}
	}
	cout<<result<<endl;
}
