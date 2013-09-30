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
int a[105];
int n;
bool canReach[105][105];

void init();
int main()
{
    cin>>n;
    memset(canReach, 0, sizeof(canReach));
    int val;
    REP(i,1,n)
    {
        cin >> val;
        a[i] = val;
    }

    REP(i,1,n)
    {
        cin>>val;
        canReach[i][i] = true;
        if (i - val >= 1)  canReach[i][i-val] = canReach[i-val][i] = true;
        if (i + val <= n) canReach[i][i+val] = canReach[i+val][i] = true;
    }

    init();

    REP(i,1,n)
    {
        if (!canReach[i][a[i]])
        {
            cout<<"NO";
            return 0;
        }
    }

    cout<<"YES";
    return 0;
}

void init()
{
    REP(t,1,n)
    REP(i,1,n)
    REP(j,1,n)
    {
        if (canReach[i][t] && canReach[t][j])
            canReach[i][j] = true;
    }
}
