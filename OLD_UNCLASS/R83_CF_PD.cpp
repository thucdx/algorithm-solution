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

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
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

int s[1005];
int n,m,h;
int main()
{
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	scanf("%d%d%d",&n,&m,&h);
	int sum=0;
	for(int i=1;i<=m;i++)
	{
        scanf("%d",&s[i]);
        sum+=s[i];
    }
    if(sum<n) {cout<<"-1"; return 0;}
    if(sum-s[h]<n-1) { cout<<"1.0";return 0;}
    
    double a=sum-n-s[h]+1,b=sum-s[h];
    double rs=1.0;
    for(int i=1;i<s[h];i++)   
           rs=rs*((a+i)/(b+i)); 
    printf("%.9f",1-rs);
}
