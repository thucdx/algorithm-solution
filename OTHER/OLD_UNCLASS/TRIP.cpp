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

#define INF 10000000
typedef long long LL;
typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<pair<int, int> > VII;

int c[20][20];
int f[20][65536];
int n;
void optimize();
int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	cin>>n;
	FOR(i,0,n-1)
    FOR(j,0,n-1)
    {
     cin>>c[i][j];                 
    }
    optimize();
}
void optimize()
{
     f[0][0]=0;
     int lim=(1<<n)-1;
     FOR(i,0,n-1)
     FOR(j,0,lim)
                 f[i][j]=INF;
                 
     FOR(i,0,n-1)
          f[i][1<<i]=0;
          
     FOR(i,1,lim)
     {
      FOR(j,0,n-1)
      {
       if((i& (1<<j))!=0)
       { 
              int tmp=i & (~(1<<j)); //xoa di thanh pho i.
              if( f[tmp]==0) continue;
              FOR(t,0,n-1)
              {
               if((tmp &(1<<t))!=0)
               {
                f[j][i]=min(f[j][i],f[t][tmp]+c[t][j]);        
               }
              }                 
       }            
      }            
     }
     //tim
     int minCost=INF;
     FOR(i,0,n-1)
     if (f[i][lim] <minCost)    minCost=f[i][lim];
     cout<<minCost<<endl;
}
