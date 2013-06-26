//============================================================================
// Name        : NKCABLE.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int list[25005];
long long f[25005];
long long min(long long, long long);
int main() {
	int i;
	scanf("%d",&n);
	for(i=1;i<n;i++)
		scanf("%d",&list[i]);
	f[1]=0;
	f[2]=list[1];
	f[3]=list[1]+list[2];
	for(i=4;i<=n;i++){
		f[i]=min(f[i-1],f[i-2])+list[i-1];
	}
	cout<<f[n]<<endl;
}
long long min(long long a, long long b){
	if (a>b) return b;
	return a;
}
