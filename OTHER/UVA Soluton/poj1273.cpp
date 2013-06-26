#include <algorithm>

int     c[210][210], f[210][210];
int     pnt[210], d[210], mk[210];
int     n, m;
int     u, v, w;

int maxflow()
{
    int     cur, tail, i, j, u, v, flow = 0;
    int     open[1000];
    memset(f, 0, sizeof(f));
    
    do
    {
        memset(mk, 0, sizeof(mk));  memset(d, 0, sizeof(d));
        open[0] = 1;  mk[1] = 1;  d[1] = 0x3fffffff;
        for (pnt[1] = cur = tail = 0; cur <= tail && !mk[n]; cur++)
            for (u = open[cur], v = 1; v <= n; v++)
                if (!mk[v] && f[u][v] < c[u][v])
                {
                    mk[v] = 1;  open[++tail] = v; pnt[v] = u;
                    if (d[u] < c[u][v] - f[u][v]) d[v] = d[u];
                        else d[v] = c[u][v] - f[u][v]; 
                }
        if (!mk[n]) break;
        flow += d[n];
        for (u = n; u != 1; ) 
        { 
            v = u;   u = pnt[v]; 
            f[u][v] += d[n];  f[v][u] = -f[u][v]; 
        }
    }while (d[n] > 0);
    return flow;
}

int main()
{
    while (scanf("%d %d", &m, &n) != EOF)
    {
        memset(c, 0, sizeof(c));
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            c[u][v] += w;            
        }
        printf("%d\n", maxflow());
    }
    return 0;
}
