//============================================================================
// Name        : PCDIV.cpp
// Author      : ThucDX
// Version     :
// Copyright   : DTDOI
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
long long a,b;
int n;
long long calc();
long long div(long long );
int main() {
	int i;
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",calc());
	}
	return 0;
}
long long div(long long n){
	long long nA=(a-1)/n+1;
	if(a==0) nA=1;
	long long nB=b/n+1;
	return nB-nA;
}
long long calc()
{
	return (div(12)+div(30)-2*div(60));
}
