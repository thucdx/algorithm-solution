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
#define all(x) begin(x), end(x)
#define sz(x) size(x)
#define INF 1000000000
#define PI 3.14159

#define VI vector<int>
#define VVI vector<VI>


//#include <conio.h>
int n;
const int RLIM = 5050;
const int LIM = 10000005;
const int MAXN = 1000005;

int id[LIM];
int father[MAXN];

int getRoot(int x)
{
    return x == father[x] ? x : father[x] = getRoot(father[x]);
}

bool unite(int x, int y)
{
    x = getRoot(x);
    y = getRoot(y);

    if (x == y)
        return false;
    else
    {
        father[x] = y;
        return true;
    }
}

inline bool couple(int a, int b)
{
    return id[a] != 0  && id[b] != 0 && unite(id[a],id[b]);
}

inline bool inRange(int x);
inline int gcd(int a, int b);

int main()
{
    //freopen("input.txt", "rt", stdin);

    cin >> n;
    memset(id, 0, sizeof(id));

    int val;
    REP(i,1,n)
    {
        scanf("%d",&val);
        id[val] = i;
        father[i]  = i;
    }

    int result = n;

    REP(r,1,RLIM)
    {
        for(int s = r % 2 + 1; s < r; s += 2)
        {
            //if (r * r + s * s > LIM) break;

            if (gcd(r,s) == 1)
            {
                int x = r * r + s * s;
                int y = r * r - s * s;
                int z = 2 * r * s;

                if (inRange(x)  && inRange(y))
                    result -= couple(x,y);

                if (inRange(y)  && inRange(z))
                    result -= couple(y,z);

                if (inRange(x)  && inRange(z))
                    result -= couple(x,z);
            }
        }
    }

    cout <<result;
}
bool inRange(int x)
{
    return 0 < x && x < LIM;
}
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a%b);
}
