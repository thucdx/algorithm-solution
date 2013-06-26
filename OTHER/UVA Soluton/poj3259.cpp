#include <algorithm>
#include <vector>
using namespace std;

struct  edge
{   
    int     u, v, w;
    edge (int _u = 0, int _v = 0, int _w = 0)
    {
        u = _u; v = _v; w = _w;
    }
}   e[6000];
int     n, m, w;

void solve()
{
    scanf("%d %d %d", &n, &m, &w);
    int     i, k, a, b, t;
    int     es = 0;
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &t);
        a--;  b--;
        e[es++] = edge(a, b, t);
        e[es++] = edge(b, a, t);
    }
    for (i = 0; i < w; i++)
    {
        scanf("%d %d %d", &a, &b, &t);
        a--;  b--;
        e[es++] = edge(a, b, t * (-1));
    }
    
    int     dist[500];
    memset(dist, 0, sizeof(dist));
    for (k = 0; k <= n; k++)
        for (i = 0; i < es; i++)
            dist[e[i]. v] <?= dist[e[i]. u] + e[i]. w;
            
    bool    cycle = false;
    for (i = 0; i < es; i++)
        if (dist[e[i]. v] > dist[e[i]. u] + e[i]. w) 
        {
            cycle = true;
            break;
        }
    
    if (cycle) printf("YES\n"); else printf("NO\n");
}

int main()
{
    int     cases;
    scanf("%d", &cases);
    while (cases--)
        solve();
    system("pause");
    return 0;
}
