#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 10010;

vector<vector<int> > g, gg;
int n, m, num, t;
bool mk[MAXN];
int list[MAXN];

void back(int v)
{
    mk[v] = 1;  t++;
    for (size_t i = 0; i < gg[v]. size(); i++)
        if (!mk[gg[v][i]]) back(gg[v][i]);
}

void dfs(int u)
{
    mk[u] = 1;
    for (size_t i = 0; i < g[u]. size(); i++)
        if (!mk[g[u][i]]) dfs(g[u][i]);
    list[num--] = u;
}


int main()
{
    scanf("%d %d", &n, &m);
    g. resize(n + 1);
    gg. resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a]. push_back(b);  
        gg[b]. push_back(a);   
    }
    memset(mk, 0, sizeof(mk));
    num = n;
    for (int i = 1; i <= n; i++)
        if (!mk[i]) dfs(i);
    memset(mk, 0, sizeof(mk));
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!mk[list[i]]) 
        {
            t = 0;
            back(list[i]);
            if (t >= 2) ans++;
        }
    printf("%d\n", ans);
    return 0;
}
