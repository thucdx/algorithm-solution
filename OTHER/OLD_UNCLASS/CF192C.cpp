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

int n;
int f['z' - 'a' + 1]['z' - 'a' + 1];

int main()
{
    cin>>n;
    memset(f,0,sizeof(f));

    ///

    string s;
    REP(i,1,n)
    {
        cin>>s;

        int len = s.length();
        int first = s[0] - 'a', last = s[len - 1] - 'a';

        REP(j,0,'z'- 'a')
        {
            if(f[j][first] > 0)
            {
                f[j][last] = max ( f[j][last], f[j][first] + len);
            }
        }

        f[first][last] = max(f[first][last], len);
    }

    int result = 0;
    REP(i,0,'z' - 'a')
    {
        result = max(result, f[i][i]);
    }

    cout<<result;
    return 0;
}
