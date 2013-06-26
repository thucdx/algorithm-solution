//============================================================================
// Name        : NKTICK.cpp
// Author      : ThucDX
// Version     :
// Copyright   : NKTICK
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
#define max 60000
int n;
int t[max];
int r[max];
int f[max];
int minInt(int a,int b);
int main() {
	int i,j;
	//input
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&t[i]);
	for(i=0;i<n-1;i++)
		scanf("%d",&r[i]);
	//qui hoach dong.
	f[0]=t[0];
	f[1]=minInt(t[0]+t[1],r[0]);
	for(j=2;j<n;j++){
		f[j]=minInt(f[j-1]+t[j],f[j-2]+r[j-1]);
	}
	cout<<f[n-1]<<endl;
}
int minInt(int a, int b){
	if(a<b) return a;
	else return b;
}

