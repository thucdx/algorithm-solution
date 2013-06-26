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
#define NEG -800000001
int n;
int b[8][10005];
int list[256];
bool chk[256][256];
long long f[2][256];
int sizeofList;
void input();
void calc();
inline bool check(long long i,long long j);
inline long long value(long long, long long);
void makeList();
void makeChk();
int main() {
	makeList();
	makeChk();
	input();
	calc();
}
void makeList(){
	sizeofList=0;
	int i,t;
	bool isOk;
	for(i=0;i<=255;++i){
		isOk=true;
		//check xem i co thoa man.
		for(t=0;t<7;t++){
			if(((i&(1<<t))!=0)&&(((i&(1<<(t+1)))!=0)))
			{	isOk=false;
				break;
			}
		}
		if(isOk){
			sizeofList++;
			list[sizeofList]=i;
			//cout<<i<<endl;
		}
	}
	sizeofList++;
}
void makeChk(){
	int i,j;
	for(i=0;i<sizeofList;i++){
		for(j=0;j<sizeofList;j++){
			chk[i][j]=check(list[i],list[j]);
		}
	}
}
bool check(long long i,long long j){
	int t;
	for(t=0;t<8;t++){
		if(((i&(1<<t))!=0) && ((j&(1<<t))!=0))
				return false;
	}
	return true;
}

long long value(long long i,long long j) //dong i, gia tri trang thai j
{
	int t;
	long long result=0;
	for(t=0;t<8;t++){
		if((j&(1<<t))!=0) //bit thu t cua j la 1.
			result+=b[t][i];
	}
	return result;
}
void input(){
	int i,j;
	scanf("%d",&n);
	for(j=0;j<8;++j)
		for(i=0;i<n;++i){
			scanf("%d",&b[j][i]);
		}
}
void calc(){
	int  i,j,t;
	long long max=NEG,max2;
	long long tmp;

	//khoi tao.
	//cout<<list[sizeofList-1];
	for(i=0;i<sizeofList;++i){
		f[0][list[i]]=value(0,list[i]);
	}
	for(i=1;i<n;++i){
		for(j=0;j<sizeofList;++j){
			f[i%2][list[j]]=NEG;
			for(t=0;t<sizeofList;++t){
				//if(check(list[t],list[j]))
				if (chk[t][j]){ //khong xung dot
					tmp=f[(i+1)%2][list[t]]+value(i,list[j]);
					if (f[i%2][list[j]]<tmp) f[i%2][list[j]]=tmp;
				}
			}
		}
	}
	//Tinh max
	int col=(n-1)%2;
	max=f[col][list[0]];
	for(i=1;i<sizeofList;++i){
		if(max<f[col][list[i]]) max=f[col][list[i]];
	}
	if(max==0){
		max2=b[0][0];
		for(i=0;i<sizeofList;i++)
			for(j=0;j<n;j++)
				if(b[i][j]>max2) max2=b[i][j];
		if(max2<0) max=max2;
	}

	cout<<max<<endl;
}
