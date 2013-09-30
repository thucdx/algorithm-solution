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
#include <queue>
#include <stack>
//#include <conio.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);
#define pb  push_back
#define INF 100000000
#define VI vector<int>
#define VVI vector<VI>

int d[505][505],fi[505],p,f,c;
vector<int> adj[505];
bool inqueue[505];
 int ford[505];
int minDis=INF,pos;

int main()
{
//    freopen("BestSpot.IN", "rt", stdin);
//    freopen("BestSpot.OUT", "wt", stdout);              
    scanf("%d%d%d",&p,&f,&c);
    REP(i,1,f)
    {
        scanf("%d",&fi[i]);   
    }
    int a,b,dis;
    REP(i,1,c)
    {
        scanf("%d%d%d",&a,&b,&dis);
        d[b][a]=dis;
        d[a][b]=dis;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ///cout<<a<<" "<<b<<" "<<d[a][b]<<" "<<d[b][a]<<endl;
    }
    REP(i,1,p)
    {     
        REP(t,1,p)
            ford[t]=INF;
        memset(inqueue,false, sizeof(inqueue));
        queue<int> qi;
        qi.push(i);
        ford[i]=0;
        inqueue[i]=true;

        while(!qi.empty())
        {
            int u=qi.front();    
            qi.pop();
            inqueue[u]=false;
            int sizeV=adj[u].size()-1;
            REP(t,0,sizeV)
            {
                    int j=adj[u][t];
                    if(ford[j]>ford[u]+d[u][j])
                    {
                        ford[j]=ford[u]+d[u][j];
                        if(!inqueue[j])
                        {
                            qi.push(j);
                            inqueue[j]=true;
                        }
                            
                    }   
            }
        }
        int sumDis=0;
        REP(t,1,f)
            sumDis+=ford[fi[t]];
        if(sumDis<minDis)
        {
            minDis=sumDis;
            pos=i;    
        }
    }
    cout<<pos;
    
}

