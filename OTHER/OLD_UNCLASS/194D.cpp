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

int main()
{
    freopen("input.txt",  "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int n = 10;
    int lim = 1<<n;
    long long result = 1;
    REP(i,1,lim)
    {
        result +=(long long) i*i;
    }
    cout<<result<<endl;


}
