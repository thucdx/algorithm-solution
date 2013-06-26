#include <bitset>
#include <algorithm>
#include <functional>
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


int k,l,m;
bool f[1000005];
void init();
int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	cin>>k>>l>>m;
	int n;
	init();
	FOR(i,1,m)
	{
		cin>>n;
		if(f[n]) cout<<'A';
		else cout<<'B';
	}
}
void init()
{
	f[1]=true;
	//neu n-1,n-k,n-l co 1 vi tri false thi f[n] la vi tri thang
	int a,b,c;
	FOR(n,2,1000004)
	{
		a=n-1;
		b=n-k;
		c=n-l;
		if(a==0 || !f[a]) {f[n]=true; continue;}
		if (b>=0)
		{
			if(b==0 || !f[b]) {f[n]=true; continue;}
		}
		if(c>=0)
		{
			if(c==0 || !f[c]) {f[n]=true; continue;}
		}
	}
}
