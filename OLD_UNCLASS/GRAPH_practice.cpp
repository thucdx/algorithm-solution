#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 100000
#define INF 100000000

using namespace std;
vector <int> adj[MAX+5];
vector <int> dis[MAX+5];

int n,m;
struct V{
        int v, d;
        V(){}
        V(int _v, int _d) {
            v=_v;
            d=_d;
        }
        bool operator<(const V & that) const
        {
            if(d!=that.d)
             return (d< that.d)    ;
            return (v<that.v) ;
        }
};
void dfs(int a);
void bfs(int a);
void dijikstra(int a, int b);

void input();
void output();
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    input();
    //output();
    int i=1;
    cout<<"dfs from " <<i<<endl;
    dfs(1);            
    cout<<"\nBFS from "<<i<<endl;
    bfs(1);
    cout<<endl<<"DIJIKSTRA : ";
    dijikstra(1,6);
}
void input()
{
    scanf("%d%d",&n,&m);
    int a,b,d;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&a,&b,&d);
        adj[a].push_back(b);
        adj[b].push_back(a);
        dis[b].push_back(d);
        dis[a].push_back(d);    
    }
}
void output()
{
    for(int i=1;i<=n;++i)
    {
        printf("\n%d : ",i);
        for(int l=0;l<adj[i].size();++l)
        {
            printf("( %d , %d ) ",adj[i][l],dis[i][l]);
        }   
    }    
}
void dfs(int a)
{
    bool f[MAX+5];
    stack <int> q;
    memset(f,0,MAX+5);
    int v;
    q.push(a);
    while(!q.empty())
    {
        v=q.top();   
        q.pop();
        if(!f[v])
        {
            f[v]=true;
            printf("%d  ",v);
            for(int i=0;i<adj[v].size();i++)
            {
                
                int t=adj[v][i];
                if(!f[t])
                    q.push(t);    
                
            }       
        }
    }
}
void bfs(int a)
{   
    bool f[MAX+5];
    queue <int> q;
    int v;
    q.push(a);
    memset(f,0,MAX+5);
    while(!q.empty())
    {
          v=q.front();
          q.pop();
          if(!f[v])
          { 
                f[v]=true;
                cout<<v<<" ";
                for(int i=0;i<adj[v].size();i++)
                {
                    int t=adj[v][i];
                    if(!f[t]) q.push(t);
                        
                }        
          }  
    }
}
void dijikstra(int a, int b){
    
    set<V> s;
    int e[MAX+5];
    //memset(e,1, MAX+5);
    //cout<<e[0]<<" "<<endl;
    for(int i=0;i<=n;i++)
    e[i]=INF;
    s.insert(V(a,0));
    e[a]=0;
    while(!s.empty())
    {
            int vt=s.begin()->v;
            int dt=s.begin()->d;
            
            cout<<"consider "<<vt<<endl;
            s.erase(s.begin());
            if(vt==b) {
                printf(" Min from %d to %d  is: %d",a,b,dt); return ;
            }
            for(int t=0;t<adj[vt].size();t++)
            {   
                int temp=adj[vt][t];
                cout<<"_ "<<temp<<" _ "<<e[temp]<<" ";
                if(e[temp]> e[vt]+dis[vt][t])
                {
                    e[temp]=e[vt]+dis[vt][t];
                    s.insert(V(temp,e[temp]));
                    cout<<"DUa :"<<temp<<" ";
                }    
            }
    }
}
