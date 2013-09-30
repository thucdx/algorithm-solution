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
#define REP(i,a,b) for(int i = a; i <= (b); ++i)
#define DOWN(i,a,b) for(int i = a; i >= (b); --i)
#define FOR(i,a) REP(i,0,a);
#define pb  push_back
#define ins insert
#define sz(a) size(a)
#define all
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>


//#include <conio.h>

int n;
int f[100005], unit[100005];

int root(int x)
{
    return x == f[x] ? x : f[x] = root(f[x]);
}

bool isLucky(int n)
{
    while (n != 0)
    {
        int dig = n % 10;
        n /= 10;
        if (dig != 4 && dig != 7) return false;

    }
    return true;
}

void unite(int x, int y)
{
    x = root(x);
    y = root(y);

    f[x] = y;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    scanf("%d",&n);

    REP(i,1,n)
        f[i] = i;
    REP(i,0,n)
        unit[i] = 1;

    int u,v,w;
    REP(i,1,n-1)
    {
        scanf("%d %d %d", &u, &v, &w);
        if (!isLucky(w))
        {
            //cout << u <<" "<< v <<endl;
            u = root(u);
            v = root(v);
            f[v] = u;
            unit[u] += unit[v];
        }
    }

    long long result = 0;
    REP(i,1,n)
    {
        //cout<<i<<" "<<root(i)<<" "<<unit[i]<<endl;
        int rx = root(i);
        long long val = n - unit[rx];
        result += val * (val - 1);
    }

    cout << result;
}
