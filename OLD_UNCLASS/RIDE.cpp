/*
ID: thucdx01
PROG: ride
LANG: C++
*/
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

string a,b;
int main()
{
    freopen("ride.in",  "rt", stdin);
    freopen("ride.out", "wt", stdout);
    cin>>a>>b;
    int ma=1,mb=1;
    REP(i,0,a.length()-1)
    {
        ma=(ma*(a[i]-'A'+1))%47;
    }
    REP(i,0,b.length()-1)
    {
        mb=(mb*(b[i]-'A'+1))%47;
    }
    if(ma==mb)
    {
        cout<<"GO"<<endl;    
    }
    else cout<<"STAY"<<endl;
    
    
}
    
