#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
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
int n,m,d[1605][1605],c,a,s,f;
inline int node(int ver, int flightAgency)
{
    return ver*16+flightAgency-1;    
}

int main()
{
    freopen("AIRLINE.IN", "rt", stdin);
    freopen("AIRLINE.OUT", "wt", stdout);              
    cin>>n>>m>>c>>a>>s>>f;
    string s;
    REP(i,1,m)
    {
        getline(cin,s);
        cout<<s<<endl;
    }
}

