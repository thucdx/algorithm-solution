#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector <int> adj[805];
vector <int> prev[805];
bool pass[805];
void bfs(int a);
int n,m;
int main()
{   
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    scanf("%d%d",&n,&m);
    for(int i=1,a,b;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);    
        prev[b].push_back(a);
    }
    int k=0;
    for(int i=1;i<=n;i++)
    {
        if(!pass[i])
        {
            bfs(i);
            ++k;
        }
    }
    cout<<k;
}
void bfs(int a)
{   
    if(pass[a]) return ;
    pass[a]=true;
    cout<<a<<" ";
    for(int j=0;j<adj[a].size();j++)
    {
        bfs(adj[a][j]); 
    }
    for(int j=0;j<prev[a].size();j++)
    {
        bfs(prev[a][j]);    
    }
}
