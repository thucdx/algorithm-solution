
//ok
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include <sstream>
#include<algorithm>
#include<map>
using namespace std;

const int MAXN=210;
const int INF=1000000000;

vector<int>G[MAXN];
int dp[MAXN][MAXN];
int cost[MAXN],in[MAXN];
bool vi[MAXN];
int n,m;

int dfs(int u){
    vi[u]=1;
    int num=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(vi[v])continue;
        num+=dfs(v);
    }
    for(int j=0;j<=n;j++)dp[u][j]=INF;
    dp[u][0]=0;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        for(int j=n;j;j--){
            for(int k=1;j-k>=0;k++)
                if(dp[u][j]>dp[u][j-k]+dp[v][k])
                    dp[u][j]=dp[u][j-k]+dp[v][k];
        }
    }
    //??????,??num?????????,???????,?????!
    if(dp[u][num]>cost[u])dp[u][num]=cost[u];
    return num;
}
int main(){
    char str[1000];
    while(gets(str)){
        if(str[0]=='#')break;
        sscanf(str,"%d%d",&n,&m);
        for(int i=0;i<=n;i++)G[i].clear();
        map<string,int>Map;
        memset(in,0,sizeof(in));
        int ID=0;
        for(int i=1;i<=n;i++){
            scanf("%s",str);
            if(Map.find(str)==Map.end())Map[str]=++ID;
            int u=Map[str];
            scanf("%d",&cost[u]);
            //while(getchar()==' '){//??????!
            //    scanf("%s",str);
            //    if(Map.find(str)==Map.end())Map[str]=++ID;
            //    G[u].push_back(Map[str]);
            //    in[Map[str]]++;
            //}
            gets(str);
            stringstream ss(str);
            string name;
            while(ss>>name){
                if(Map.find(name)==Map.end())Map[name]=++ID;
                G[u].push_back(Map[name]);
                in[Map[name]]++;
            }
        }
        cost[0]=INF;
        for(int i=1;i<=n;i++){
            if(in[i])continue;
            G[0].push_back(i);
        }
        memset(vi,0,sizeof(vi));
        dfs(0);
        int ans=INF;
        for(int j=m;j<=n;j++)
            if(dp[0][j]!=-1&&dp[0][j]<ans)ans=dp[0][j];
        printf("%d\n",ans);
    }
    return 0;
}
