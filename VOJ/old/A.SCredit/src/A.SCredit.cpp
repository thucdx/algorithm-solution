//============================================================================
// Name        : SCredit.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
#define max 1000
int list[max+1];
int credit,nItem;
int f[2000][1001];
bool choose[max+1];
void input();
int maxL(int a, int b);
void calc(int i);
int main() {
	input();
	calc();
}
int maxL(int a,int b){
	if(a>credit){
		if(b<=credit) return b;
		else
			return 0;
	}
	else {
		if(b<=credit){
			if(a<b) return a;
			else return b;
		}
		else return a;
	}
}
void input(){
	int i;
	cin>>credit;
	cin>>nItem;
	for(i=1;i<=nItem;++i){
		scanf("%d",&list[i]);
	}
}
void calc(){
	int i,j;
	//khooi tao
	for(i=0;i<=nItem;++i)
	{	for(j=0;j<=credit;++j)
			f[i][j]=0;
	}
	f[1][credit]=(list[1]<credit? list[1]: 0);
	for(i=2;i<=nItem;++i){

	}


}
