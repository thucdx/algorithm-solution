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

bool f[10000005];
long long rs[500005];
void init();
int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	cout<<f[0];
	init();
	int k;
	do
	{
		cin>>k;
		if(k==-1) break;
		cout<<rs[k]<<endl;
	}
	while(true);
}
void init()
{
	memset(f,0,10000000);
	rs[0]=0;
	f[0]=true;
	long long temp;
	FOR(i,1,500000)
	{
		temp=rs[i-1]-i;
		if(temp >0 && !f[temp])
		{
			rs[i]=temp;
		}
		else rs[i]=rs[i-1]+i;
		f[rs[i]]=true;
	}
}
