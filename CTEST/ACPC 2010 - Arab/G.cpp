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

typedef long long ll;

#define VI vector<int>
#define VVI vector<VI>

inline ll knightDist(ll x1, ll y1, ll x2, ll y2)
{
    ll dx = abs(x1-x2), dy = abs(y1 - y2);
    if(dx + dy == 1)
        return 3;
    if (dx == 2 && dy == 2)
        return 4;
    
    ll ret = max((ll)(dx+1)/2, (ll)(dy+1)/2);
    ret = max(ret, (ll)(dx + dy + 2 )/ 3);    
    ret += (ret % 2 != (ll)(dx + dy) %2 );
    
    return ret; 
}

int n;
ll knight[20][5], target[20][5];
ll dis[20][20];
ll f[(1<<16)];

int main()
{
    freopen("G.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    
    int test = 0;
    int x,y;
    
    do
    {
        cin >> n;
        if (n==0) break;
        test++;
        cout<<test<<". ";
        REP(i,1,n)
        {
            cin >> x >> y;
            knight[i-1][0] = x;
            knight[i-1][1] = y;        
        }        
        
        REP(i,1,n)
        {
            cin >> x >> y;
                        
            target[i-1][0] = x;
            target[i-1][1] = y;        
        }

        REP(i,0,n-1)
        REP(j,0,n-1)
        {
            dis[i][j] = knightDist(knight[i][0], knight[i][1], target[j][0], target[j][1]);
        }
        REP(i,1,((1<<n)-1))
            f[i] = (ll)1e18;
                
        REP(i,1,((1<<n) - 1))
        {            
            int count = 0;
            REP(j,0,n)
            {
                if (i>>j & 1 != 0)
                    ++count;                     
            }            
            
            REP(j,0,n)
            {
                if (i>>j & 1 != 0)
                {
                    f[i] = min(f[i], dis[count-1][j] + f[i ^ (1 <<j)]);    
                }    
            }
        }
        
        cout << f[(1<<n)-1]<<endl;
    }
    while(true);
}
