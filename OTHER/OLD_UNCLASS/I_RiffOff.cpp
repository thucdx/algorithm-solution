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

#define NEGINF -20000000
long long maxL(long long a, long long b)
{
	if (a>b) return a;
	return b;
}
long long f[205][205];
int val[205];
int n,s,t;
void calc();
int main()
{
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	do
	{
		cin>>n;
		if(n==0) break;
		cin>>s>>t;
		FOR(i,1,n)
		{
			cin>>val[i];
		}
		calc();
		cout<<f[n][t]<<endl;
	}while(true);
}
void calc()
{
	//memset
	FOR(i,0,204)
	FOR(j,0,204)
	{
		f[i][j]=NEGINF;
	}
	//tinh toan.
	//t=1;
	FOR(i,0,s-1)
		f[i][1]=0;
	//quy hoach
	FOR(i,2,t) //max turn
	{
		long long lim=s*i-1;
		if(n<s*i-1) lim=n;
		FOR(j,i-1,lim)  //n
		{
			//f[j][i]=max(f[j][i-1])
			//nhay  s buoc
			FOR(sp,1,s)
			{
				if(sp>j) break;
				f[j][i]=maxL(f[j][i],f[j-sp][i-1]+val[j-sp+1]);
			}
		}
	}
}
