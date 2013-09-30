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
const int maxSize = 100005;
vector<int> color[maxSize];

int main()
{
    //freopen("input.txt", "rt", stdin);

    int n,m,k;
    cin >> n >> m >> k;

    int cl;
    REP(i,1,n)
    {
        scanf("%d",&cl);
        color[cl].pb(i);
    }

    int result = 0;
    REP(i,1,m)
    {
        int head = 0, tail = 0;
        for (head = 0 , tail = 0;  tail < color[i].size(); tail ++)
        {
            while (color[i][tail] - color[i][head] - (tail - head) > k)  head ++;

            if (tail - head + 1 > result)  result = tail - head + 1;
        }
    }

    cout << result ;

}
