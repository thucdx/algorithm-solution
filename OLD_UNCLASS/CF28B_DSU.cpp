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
int n;
int p[105], a[105];
int findRoot(int x)
{
    while (x != p[x])
    {
        p[x] = findRoot(p[x]);
        x = p[x];
    }
    return x;
}

void unite(int x, int y)
{
    x = findRoot(x);
    y = findRoot(y);

    p[x] = y;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    scanf("%d",&n);

    REP(i,1,n)
    {
        scanf("%d", &a[i]);
        p[i] = i;
    }

    int val;
    REP(i,1,n)
    {
        scanf("%d",&val);

        if (i - val >= 1) unite(i, i - val);
        if (i + val <= n) unite(i, i + val);
    }


    bool isOk = true;
    REP(i,1,n)
    {
        if (findRoot(a[i]) != findRoot(i))
        {
            isOk = false;
            break;
        }
    }

    puts( isOk ? "YES": "NO");
    return 0;
}
