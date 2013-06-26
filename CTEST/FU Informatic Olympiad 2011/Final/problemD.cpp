//ok
#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 205;

struct{
    int v, nxt;
}edge[MAX];
int k, edgeHead[MAX];
char name[MAX][105];
int n, nn, dp[2][MAX];
bool uni[2][MAX];

void addEdge(int u, int v){
    edge[k].v = v;
    edge[k].nxt = edgeHead[u];
    edgeHead[u] = k ++;
}

void dfs(int u){
    int i, v;
    dp[0][u] = 0;
    dp[1][u] = 1;
    for(i = edgeHead[u]; i; i = edge[i].nxt){
        v = edge[i].v;
        dfs(v);
        if(dp[0][v] > dp[1][v]){
            dp[0][u] += dp[0][v];
            if(!uni[0][v]) uni[0][u] = false;
        }else if(dp[0][v] < dp[1][v]){
            dp[0][u] += dp[1][v];
            if(!uni[1][v]) uni[0][u] = false;
        }else{
            dp[0][u] += dp[0][v];
            uni[0][u] = false;
        }
        dp[1][u] += dp[0][v];
        if(!uni[0][v]) uni[1][u] = false;
    }
}

int sch(char *str){
    for(int i = 1; i < nn; i ++)
        if(!strcmp(str, name[i]))
            return i;
    strcpy(name[nn ++], str);
    return nn-1;
}

int main(){
    int i, u, v;
    char str[105];
    while(scanf("%d", &n) && n){
        for(i = 0; i <= n; i ++){
            strcpy(name[i], "");
            edgeHead[i] = 0;
            uni[0][i] = uni[1][i] = true;
        }
        scanf("%s", name[1]);
        k = 1, nn = 2;
        for(i = 2; i <= n; i ++){
            scanf("%s", str);
            v = sch(str);
            scanf("%s", str);
            u = sch(str);
            addEdge(u, v);
        }
        addEdge(0, 1);
        dfs(0);
        printf("%d ", dp[0][0]);
        if(uni[0][0]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
