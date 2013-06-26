#include <iostream>
using namespace std;
#include <algorithm>
#include <math.h>
#include <stdio.h>

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
float dist(p a, p b);
float minF(float a, float b);
float nearest(int start,int end);
int main() {
	int i;
	//Input
	do{
		scanf("%d",&n);
		if(n==0) break;
		for(i=0;i<n;i++){
			scanf("%f%f",&list[i].x,&list[i].y);
		}
		//
		qsort(list,n,sizeof(list[0]),cmp);
		float rs=nearest(0,n-1);
		if(rs>=10000) printf("INFINITY\n");
		else
			printf("%.4f\n",rs);
	}
	while(true);
}
float dist(p a, p b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
float minF(float a, float b){
	if(a>b) return b;
	else return a;
}
float nearest(int start, int end){
	float minL,minR,minLR,minFinal;
	if(end==start+2){
		float rs=dist(list[start],list[start+1]);
		if(rs> dist(list[start],list[start+2])) rs=dist(list[start],list[start+2]);
		if(rs> dist(list[start+1],list[start+2])) rs=dist(list[start+1],list[start+2]);
		return rs;
	}
	if(end==start+1){
		return dist(list[start],list[end]);
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
		while(list[j].x<=list[i].x+minLR){
			if (!(list[i].y+minLR>list[j].y && list[j].y>list[i].y-minLR))
				{
					j++;
					if(j>end) break;
					else
						continue;
				}
			float tDis=dist(list[i],list[j]);
				if(tDis<minFinal) minFinal=tDis;
			j++;
			if(j>end) break;
		}
		i--;
		if(i<start) break;
	}
	return minFinal;
}
