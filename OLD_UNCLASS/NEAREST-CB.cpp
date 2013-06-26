//============================================================================
// Name        : CapDiemGanNhat_PhienbanXapxi.cpp
// Author      : ThucDX
// Version     :
// Copyright   : CapDiemGanNhat
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <iterator>

#define area 100
struct p{
	float x;
	float y;
}list[100000];
int n;
int cmp(const void* a, const void *b){
	p *ia=(p *)a;
	p *ib= (p *)b;
	if(ia->x > ib->x) return 1;
	else return -1;
}
float distance(p a, p b);
float minF(float a, float b);
float nearest(int start,int end);
int main() {
	int i;
	//Input
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%f%f",&list[i].x,&list[i].y);
	}
	//
	qsort(list,n,sizeof(list[0]),cmp);
	cout<<nearest(0,n-1);
}
float distance(p a, p b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
float minF(float a, float b){
	if(a>b) return b;
	else return a;
}
float nearest(int start, int end){
	float minL,minR,minLR,minFinal;
	if(end==start+2){
		float rs=distance(list[start],list[start+1]);
		if(rs> distance(list[start],list[start+2])) rs=distance(list[start],list[start+2]);
		if(rs> distance(list[start+1],list[start+2])) rs=distance(list[start+1],list[start+2]);
		return rs;
	}
	if(end==start+1){
		return distance(list[start],list[end]);
	}
	//chia de tri.
	//find x.
	minL=nearest(start,(start+end)/2);
	minR=nearest((start+end)/2+1,end);

	minLR=minF(minL, minR);

	//Tim cap diem, 1 ben trai, 1 ben phai.
	int i,j,mid;
	mid=(start+end)/2;
	minFinal=minLR;
	i=mid;
	while(list[i].x+minLR>=list[mid].x){
		//Tim tat ca j xung quanh.
		if(mid+1>end) break;
		j=mid+1;
		while(list[j].x<=list[mid].x+minLR){
			float tDis=distance(list[i],list[j]);
				if(tDis<minFinal) minFinal=tDis;
			j++;
			if(j>end) break;
		}
		i--;
		if(i<start) break;
	}
	return minFinal;

}
