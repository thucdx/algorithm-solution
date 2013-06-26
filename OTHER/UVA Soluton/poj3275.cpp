#include <algorithm>
using namespace std;

const int   MAXN = 1010;
const int   MAXM = 10010;

struct Edge
{
    int v, next;  
};

bool    g[MAXN][MAXN]; 
int     n, m;
Edge    e[MAXM];
int     nbs[MAXN];
bool    mk[MAXN];

void dfs(int s, int i)
{
    g[s][i] = true;
    mk[i] = true;
    int     te = nbs[i];
    while (te)
    {
        if (!mk[ e[te].v ]) dfs(s, e[te]. v);
        te = e[te]. next; 
    }
}

int main()
{
    int     i, j, k;
    scanf("%d%d", &n, &m);
    memset(g, 0, sizeof(g));
    memset(nbs, 0, sizeof(nbs));
    for (k = 1; k <= m; k++)
    {
        scanf("%d%d", &i, &j);
        g[i][j] = true;
        e[k]. v = j;
        e[k]. next = nbs[i];        
        nbs[i] = k;
    }
    for (i = 1; i <= n; i++)
    {
        memset(mk, 0, sizeof(mk));
        dfs(i, i);
    }
    k = 0;
    for (i = 1; i <= n; i++)
        for (j = i + 1; j <= n; j++)
            if (!g[i][j] && !g[j][i]) 
                k++;
    printf("%d\n", k); 
    return 0;
}
