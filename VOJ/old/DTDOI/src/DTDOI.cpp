//============================================================================
// Name        : DTDOI.cpp
// Author      : ThucDX
// Version     :
// Copyright   : DTDOI
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int n,dollar;
int l[102];
int f[100001];
int soTo=0;
int minTo;
int moneyLeft;
int cmp(const void * a, const void *b){
	return (*(int *)a - *(int *)b);
}
int min(int a,int b)
{
	if(a<b) return a;
	return b;
}
void att(int i);
int main() {
	int i,j;
	cin >>n>>dollar;
	for(i=0;i<n;++i)
		scanf("%d",&l[i]);
	qsort(l, n, sizeof(l[0]),cmp);
	soTo=0;
	soTo+=(dollar-10000)/l[n-1];
	dollar=dollar-(dollar-10000)/l[n-1]* l[n-1];
	f[0]=0;
	for(i=1;i<=dollar;i++)
	{
		f[i]=1000005;
		for(j=0;j<n;j++)
		{
			if(l[j]<=i) f[i]= min(f[i],1+f[i-l[j]]);
			else break;
		}
	}
	soTo+=f[dollar];
	cout<<soTo<<endl;
}
void att(int i){
	if(i==-1){
		if(soTo<minTo && moneyLeft==0) minTo=soTo; return;
	}
	if(soTo>minTo) return;
	int j;
	int maxTo=moneyLeft/l[i];
	int lim=min(l[i+1]-1,maxTo);
	for(j=lim;j>=0;--j){
		moneyLeft-=j*l[i];
		soTo+=j;
		att(i-1);
		moneyLeft+=j*l[i];
		soTo-=j;
	}
}
