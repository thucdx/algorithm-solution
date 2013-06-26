#include <iostream>
using namespace std;
#include <stdio.h>
#include <cstring>
#include <climits>
struct INFOR{
	int maxVal;
	int minVal;
};
#define MAX 50000
int h[MAX+5];
INFOR rs[4*MAX+5];
int n,maxV,minV;

void update(int k, int m,int n, int i);
void get(int k, int m,int n, int i, int j);
void init();
int main() {
	int q,i,x,y;
	scanf("%d%d",&n,&q);
	init();
	for(i=1;i<=n;++i){
		scanf("%d",&h[i]);
		update(1,1,n,i);
	}

	for(i=1;i<=q;++i){
		maxV=0;minV=1000001;
		scanf("%d%d",&x,&y);
		get(1,1,n,x,y);
		printf("%d\n",maxV-minV);
	}
}
void init(){
	for(int i=1;i<=n;++i){
		rs[i].maxVal=0;
		rs[i].minVal=1000001;
	}
}
void update(int k, int m, int n,int i){
	if(m>i || n<i) return;
	if(m==n){
		rs[k].maxVal=h[i];
		rs[k].minVal=h[i];
		return ;
	}
	int mid=(m+n)/2;
	update(2*k,m,mid,i);
	update(2*k+1,mid+1,n,i);
	rs[k].minVal=min(rs[2*k].minVal, rs[2*k+1].minVal);
	rs[k].maxVal=max(rs[2*k].maxVal, rs[2*k+1].maxVal);
}
void get(int k, int m, int n, int i, int j){
	if(m>j || n<i) return ;//doan khong chua
	if(i<=m && n<=j) //chua doan
	{
		maxV=max(maxV,rs[k].maxVal);
		minV=min(minV,rs[k].minVal);
		return ;
	}
	int mid=(m+n)/2;
	get(2*k, m,mid,i,j);
	get(2*k+1,mid+1,n,i,j);
}

