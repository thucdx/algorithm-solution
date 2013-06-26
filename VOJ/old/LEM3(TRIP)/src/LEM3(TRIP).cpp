#include <iostream>
#include <stdio.h>
#include <cstring>
#define INF 2250005
long long f[65537][16];

using namespace std;
int n;
int c[16][16];
void input();
void calc();
long min(long a ,long b){
	if(a<b) return a;
	else return b;
}
int main() {
	input();
	calc();
	return 0;
}
void input(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			scanf("%d",&c[i][j]);
		}
}
void calc(){
	int t,j,k;
	int max=(1<<n)-1;
	int tmp;
	for(t=1;t<=max;t++){
		//tim tat cac bit cua t la 1.
		for(j=0;j<n;j++){
			if((t&(1<<j))!=0)//bit thu j cua t la 1.
			{
				if(t==(1<<j)) {
					f[t][j]=0; continue;
				}
				else{
					f[t][j]=INF;
					for(k=0;k<n;k++){
						if(((t&(1<<k))!=0) && (k!=j)){
							tmp=t;
							tmp&=~(1<<j);
							f[t][j]=min(f[t][j],c[k][j]+f[tmp][k]);
						}
				}
				}
			}
		}
	}
	long long rs=1<<19;
	for(j=0;j<n;j++)
		if(rs>f[max][j])  rs=f[max][j];
	cout<<rs<<endl;
}
