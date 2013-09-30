#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <ctime>
#include <list>
#include <vector>
using namespace std;

#define forn(i,n) for(long long i=0;i<n;++i)
#define forx(i,n) for(long long i=1;i<=n;++i)
#define forab(i,a,b) for (long long i=a;i<=b;++i)
template <class T> //t:int, long
T gcd(T a, T b){
	if(a<0) a=-a;
	if(b<0) b=-b;
	T c;
	while(b!=0){
		c=b;
		b=a%b;
		a=c;
	}
	return a;
}
long long m,n;
void calc();
void calc(long long  a,long long b);
int main() {
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	do
	{
		cin>>m>>n;
		if(m==0 && n==0)
			break;
		calc();
	}
	while(true);
}
void calc()
{
	calc(m,n);
}
void calc(long long m,long long n){
	if(m==1)
	{
		cout<<n<<endl; return;
	}
	long long frac;
	frac=(n/m)+1;
	//tim kiem
	while((n*frac)/(gcd(frac*m-n,n*frac))>=1000000)
	{
		frac++;
	}
	long long g=gcd(frac*m-n,n*frac);
	cout<<frac<<' ';
	m=(frac*m-n)/g;
	n=n*frac/g;
	calc(m,n);
}
