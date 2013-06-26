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

LL f[100005];
int n;
int a[100005];

int cmp(const void * a, const void *b)
{
	int *ia= (int *) a;
	int  *ib=(int *)b;
	return(*ia -*ib);
}

void input();
void exe();
int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	input();
	exe();
}
void input()
{
	int _t;
	cin >>n;
	scanf("%d",&_t);
	f[0]=_t;
	FOR(i,1,n-1)
	{
		scanf("%d",&_t);
		f[i]=f[i-1]+_t;
	}
}
void exe()
{
	if(f[n-1]<=0 ) {
		cout<<"-1";
		return ;
	}
	qsort(f,n-1,sizeof(f[0]),cmp);

	a[0]=f[0];
	FOR(i,1,n-1)
	{
		a[i]=f[i]-f[i-1];
		if(a[i]<=0 ) {
			cout<<"-1";
			return;
		}
	}
	cout<<a[0];
	FOR(i,1,n-1)
	{
		cout<<' '<<a[i];
	}
}
