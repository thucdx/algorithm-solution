#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
//#include <conio.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);
#define pb  push_back
#define INF 1000000000
#define VI vector<int>
#define VII vector<VI>
//ham
template <class T>  //so ko am
T gcd(T a, T b){if(b==0) return abs(a); else return gcd(b,a%b);}
template <class T>  
T lcm(T a, T b){ return a/gcd(a,b) *b;}
#define MAX 100000

double EPS=1e-9;
bool visited[MAX+5];
VI adj[MAX+5];
int n;
int ver,maxDis,curDis;
void dfs(int a);
int main()
{
    //freopen("PT07Z.IN", "rt", stdin);
    //freopen("PT07Z.OUT", "wt", stdout);
    scanf("%d",&n);
    int a,b;
    REP(i,1,n-1)
    {
        scanf("%d%d",&a,&b);
        adj[a].pb(b);
        adj[b].pb(a);   
    }
    //Chon tu dinh 1.
    //Step 1. Tinh dinh xa dinh 1 nhat. goi dinh do la k.
    memset(visited, false, sizeof(visited));
    curDis=0;
    visited[1]=true;
    dfs(1);
    memset(visited, false, sizeof(visited));
    curDis=0;
    maxDis=0;
    visited[ver]=true;
    //cout<<endl<<" ______"<<endl;
    dfs(ver);
    cout<<maxDis;
}
void dfs(int a)
{   
    //cout<<a<<endl;
    if(curDis>maxDis)
    {
        maxDis=curDis;
        ver=a;    
    }
    REP(i,0,adj[a].size()-1)
    {
        int v=adj[a][i];
        if(visited[v]==false) //chua visit
        {
            visited[v]=true;
            curDis++;
            dfs(v);
            curDis--;
        }    
    }
}

