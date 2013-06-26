#include <iostream>
#include <stdio.h>
using namespace std;

long long h[1005];
long long v[1005];
void input();
void calc();
int n,i;
int a[1005],b[1005];
inline long long maxL(long long a, long long b);
long long dis(long long a, long long b);
int main() {
	input();
	calc();
}
void input(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d",&a[i],&b[i]);
	}
}
long long maxL(long long a, long long b)
{
	if(a>b) return a;
	return b;
}
long long dis(long long a, long long b){
	long long rs=a-b;
	if (rs<0) rs=-rs;
	return rs;
}
void calc()
{
//h[i] la max neu a[i] la canh nam ngang -
//v[i] la max neu a[i] nam doc |
	h[1]=a[1];
	v[1]=b[1];
	for(i=2;i<=n;++i){
		h[i]=maxL(h[i-1]+a[i]+dis(b[i],b[i-1]),v[i-1]+a[i]+dis(b[i],a[i-1]));
		v[i]=maxL(v[i-1]+b[i]+dis(a[i],a[i-1]),h[i-1]+b[i]+dis(a[i],b[i-1]));
	}
	cout<<maxL(h[n],v[n])<<endl;
}

