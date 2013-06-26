#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);
#define pb  push_back
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>


//#include <conio.h>
int n, m ,r;
int carSets[1005][65][65];
int minDisByCar[1005][65][65];
int dis[65][65][1005];

void init();

int main()
{
    scanf("%d %d %d",&n,&m,&r);
    int val;
    REP(i,1,m)
    REP(a,1,n)
    REP(b,1,n)
    {
        scanf("%d",&val);
        carSets[i-1][a-1][b-1] = val;
    }

    init();

    int s,t,k;
    REP(i,1,r)
    {
        scanf("%d %d %d",&s,&t,&k);
        printf("%d\n",dis[s-1][t-1][k]);
    }

    return 0;
}

void init()
{
    //minDisByCar
    REP(car, 0, m - 1)
    {
        REP(i,0,n-1)
        REP(j,0,n-1)
            minDisByCar[car][i][j] = carSets[car][i][j];

        REP(t,0,n-1)
        REP(i,0,n-1)
        REP(j,0,n-1)
        {
            minDisByCar[car][i][j] = min (minDisByCar[car][i][t] + minDisByCar[car][t][j]
                                          , minDisByCar[car][i][j]);
        }
    }

    //DP
    memset(dis,INF, sizeof(dis));

    //k = 0;
    REP(i,0,n-1)
    REP(j,0,n-1)
    {
        int minDisIJ = INF;
        REP(car, 0, m - 1)
            minDisIJ = min(minDisIJ, minDisByCar[car][i][j]);

        dis[i][j][0] = minDisIJ;
    }

    // k by k - 1;
    REP(k, 1, 1000)
    {
        REP(i,0,n-1)
        REP(j,0,n-1)
        {
            int minDisByCarIJ = INF;
            REP(other, 0, n-1)
            {
                minDisByCarIJ = min(minDisByCarIJ, dis[i][other][0] + dis[other][j][k-1]);
            }

            dis[i][j][k] = min(dis[i][j][k-1], minDisByCarIJ);
        }
    }
}
