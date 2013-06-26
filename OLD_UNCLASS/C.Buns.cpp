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

int  f[1005][15];
int n,m,cf,df;
int a[15],b[15],c[15],d[15];
int main()
{
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	scanf("%d%d%d%d", &n,&m,&cf,&df);
    FOR(i,0,m-1){
    	scanf("%d%d%d%d", &a[i],&b[i],&c[i],&d[i]);
    	//cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<" "<<d[i]<<endl;
    }
    FOR(i,0,n) //tinh f[i][0];
    {
            f[i][0]=(i/cf) * df;
            //cout<<i<<" "<<0<<" "<<f[i][0]<<endl;
    }
    
    FOR(i,1,m)
    FOR(j,1,n)
    {
        int rs=f[j][i-1]; //khong chon thu i;
        int lim=a[i-1]/b[i-1];
        int minus;
        FOR(t,1,lim)
        {
            minus=t*c[i-1]; 
            if(minus>j) break;
            rs=max(rs,t*d[i-1]+f[j-minus][i-1]);  
        }
        f[j][i]=rs;
        //cout<<j<<" "<<i<<" "<<f[j][i]<<endl;
    }
    cout<<f[n][m];
}
