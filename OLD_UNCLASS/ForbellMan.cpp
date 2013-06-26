#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <stack>
#include <queue>
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
#define MAX 1000

int start, end,n;
int f[MAX][MAX];
int ford(int start, int end);
int main()
{
    freopen("Ford.IN", "rt", stdin);
    freopen("Ford.OUT", "wt", stdout);              
    scanf("%d%d%d", &n,&start, &end);
    int va,vb,d;
    while(scanf("%d%d%d",&va,&vb,&d)==3)
    {   
        f[va][vb]=d;
        f[vb][va]=d;    
    }
    ford(start,end);
    
}
int ford(int start, int end)
{

    int *trace=new int [n+1];
    int *d= new int [n+1];
    REP(i,0,n)
    {
        d[i]=INF;
        trace[i]=-1;
    }
    d[start]=0;
    //Cach 1.
    /*
    bool stop=true;
    do
    {
        stop=true;
        REP(u,1,n)
        REP(v,1,n)
        {
            if(f[u][v]!=0)
            {
                if(d[v]>d[u]+f[u][v])
                {
                    d[v]=d[u]+f[u][v];
                    trace[v]=u;
                    stop=false;    
                }
                    
            }    
        }
    }
    while(stop);
    */
    //Cach 2 . Queue Vong
    queue <int> qi;
    bool *inqueue= new bool[n+1];
    memset(inqueue, false, sizeof(inqueue));
    qi.push(start);
    d[start]=0;
    inqueue[start]=true;
    while(!qi.empty())
    {
        int u=qi.front();
        inqueue[u]=false;
        qi.pop();
        REP(i,1,n)
        {
            if(f[u][i]!=0)
            {
                if(d[i]>d[u]+f[u][i])
                {
                    d[i]=d[u]+f[u][i];
                    trace[i]=u;
                    if(!inqueue[i])
                    {
                        qi.push(i);    
                        inqueue[i]=true;
                    }
                }    
            }
        }    
    }
    cout<<"min distance from"<<start<<" to"<< end<<" is: "<<d[end]<<endl;
    //return d[end];
    stack <int> si;
    int ver=end;
    do
    {
        si.push(ver);
        ver=trace[ver]; 
    }
    while(ver!=start);
    si.push(start);
    cout<<" path:"<<endl;
    while(!si.empty())
    {
        int a=si.top();
        si.pop();    
        cout<<a<<" ";
    }
    return d[end];
        
}

