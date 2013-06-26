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

int a[100005][5];
long long f[100005][5];
int n;
void solve();
int main()
{
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
    
    int val;
    int test = 0;
    do
    {
        scanf("%d", &n);
        if ( n == 0 ) break;
        int x, y,z;
        REP(i,1,n)
        {
            scanf("%d%d%d",&x,&y,&z);    
            a[i-1][0] = x;
            a[i-1][1] = y;
            a[i-1][2] = z;
        }    
        
        test ++;
        cout <<test<<". ";
        
        solve();
    }
    while( true);
}

void solve()
{
    memset(f,0,sizeof(f));

    //i = 0;
    f[0][0] = INF;
    f[0][1]= a[0][1];
    f[0][2]= f[0][1] + a[0][2];
    
    REP(i,1,n-1)
    {
        f[i][0]= INF;
        f[i][0] = min(f[i-1][0], f[i-1][1]) + a[i][0];
        
        f[i][1] = INF;
        f[i][1] = min(f[i-1][0], f[i-1][1]);
        f[i][1] = min(f[i][1], f[i-1][2]);
        f[i][1] = min (f[i][0], f[i][1]) ;
        f[i][1] += a[i][1];
        
        f[i][2] = INF;
        f[i][2] = min(f[i-1][1], f[i-1][2]);
        f[i][2] = min(f[i][1], f[i][2]);
        f[i][2] += a[i][2];                 
    }
    
    cout << f [n-1][1]<<endl;    
}
