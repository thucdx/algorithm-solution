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
#define ms(arr,val) memset(arr, val, sizeof(arr))

#define INF 1000000000
#define PI 3.14159

#define VI vector<int>
#define VVI vector<VI>

bool f[1005][1005];
int n;

bool isInRec(int x, int y)
{
    return (1 <= x && x <= n && 1 <= y && y <= n);    
}

bool isLeftTop(int x, int y)
{
    if (x >= 1 && y >= 1 && x <= n && y <= n)
    {
        REP(i,x,x+2)
        REP(j,y,y+2)
        {
            if ( !isInRec(i,j) || !f[i][j] )
                return false;
        }         
        
        return true;
    }   
    return false;
}

bool isExist(int x, int y)
{
    REP(i,x,x + 5)
    REP(j,y,y + 5 )
        if(isLeftTop(i,j))
            return true;
    return false;
}


int main()
{
    //freopen("B.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    int m;
    cin >> m;
    memset(f,false,sizeof(f));
    int x, y;
    REP(i,1,m)
    {
        cin >> x >> y;
        f[x][y] = true;
        if(isExist(x-2,y-2))
        {
            cout << i;
            return 0;
        }            
    }
    cout << -1;
}
