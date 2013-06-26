//============================================================================
// Name        : QBSELECT.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
#define NEG -400000
int n;
int b[4][10005];
int list[]={0,1,2,4,5,8,9,10};

int f[10005][11];
void input();
void calc();
inline bool check(int i,int j);
inline int value(int, int);
inline int maxInt(int, int);
int main() {
	input();
	calc();
}
bool check(int i,int j){
	int t;
	for(t=0;t<4;t++){
		if(((i&(1<<t))!=0) && ((j&(1<<t))!=0))
				return false;
	}
	return true;
}
int maxInt(int a, int b){
	if (a>b) return a;
	else return b;
}
int value(int i,int j) //dong i, gia tri trang thai j
{
	int t;
	int result=0;
	for(t=0;t<4;t++){
		if((j&(1<<t))!=0) //bit thu t cua j la 1.
			result+=b[t][i];
	}
	return result;
}
void input(){
	int i,j;
	scanf("%d",&n);
	for(j=0;j<4;++j)
		for(i=0;i<n;++i){
			scanf("%d",&b[j][i]);
		}
}
void calc(){
	int i,j,t;
	int max=NEG,max2;
	int tmp;

	//khoi tao.
	for(i=0;i<8;++i){
		f[0][list[i]]=value(0,list[i]);
	}
	for(i=1;i<n;++i){
		for(j=0;j<8;++j){
			f[i][list[j]]=NEG;
			for(t=0;t<8;++t){
				if(check(list[t],list[j])){ //khong xung dot
					tmp=f[i-1][list[t]]+value(i,list[j]);
					if (f[i][list[j]]<tmp) f[i][list[j]]=tmp;

				}
			}
		}
	}
	//Tinh max
	max=maxInt(max,f[n-1][list[0]]);
	for(i=1;i<8;++i){
		max=maxInt(max,f[n-1][list[i]]);
	}
	if(max==0){
	max2=b[0][0];
		for(i=0;i<4;i++)
			for(j=0;j<n;j++)
				if(b[i][j]>max2) max2=b[i][j];
	}
	if(max2<0) max=max2;
	cout<<max<<endl;
}
