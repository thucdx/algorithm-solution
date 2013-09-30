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
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>
#define MAX 10000

//ham
template <class T>  //so ko am
T gcd(T a, T b){if(b==0) return abs(a); else return gcd(b,a%b);}
template <class T>  
T lcm(T a, T b){ return a/gcd(a,b) *b;}
double EPS=1e-9;

VVI adj;
int f[MAX+5][4], parent[MAX+5],a,b,n,v[MAX+5];
bool visited[MAX+5];
void dfs(int a);
void create(int a, int val);
int main()
{
    //freopen("CTREE.IN", "rt", stdin);
    //freopen("CTREE.OUT", "wt", stdout);
    scanf("%d",&n);
    adj.resize(n+2);
    REP(i,1,n-1)
    {
        scanf("%d%d",&a,&b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int root=1;
    dfs(root);
    int kq=1000000000;
    int valOfRoot;
    REP(i,1,3)
    if(f[root][i]<kq) {
        kq=f[root][i];
        valOfRoot=i;
    }
    //cout<<kq<<endl;
    printf("%d\n",kq);
    create(root,valOfRoot);
    REP(i,1,n)
    {
        printf("%d\n",v[i]);    
    }
    
}
void dfs(int a)
{
    REP(i,1,3)
        f[a][i]=i;    
    int ke;
    REP(i,0,adj[a].size()-1)
    { 
        ke=adj[a][i];
        if(ke!=parent[a])
        {
            parent[ke]=a;
            dfs(ke);
            f[a][1]+=min(f[ke][2],f[ke][3]);    
            f[a][2]+=min(f[ke][1],f[ke][3]);
            f[a][3]+=min(f[ke][2],f[ke][1]);            
        }               
    }
}
void create(int a, int val)
{
    v[a]=val;
    int ke;
    REP(i,0,adj[a].size()-1)
    {
        ke=adj[a][i];
        if(ke!=parent[a])
        {   
            int kq=1000000000;
            int newV;
            REP(j,1,3)
            {   
                if(j!=val && f[ke][j]<kq)
                {
                    kq=f[ke][j];
                    newV=j;
                }    
            }
            create(ke,newV);
        }   
    }           
}



