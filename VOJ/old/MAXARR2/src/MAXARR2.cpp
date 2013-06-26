//============================================================================
// Name        : MAXARR2.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
int val[100005];
int rs[100005];
int max(int a,int b){
	if (a>b )return a;
	return b;
}
void init(){
	int i,j;
	val[0]=0;
	rs[0]=0;
	val[1]=1;
	rs[1]=1;
	for(i=2;i<=10004;++i)
	{	j=i>>1;
		if(i&1){
			val[i]=val[j]+val[j+1];
		}
		else val[i]=val[j];
		rs[i]=max(val[i],rs[i-1]);
	}
}
int main() {
	int nTest,i,n;
	cin>>nTest;
	init();
	for(i=1;i<=nTest;++i){
		scanf("%d",&n);
		printf("%d\n",rs[n]);
	}
}
