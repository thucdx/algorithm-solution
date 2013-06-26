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

int f[1005][1005];
int a[1005];
int b[1005];
int m,n;
int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	scanf("%d%d",&m,&n);
	FOR(i,0,m-1)
	{
	           scanf("%d",&a[i]);
	           // cout<<a[i]<<" " ;
    }
            // cout<<endl;
             
	FOR(i,0,n-1)
	{
	           scanf("%d",&b[i]);
	           // cout<<b[i]<<" ";
             }
            // cout<<endl;

    f[0][0]=((a[0]==b[0])? 1:0);
    FOR(i,0,m-1)
    {   
        if(i>=1) f[i][0]=f[i-1][0];
        if(a[i]==b[0]) f[i][0]=1;
              
        FOR(j,1,n-1)
        {
            f[i][j]=f[i][j-1]; 
            if(a[i]==b[j]) 
            {            
                           int a;
                           if(i>=2 && j>=2) a=f[i-2][j-2]+1;
                           else a=1;
                           f[i][j]=max(f[i][j],a);
            }
            if(i>=1)
                    f[i][j]=max(f[i][j],f[i-1][j]);          
        }
    }
    cout<<f[m-1][n-1];
}
