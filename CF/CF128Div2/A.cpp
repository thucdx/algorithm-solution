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

int main()
{
    //freopen("A.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    int x, t,a,b,da,db;
    cin >> x >> t >> a >> b >> da >> db;
    
    if (x == 0)
    {
        cout <<"YES";
        return 0;    
    }
    REP(i,0,t-1)
    {
        if ( a - da * i == x)
        {
            cout <<"YES";
            return 0;    
        }    
    }
    REP(i,0,t-1)
    {
        if ( b - db * i == x)
        {
            cout <<"YES";
            return 0;    
        }    
    }
    
    REP(i,0,t-1)
    REP(j,0,t-1)
    {
        if(a + b - da * i - db * j == x) 
        {
            cout <<"YES";
            return 0;
        }
    }
    
    cout << "NO";
}
