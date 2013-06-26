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

bool adj[105][105];
int deg[105];
int nStudent, nGroup,nLace;
int solve();
int main()
{
    //freopen("input.txt",  "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    scanf("%d%d",&nStudent,&nLace);
    int a,b;
    memset(adj,false,sizeof(adj));
    memset(deg,0,sizeof(deg));
    for(int i=1;i<=nLace;i++)
    {
        scanf("%d%d",&a,&b);
        adj[a][b]=true;
        adj[b][a]=true;
        deg[a]++;
        deg[b]++;
    }
    cout<<solve();
}
int solve()
{
    bool cont=true;
    int result=0;
    while(cont)
    {
        bool tmp[105][105];
        int tDeg[105];
        //copy trang tha
        for(int i=1;i<=nStudent;i++)
        for(int j=1;j<=nStudent;j++)
        {
            tmp[i][j]=adj[i][j];
        }
        for(int i=1;i<=nStudent;i++)
            tDeg[i]=deg[i];
        cont=false;
        for(int i=1;i<=nStudent;i++)
        {
            if(deg[i]==1) //
            {
                tDeg[i]=0;
                cont=true;
                for(int j=1;j<=nStudent;j++)
                {
                    if(adj[i][j]==true){
                        tmp[j][i]=false;
                        tmp[i][j]=false;
                        tDeg[j]--;
                    }
                }
            }    
        } 
        //copy trang tha
        for(int i=1;i<=nStudent;i++)
        for(int j=1;j<=nStudent;j++)
        {
            adj[i][j]=tmp[i][j];
        }
        for(int i=1;i<=nStudent;i++)
            deg[i]=tDeg[i];  
        if(cont) result++;
    }
    return result;
}
    
