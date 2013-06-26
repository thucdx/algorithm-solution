//============================================================================
// Name        : GPMB.cpp
// Author      : ThucDX
// Version     :
// Copyright   : GPMB
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 100000.0 //when
#define NEG -10000.0
int maxMoney=0;
int nHouse;
struct house{
	int x,y,s;//xi,yi,si;
}Houses[1501];
struct noname{
	float a;
	int s;
}nn[1501];

inline void input();
inline void calc();
inline int cmp(const void *a, const void *b);
int main() {
	input();
	calc();
	return 0;
}
void input(){
	int i;
	scanf("%d",&nHouse);
	for(i=0;i<nHouse;i++){
		scanf("%d%d%d",&Houses[i].x,&Houses[i].y,&Houses[i].s);
	}
}
int cmp(const void *a, const void *b){
	noname *ia=(noname*)a;
	noname *ib=(noname*)b;
	if(ia->a >ib->a) return 1;
	return -1;
}
void calc(){
	int i,j;
	int money=0;
	for(i=0;i<nHouse-1;i++){
		//Tao he so goc
		for(j=i+1;j<nHouse;j++){
				nn[j-i-1].s=Houses[j].s;
				if(Houses[j].y==Houses[i].y) nn[j-i-1].a=INF;
				else nn[j-i-1].a= (1.0*Houses[j].x-Houses[i].x)/((Houses[j].y-Houses[i].y));
		}
		//Qsort
		qsort(nn,nHouse-1-i, sizeof(nn[0]),cmp);
		//Tinh max;
		int fix=(Houses[i].s *Houses[i].s)+5;
		int b;
		money=fix;
		j=i+1;
		while(j<nHouse){
			b=nn[j-1-i].s;
			money=fix+b*b+5;
			if(j+1<nHouse)
				while(nn[j-1-i].a==nn[j+1-1-i].a){
					b=nn[j+1-1-i].s;
					money+= b*b+5;
					j++;
					if(j>=nHouse) break;
				}
			//cout<<j-i-1<<' '<<money<<endl;
			if(money>maxMoney) maxMoney=money;
			j++;
		}
		//cout<<"het "<<i<<"with maxmoney= "<<money<<endl;
	}
	printf("%d\n",maxMoney);
}
