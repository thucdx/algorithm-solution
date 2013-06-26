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
#define EPS 0.000001
bool compareDB(double a, double b){
    return (fabs(a-b)<EPS);
}

int main()
{
    freopen("input.txt",  "rt", stdin);
    freopen("output.txt", "wt", stdout);
    double a=5, b=0.1;
    while(!compareDB(a,b))
    {   cout<<b<<endl;
         b+=0.1;
    }
}
    
