#include <algorithm>
using namespace std;

int     k, n, m;
bool    g[1000][1000];
bool    mk[1000], amk[1000], hmk[1000];

void dfs(int v)
{
    mk[v] = true;
    for (int i = 0; i < n; i++)
        if (g[v][i] && !mk[i]) dfs(i);
}

int main()
{
    int     i, j, t;
    scanf("%d%d%d", &k, &n, &m);
    memset(hmk, 0, sizeof(hmk));
    for (i = 0; i < k; i++)
    {
        scanf("%d", &t);
        --t;
        hmk[t] = true;
    }
    memset(g, 0, sizeof(g));
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &t, &j);
        t--, j--;
        g[t][j] = true;
    }
    for (i = 0; i < n; i++)
        if (hmk[i])
        {   
            memset(mk, 0, sizeof(mk));
            dfs(i);
            hmk[i] = false;       
            break;            
        }
    
    memcpy(amk, mk, n);
    
    for (i = 0; i < n; i++)
        if (hmk[i])
        {   
            memset(mk, 0, sizeof(mk));
            dfs(i);
            for (j = 0; j < n; j++)
                amk[j] &= mk[j];       
        }
    for (t = i = 0; i < n; i++)
        t += amk[i];
    printf("%d\n", t); 
    return 0;
}
