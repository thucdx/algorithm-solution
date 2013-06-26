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
#define maxSize  1000 //for this problem only.

struct edge
{
    int ver1,ver2;
    int len;

    edge()
    {
    }

    edge(int v1, int v2, int l)
    {
        ver1 = v1;
        ver2 = v2;
        len = l;
    }

    bool operator<(const edge& other) const
    {
        return len < other.len;
    }
};

vector<edge> edges;

int father [ maxSize + 5];
int n, m;

int getRoot(int ver)
{
    while (ver != father[ver])
    {
        father[ver] = getRoot(father[ver]);
        ver = father[ver];
    }
    return ver;
}

void Union(int x, int y)
{
    x = getRoot(x);
    y = getRoot(y);

    father[x] = y;
}
vector<edge>::iterator it;

int main()
{
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    cin>> n >> m;

    int v1,v2,l;
    REP(i,1,m)
    {
        cin >> v1 >> v2 >> l;

        edge e(v1,v2,l);
        edges.push_back(e);
    }

    sort(edges.begin(), edges.end());
    vector<edge> spanningTree;

    int count = 0;

    REP(i,1,n)
        father[i] = i;

    REP(i,0,m - 1)
    {
        edge e = edges[i];
        int v1,v2;
        v1 = e.ver1, v2 = e.ver2;
        if(getRoot(v1) != getRoot(v2))
        {
            count ++;
            spanningTree.pb(e);
            Union(v1,v2);
            if(count == n-1) break;
        }
    }

    for (it = spanningTree.begin() ; it != spanningTree.end(); it++)
    {
        cout <<it->ver1<<" "<<it->ver2<<" "<<it->len<<endl;
    }
}
