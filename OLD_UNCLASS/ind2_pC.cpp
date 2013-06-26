#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

#include <cstring>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, n) for (int i = 0; i < n; i++)
#define FIT(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int) (c).size()
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define SET(a, x) memset(a, x, sizeof(a));

typedef long long LL;
typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<pair<int, int> > VII;

long long f[10000];
long long g[10000];
long long t[10000];
int nMax=-1;
void init();
int main()
{
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	init();
	int nTest,a;
	cin >>nTest;
	FOR(i,1,nTest)
	{
		cin>>a;
		cout<<i<<' '<<f[a]<<endl;
	}
}
void init()
{
	f[2]=5;
	f[1]=1;
	g[2]=2;
	t[1]=1;
	t[2]=1;
	int lim=1000;
	FOR(i,3,lim)
	{
		g[i]=g[i-1]+f[i-1];
		t[i]=f[i-1]+t[i-2];
		f[i]=g[i]+g[i-1]+f[i-2]+t[i-1];
		f[i]=t[i]+t[i-2]+f[i-2]+g[i-1];
	}
	///cout<<"MAX: "<<f[lim]<<endl;
}
