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

int gcd(int a, int b)
{
    if (a <0) a = -a;
    if (b < 0) b = -b;
    
    if (b == 0) return a;
    return gcd(b, a%b);    
}

int main()
{
    int n, m;
    int a0, b0;
    int val;
    
    cin >> n >> m;
    cin >> a0;
    REP(i,1,n) cin >> val;
    cin >> b0;
    REP(i,1,n) cin >> val;
    
    if (n == m)
    {
        int uoc = gcd(a0,b0);
        int tu = a0/uoc;
        int mau = b0/uoc;
        
        if(mau <0) mau *=-1, tu *=-1;        
        cout <<tu <<"/"<<mau<<endl;
    }
    else if (n < m)
    {
        cout <<"0/1"<<endl;    
    }
    else //n >m
    {
        if( a0 * b0 >0)
        {
            cout << "Infinity";
                
        }    
        else cout << "-Infinity";
    }
    
}
