//============================================================================
// Name        : CREC01.cpp
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
	char a[1005];
	int h[1002],dp[1002];
	long long res=0L;
	scanf("%d%d",&m,&n);
	while(getchar()!='\n');
	for(i=0;i<=n;i++)
		h[i]=0;
	for(i=1;i<=m;++i){
		scanf("%s",a);
		//cout<<a<<endl;
		for(j=1;j<=n;++j){
			if(a[j-1]=='0') h[j]=0; else ++h[j];
			jpr=j;
			dp[0]=0;h[0]=-1;
			while(h[jpr]>=h[j]) jpr--;
			dp[j]=(j-jpr)*h[j]+dp[jpr];
			//cout<<i<<' '<<j<<' '<<dp[j]<<endl;
			res+=dp[j];

		}
		//cout<<i<<endl;
	}
	cout<<res<<endl;
}
