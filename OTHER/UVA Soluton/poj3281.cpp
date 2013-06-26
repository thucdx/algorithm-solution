#include <algorithm>
using namespace std;

int     c[510][510], f[510][510];
int     pnt[510], d[510], mk[510];
int     n, nfood, ndrink;

void init()
{
    int     i;
    memset(c, 0, sizeof(c));
    for (i = 2; i <= nfood + 1; i++)
        c[1][i] = 1;
    for (i = nfood + n*2 + 2; i <= nfood + n*2 + 1 + ndrink; i++)
        c[i][1 + nfood + n*2 + ndrink + 2] = 1;
    for (i = 1; i <= n; i++)
        c[nfood + 1 + i][nfood + 1 + n + i] = 1;
}

void inputdata(int k)
{
    int     n1, n2;
    int     i, t;
    scanf("%d%d", &n1, &n2);
    for (i = 0; i < n1; i++) 
    {
        scanf("%d", &t);
        c[t + 1][nfood + 1 + k] = 1;        
    }
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &t);
        c[nfood + 1 + n + k][nfood + n*2 + 1 + t] = 1;
    }    
}


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
    scanf("%d%d%d", &n, &nfood, &ndrink);
    init();    
    for (int i = 1; i <= n; i++)
        inputdata(i);
    n = 1 + nfood + n*2 + ndrink + 2;
    printf("%d\n", maxflow());
    return 0;
}
