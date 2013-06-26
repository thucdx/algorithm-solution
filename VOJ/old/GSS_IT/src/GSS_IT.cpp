
#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include <climits>
struct NODE{
	int MLeft,MRight,Sum,MAll; //max from left, max from right, sum, max of all
};
NODE rs[200005];
int seq[50005];
int n;
int prev,res;
void init();
void update(int i,int x,int y);
void get(int i, int x,int y, int u, int v);
int main() {
	int q,x,y;
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;++i)
		scanf("%d",&seq[i]);
	update(1,1,n);
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		scanf("%d%d",&x,&y);
		prev=0;
		//res= –2147483647;
		res=INT_MIN;
		get(1,1,n,x,y);
		printf("%d\n",res);
	}
}
void init(){
	for(int i=1;i<=4*n;++i){
		rs[i].MAll=INT_MIN;
		rs[i].MLeft=INT_MIN;
		rs[i].MRight=INT_MIN;
		rs[i].Sum=0;
	}
}
void update(int i,int x,int y){
	if(x>y) return ;
	if(x==y) {
		rs[i].MLeft=seq[x];
		rs[i].MRight=seq[x];
		rs[i].Sum=seq[x];
		rs[i].MAll=seq[x];
		return ;
	}
	int mid=(x+y)/2;
	update(2*i,x,mid);
	update(2*i+1,mid+1,y);
	rs[i].MLeft=max(rs[2*i].MLeft,rs[2*i].Sum+rs[2*i+1].MLeft);
	rs[i].MRight=max(rs[2*i+1].MRight,rs[2*i+1].Sum+rs[2*i].MRight);
	rs[i].Sum= rs[2*i].Sum+ rs[2*i+1].Sum;
	rs[i].MAll= max(rs[2*i].MAll,rs[2*i+1].MAll);
	rs[i].MAll=max(rs[i].MAll,rs[2*i].MRight+rs[2*i+1].MLeft);


}
void get(int i, int x,int y, int u, int v){
	if(x>v || y<u) return;
	if(u<=x && y<=v){//trong doan
		res=max(max(res,rs[i].MAll),prev+rs[i].MLeft);
		prev= max(rs[i].MRight,prev+rs[i].Sum);
		return;
	}
	int mid=(x+y)/2;
	get(2*i,x,mid,u,v);
	get(2*i+1,mid+1,y,u,v);
}
