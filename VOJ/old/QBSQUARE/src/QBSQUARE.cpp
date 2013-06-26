//============================================================================
// Name        : QBSQUARE.cpp
// Author      : ThucDX
// Version     :
// Copyright   : QBSQUARE
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
#define max 1001

int m,n;
int g[max][max];
int f[max][max];
inline void input();
inline void calc();
inline int minInt(int, int ,int);
int main() {
	input();
	calc();
}
void input(){
	int i,j;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;++i )//m dong
		for(j=0;j<n;++j){
			scanf("%d",&g[i][j]);
		}
}
int minInt(int a, int b,int c){
	int rs=a;
	if(rs>b) rs=b;
	if(rs>c) rs=c;
	return rs;
}
void calc(){
	int i,j;
	int maxL=0;
	for(i=0;i<n;++i)
		f[0][i]=1;
	for(i=0;i<m;++i)
		f[i][0]=1;
	for(i=1;i<m;++i)
		for(j=1;j<n;++j){
			if(3*g[i][j]==g[i-1][j]+g[i-1][j-1]+g[i-1][j-1])
				f[i][j]=minInt(f[i-1][j],f[i][j-1],f[i-1][j-1])+1;
			else f[i][j]=1;
			if(f[i][j]>maxL) maxL=f[i][j];
		}
	printf("%d\n",maxL);
}
