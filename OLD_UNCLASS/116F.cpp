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
#define MAX 100000
int n;
struct Point{
    int x,y;        
};

int a[MAX+5], b[MAX+5],f[MAX+5];
int main()
{
    //freopen("input.txt",  "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int n;
    cin>>n;
    REP(i,0,n-1)
    {
        scanf("%d",&a[i]);
    }
    REP(i,0,n-1)
    {
        scanf("%d",&b[i]);
    }
    REP(i,0,n-1)
    {
        f[a[i]-1]=b[i];
    }
    
    REP(i,0,n-1)
        printf("%d ",f[i]);

}
    
