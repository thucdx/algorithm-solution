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
#include <conio.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);
#define pb  push_back
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>
long long f[50005];
void init();
int k,n;
int main()
{
    freopen("D.IN",  "rt", stdin);
    cin>>k>>n;
    init();
//    freopen("D.OUT", "wt", stdout);
    getch();    
}
void init()
{
    f[1]=1;
    f[2]=1;
    REP(i,3,n)
    {
        f[i]=f[i-1]+f[i-2];    
    } 
    cout<<f[n]<<endl;
}

    
