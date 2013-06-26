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

VI a;
int n;
int main()
{
    cin >> n;
    int val;
    REP(i,1,n)
    {
        scanf("%d",&val);
        a.pb(val);
    }

    int pos = 0;
    REP(i,0,n-1)
    {
        scanf("%d",&val);
        if(val == a[pos])  ++pos;
    }

    cout << n- pos;
}
