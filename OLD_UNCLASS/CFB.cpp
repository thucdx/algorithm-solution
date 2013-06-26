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

int n;
int cnt[25];
long long rs=0;
int main()
{
//    freopen("input.txt",  "rt", stdin);
//    freopen("?.OUT", "wt", stdout);
    cin>>n;
    int a;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);    
        cnt[a+10]++;
    }
    for(int i=-10;i<=-1;i++)
    {
        rs+=(long long)cnt[i+10] *(long long) cnt[10-i];
    }
    rs+=((long long)cnt[10]*((long long)cnt[10]-1))/2;
    cout<<rs;
//    getch();  
}
    
