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
//#include <conio.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);
#define pb  push_back
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>

vector<int> h;
vector<int> f;
int n;

int main()
{
    freopen("input.txt",  "rt", stdin);

    cin>>n;

    int hei;
    REP(i,1,n)
    {
        scanf("%d",&hei);
        h.push_back(hei);
    }

    f.resize(n);

    f[0] = h[0];
    f[1] = min(h[0], h[1]);

    REP(i,2,n-1)
    {
        f[i] = max( min(h[i], f[i-1]), min(h[i], f[i-2]));
    }

    cout<<f[n-1];
}

