

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <climits>
#define MAX 1000000000
using namespace std;
int a[22];
int mu[22];
int rs[(1<<22)];
int n;
void init();
void input();
void calc();
int main() {
     input();
     init();
     calc();
}
void input(){
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		 scanf("%d",&a[i]);
	}
}
void init(){
	mu[0]=1;
	for(int i=1;i<=21;++i)
		mu[i]=mu[i-1]<<1;
	for(int i=1;i<=mu[n];++i){
		rs[i]=MAX;
	}
	rs[0]=0;
}
void calc(){

	int limit=mu[n]-1,i,j,jnxt,jprv,tSum,prv,tmp;
	for(i=1;i<=limit;++i){
		tSum=0;
		for(j=0;j<n;++j)
			if((i&mu[j])!=0)
				tSum+=a[j+1];
		tmp=tSum;
		for(j=0;j<n;++j){
			tSum=tmp;
			if((i&mu[j])!=0) //
			{
				tSum-=a[j+1];
				jprv=(j+n-1)%n;
				jnxt=(j+1)%n;
				if((i&mu[jprv])!=0) tSum-=a[jprv+1];
				if((i&mu[jnxt])!=0) tSum-=a[jnxt+1];
				prv=i;
				prv &=~mu[j];
				prv &=~mu[jprv];
				prv &=~mu[jnxt];

				rs[i]=min(rs[i],rs[prv]+tSum);
				//cout<<i<<' '<<j<<' '<<prv<<' '<<tSum<<' '<<tSub<<' '<<rs[i]<<endl;
			}
		}
		//cout<<i<<' '<<rs[i]<<endl;
	}
	printf("%d\n",rs[limit]);
}
