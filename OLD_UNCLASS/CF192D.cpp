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
#define mp make_pair
#define is insert
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>

int n, k;
long long money;
vector< pair <int, int> > sp;

vector< pair<int, int> >::iterator it;
int main()
{
    //freopen("input.txt", "rt", stdin);
    cin>> n>> k;
    cin>> money;

    int cost;
    REP(i,1,n)
    {
        scanf("%d", &cost);
        if (i != n)
            sp.pb(mp(cost, i - 1));
    }

    sort(sp.begin(), sp.end());

    long long total = 0;
    REP(i, n - 2 - k + 1 , n - 2)
    {
        total += sp[i].first;
    }

    money -= total;
    int result = n;

    if (money < 0) //lack of mn
    {
        int minCost;
        if (k != 1)
            minCost = money  + sp[n-2-k+1].first;
        else minCost = money + total;

        REP(i,0,n-2)
        {
            if (sp[i].first > minCost && sp[i].second + 1 < result)
            {
                result = sp[i].second + 1;
            }
        }
    }

    cout<<result;
}
