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
struct edge
{
    int first;
    int second;
    edge(){}

    edge(int f, int s)
    {
        first =  f;
        second = s;
    }
};
vector<edge> edgesToDel;
set<int> roots;

int father[1005];
int n;

int getRoot(int x)
{
    return x == father[x] ? x : father[x] = getRoot(father[x]);
}

void unite(int x, int y)
{
    x = getRoot(x);
    y = getRoot(y);

    father[x] = y;
}

int main()
{
    //freopen("input.txt", "rt", stdin);

    int f,s;

    scanf("%d", &n);
    REP(i,1,n)
        father[i] = i;
    REP(i,1,n-1 )
    {
        scanf("%d %d", &f, &s);

        int rf = getRoot(f);
        int rs = getRoot(s);

        if (rf == rs)
        {
            edgesToDel.pb(edge(f,s));
        }
        else unite(f,s);
    }


    int days = edgesToDel.size();

    if (days == 0)
    {
        cout << 0;
        return 0;
    }
    else
    {
        cout << days <<endl;

        REP(i,1,n)
        {
            roots.insert(getRoot(i));
        }
        vector<int> rs (roots.begin(), roots.end());

        REP(i,1,days)
        {
            cout<<edgesToDel[i - 1].first<<" "<<edgesToDel[i-1].second<<" "<<rs[i-1]<<" "<<rs[i]<<endl;
        }
    }

}
