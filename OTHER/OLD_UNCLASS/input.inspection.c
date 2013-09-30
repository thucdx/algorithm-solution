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

void input(VI &a, int size);
int main()
{
    freopen("input.txt",  "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    VI a;
    int n = 3;
    input(a,n);
    REP(i,0,n-1)
        cout<<a[i]<<" ";
    cout<<endl;
}

void input(VI &a, int size)
{
    a.resize(size);
    int val;
    REP(i,0,size-1)
    {
        cin>>val;
        a[i] = val;
    }
}
