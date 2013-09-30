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
//#include <conio.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);
#define pb  push_back
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>

int n,u,r;
vector<int> a,b,k,p;

long long s,current;

int lastChoice;

void input();
void solve();
void go(int k);

int main()
{
    //freopen("input.txt",  "rt", stdin);

    input();
    solve();
}

void input()
{
    cin>>n >>u >>r;

    a.resize(n);
    b.resize(n);
    k.resize(n);
    p.resize(n);

    int val;
    REP(i,0,n-1)
    {
        cin>>val;
        a[i] = val;
    }
    REP(i,0,n-1)
    {
        cin>>val;
        b[i] = val;
    }
    REP(i,0,n-1)
    {
        cin>>val;
        k[i] = val;
    }
    REP(i,0,n-1)
    {
        cin>>val;
        p[i] = val - 1;
    }

}

void solve()
{
    s = (long long) (-1e12);

    lastChoice = 1;
    go(1);

    cout<<s;
}

void go(int x)
{
    if( (x-1)% 2 == u%2)
    {
        long long sum = 0;
        REP(i,0,n-1)
            sum += a[i] * k[i];
        s = max(s, sum);
    }

    if( x >= u + 1)
    {
        return;
    }

    vector<int> _a(n);
    int _lastChoice = lastChoice;

    REP(i,0,n-1)
        _a[i] = a[i];
    lastChoice = 1;

    REP(i,0,n-1)
    {
        a[i] = _a[p[i]] + r;
    }

    go(x+1);

    REP(i,0,n-1)
        a[i] = _a[i];
    lastChoice = _lastChoice;

    if(lastChoice == 0)
    {
        return;
    }
    else //1
    {
        _lastChoice = lastChoice;
        REP(i,0,n-1)
            _a[i] = a[i];

        lastChoice = 0;

        REP(i,0,n-1)
        {
            a[i] = (_a[i] ^ b[i]);
        }

        go(x+1);

        lastChoice = _lastChoice;
        REP(i,0,n-1)
            a[i] = _a[i];
    }

}
