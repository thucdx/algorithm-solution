//============================================================================
// Name        : BONUS.cpp
// Author      : ThucDX
// Version     :
// Copyright   : BONUS
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
#define max 1000
int n,k;
int sumMax=0;
int b[max][max];
int v[max][max];
int h[max][max];
int f[max][max];
void input();
void init();
void process();
int main() {
	input();
	init();
	process();
}
void input(){
	int i,j;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&b[i][j]);
}
void init(){
	//tinh v[i][j];h[i][j]
	int i,j;
	for(i=0;i<n;i++)
	{	v[0][i]=b[0][i];
		h[i][0]=b[i][0];
		for(j=1;j<n;j++)
		{
			v[j][i]=v[j-1][i]+b[j][i];
			h[i][j]=h[i][j-1]+b[i][j];
		}
	}
}
void process(){
	int i,j;
	f[k-1][k-1]=0;
	//tinh f[k-1][k-1];
	for(i=0;i<k;i++)
	{
		f[k-1][k-1]+=h[i][k-1];
	}

	if(f[k-1][k-1]>sumMax) sumMax=f[k-1][k-1];
	//cout<<f[k-1][k-1]<<endl;
	//tinh f[i][k-1];
	for(i=k;i<n;i++)
	{
		f[i][k-1]=f[i-1][k-1]-h[i-k][k-1]+h[i][k-1];
		if(f[i][k-1]>sumMax) sumMax=f[i][k-1];
		//cout<<i<<' '<<k<<' '<<h[i][k-1]<<' '<<f[i][k-1]<<endl;
	}
	for(i=k;i<n;i++)
		{
			f[k-1][i]=f[k-1][i-1]-v[k-1][i-k]+v[k-1][i];
			if(f[k-1][i]>sumMax) sumMax=f[k-1][i];
			//cout<<i<<' '<<f[k-1][i]<<endl;
		}
	for(i=k;i<n;i++)
		for(j=k;j<n;j++){
			f[i][j]=f[i][j-1]-(v[i][j-k]-v[i-k][j-k])+ (v[i][j]-v[i-k][j]);
			//cout<<v[i][j-k]-v[i-k][j-k]<< ' '<<v[i][j]-v[i-k][j]<<endl;
			//cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
			if(f[i][j]>sumMax) sumMax=f[i][j];
		}
	cout<<sumMax<<endl;
}

