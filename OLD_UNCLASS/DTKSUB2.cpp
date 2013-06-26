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
string s;
int n, k;

bool check(int length);
map <string, int> cnt;

int main()
{
    freopen("DTKSUB.IN", "rt", stdin);
    cin >> n >> k;
    cin >> s;

    int low = 1, hi = n;
    while (low < hi - 1)
    {
        int mid = (low + hi) / 2;

        bool isOK = check(mid);
        if (isOK)
        {
            low = mid;
        }
        else hi = isOK;
    }

    if (check(hi)) cout << hi;
    else if (check(low)) cout << low;
    else cout << -1;

}

bool check(int length)
{
    cnt.clear();
    int maxRep = -1;

    REP(i,0,n-1-length)
    {

    }
}
