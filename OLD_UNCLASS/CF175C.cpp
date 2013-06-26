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
#define ins insert
#define all(x) x.begin(), x.end()
#define sz(x) size(x)

#define INF 1000000000
#define PI 3.14159

#define VI vector<int>
#define VVI vector<VI>

//#include <conio.h>
struct figure
{
    int k,c;
    figure(){}
    figure(int _k, int _c)
    {
        k = _k;
        c = _c;
    }
    bool operator<(const figure& other) const
    {
        return c < other.c;
    }
};

int n;
vector<figure> figures;
vector<long long> p;

int main()
{
    int k, c;
    int t;
    long long val;
    long long maxCost = 0;
    long long totalFig = 0;

    cin >> n;
    REP(i, 1, n)
    {
        cin >> k >> c;
        figures.pb(figure(k,c));
    }

    sort(all(figures));

    cin >> t;
    REP(i, 1, t)
    {
        cin >> val;
        p.pb(val);
    }

    int curFig = 0;
    int i;

    for (i = 0 ; i < t;)
    {
        if (curFig >= n)     break;

        long long tmp = totalFig + figures[curFig].k;

        if (tmp > p[i])
        {
            long long add = p[i] - totalFig;
            maxCost += add * figures[curFig].c * (i + 1);
            figures[curFig].k -= add;
            totalFig = p[i];
            i++;
        }
        else //tmp  <= p[i];
        {
            totalFig = tmp;
            maxCost += (long long )figures[curFig].k * figures[curFig].c * (i+1);
            figures[curFig].k = 0;
            curFig ++;

            if (tmp == p[i])
                i++;
        }
    }

    if (i == t)
    {
        REP(j,curFig,n-1)
        {
            maxCost += (long long)figures[j].k * figures[j].c * (t + 1);
        }
    }

    cout << maxCost;
}
