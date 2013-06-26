//============================================================================
// Name        : QBRECT.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main() {
	int m,n;
	int i,j,jpr;
	int a[1005];
	int h[1002],dp[1002];
	int res=0L;
	int tmp;
	scanf("%d%d",&m,&n);
	while(getchar()!='\n');
	for(i=0;i<=n;i++)
		h[i]=0;
	for(i=1;i<=m;++i){
		for(j=1;j<=n;++j)
		{
			scanf("%d",&a[j]);
		}
		for(j=1;j<=n;++j){
			if(a[j-1]==0) h[j]=0; else ++h[j];
			jpr=j;
			dp[0]=0;h[0]=-1;
			while(h[jpr]>=h[j]) jpr--;
			tmp=(j-jpr)*h[j];
			if(tmp>res) {
				res=tmp;
				//cout<<i<<' '<<' '<<j<<' '<<res<<' '<<jpr<<endl;
			}
		}
		//cout<<i<<endl;
	}
	cout<<res<<endl;
}
