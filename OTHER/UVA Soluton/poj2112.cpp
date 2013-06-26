#include <algorithm>
using namespace std;

bool g[500][500];
int tg[350][350];
int cy[500];
bool sy[500];
int k, c, m, tmax, nx;

int path(int u)
{
    for (int v = 1; v <= c; v++)
        if (g[u][v] && !sy[v])
        {
            sy[v] = true;
            if (!cy[v] || path(cy[v]))
            {
                cy[v] = u;
                return 1;
            }
        }
    return 0;
}

int match()
{
    int ret = 0;
    memset(cy, 0, sizeof(cy));
    for (int i = 1; i <= nx; i++)
    {
        memset(sy, 0, sizeof(sy));
        ret += path(i);
    }
    return ret;
}

void make(int l)
{
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= k; i++)
        for (int j = k + 1; j <= k + c; j++)
            if (tg[i][j] && tg[i][j] <= l)
                for (int t = m * (i - 1) + 1; t <= i * m; t++) 
                    g[t][j - k] = true;  
}

bool check(int l)
{
    make(l);
    return (match() == c);
}

void solve()
{
    int low = 0, high = tmax, mid;
    while (low + 1 < high)
    {
        mid = (low + high) / 2;
        if (check(mid)) high = mid; else low = mid;
    }
    printf("%d\n", high);
}

void init()
{
    scanf("%d %d %d", &k, &c, &m);
    tmax = 0;
    for (int i = 1; i <= k + c; i++)
        for (int j = 1; j <= k + c; j++)
            scanf("%d", &tg[i][j]);
    for (int p = 1; p <= k + c; p++)
        for (int i = 1; i <= k + c; i++)
            if (tg[i][p])
            for (int j = 1; j <= k + c; j++)
                if(tg[p][j])
                    if (tg[i][p] + tg[p][j] < tg[i][j] || !tg[i][j])
                        tg[i][j] = tg[i][p] + tg[p][j];
    for (int i = 1; i <= k + c; i++)
        for (int j = 1; j <= k + c; j++)
            tmax >?= tg[i][j];
    nx = k * m;
}

int main()
{
//    freopen("milking.4.in", "r", stdin);
//    freopen("milking.out", "w", stdout);
    init();
    solve();
//    fclose(stdout);
    return 0;
}
