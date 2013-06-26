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
#define is insert
#define er erase
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>

int n,m;
int h[705][705];
bool isPeak[705][705];
bool visited[705][705];
int dx[]={1,-1,1,-1,1,-1,0,0};
int dy[]={1,-1,-1,1,0,0, 1,-1};
bool isOk(int i, int j)
{
    return ( i>=1 && i<=n  && j>=1  && j<=m);    
}
void check(int i, int j);
bool peak(int i, int j);
int nPeak=0;
int main()
{
    //freopen("NKGUARD.IN", "rt", stdin);
    //freopen("NKGUARD.OUT", "wt", stdout);              
    scanf("%d%d",&n,&m);
    REP(i,1,n)
    {
        REP(j,1,m)
        {
            scanf("%d",&h[i][j]);
            //cout<<h[i][j]<<" ";
        }
       // cout<<endl;
    }   
    memset(isPeak, true, sizeof(isPeak));
    memset(visited, false, sizeof(visited));
    REP(i,1,n)
    REP(j,1,m)
    {
        REP(t,0,7)
        {
            int nx=i+dx[t];
            int ny=j+dy[t];
            if(isOk(nx,ny) && h[nx][ny]> h[i][j])
                isPeak[i][j]=false;    
        }
    }
    REP(i,1,n)
    {
        REP(j,1,m)
        {
            if(!visited[i][j])
            {
                nPeak+=peak(i,j);    
            }   
        }
    }
    cout<<nPeak;
    
}
bool peak(int i, int j)
{
    if(!isPeak[i][j]) return false;
    if(visited[i][j]) return true; // isPeak=true, visited=true => 1.
    visited[i][j]=true;
    bool result=true;
    REP(t,0,7)
    {
        int nx=i+dx[t];
        int ny=j+dy[t];
        if(isOk(nx,ny) && h[nx][ny]==h[i][j])
        {
            result&=peak(nx,ny);    
        }
    }
    return result;   
}
