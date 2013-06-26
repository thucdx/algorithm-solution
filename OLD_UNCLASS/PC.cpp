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
long long rs[2005][15];
int m,n;
void calc();
int main() {
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	int nTest;
	cin>>nTest;
	forx(i,nTest){
		cout<<"Data set "<<i<<": ";
		cin>>n>>m;
		cout<<n<<' '<<m<<' ';
		calc();
		cout<<rs[m][n]<<endl;
	}
}
void calc()
{
	int i,j;
	for(i=0;i<=2004;i++)
		for(j=0;j<=14;j++)
			rs[i][j]=0;
	for(i=0;i<=m;i++)
		rs[i][1]=i;
	for(j=2;j<=n;j++)
	{
		int start=1<<(j-1);//start= 2^(j-1) nhung toc do nhanh hon.
		rs[start][j]=1;
		for(i=start+1;i<=m;i++)
		{
				rs[i][j]=rs[i-1][j];
				rs[i][j]+=rs[i/2][j-1];
		}
	}
}
