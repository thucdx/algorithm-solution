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

bool adj[3005][3005];
int deg[3005];
bool inRing[3005];
bool cont=true;
bool tmp[3005][3005];
    int tDeg[3005];
int dis[3005];
int n;
void findRing();
int minDis(int i);
bool visit[3005];
int main()
{
    //freopen("input.txt",  "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    cin>>n;
    memset(adj,false,sizeof(adj));
    memset(deg,0,sizeof(deg));
    memset(inRing, false, sizeof(inRing));
    int a,b;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        adj[a][b]=true;
        adj[b][a]=true;
        deg[a]++;
        deg[b]++;    
    }
    findRing();
    REP(i,1,n)
    {
        if(inRing[i]) dis[i]=0; 
        else dis[i]=INF;   
    }
    //cout<<"Ket qua:"<<endl;
    REP(i,1,n)
    {
        if(dis[i]==INF) dis[i]=minDis(i);
        cout<<dis[i]<<" ";
    }
    
}
int minDis(int i)
{
    if(dis[i]!=INF) return dis[i];
    for(int j=1;j<=n;j++)
    {
        if(adj[i][j])
        {
            adj[i][j]=false;
            adj[j][i]=false;
            dis[i]=min(dis[i],1+minDis(j));   
            adj[i][j]=true;
            adj[j][i]=true;
        }    
    }
    return dis[i];
}
void findRing()
{

    REP(i,1,n)
    {
        REP(j,1,n) 
        {
                tmp[i][j]=adj[i][j];
        }
    }
    REP(i,1,n) tDeg[i]=deg[i];
    while(cont)
    {
        cont=false;
        for(int i=1;i<=n;i++)
        {
            if(tDeg[i]==1)
            {
                cont=true;
                tDeg[i]=0;
                REP(j,1,n)
                {
                    if(tmp[i][j]==true)
                    {
                        tDeg[j]--;    
                        break;
                    }    
                }    
            }    
        }
        if(!cont) break;    
    }
    REP(i,1,n)
    {
        if(tDeg[i]==2)
        {
            inRing[i]=true;
          //  cout<< i<<" ";
        }    
        else inRing[i]=false;
    }
        
}
