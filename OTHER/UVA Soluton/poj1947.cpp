#include <algorithm>
using namespace std;
const int   MAX = 200;

int     n, p;
int     ls[200], rs[200];
int     f[200][200];

void init()
{
    scanf("%d %d", &n, &p);
    int     a, b;
    memset(ls, 0, sizeof(ls));
    memset(rs, 0, sizeof(rs));
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &a, &b);
        rs[b] = ls[a];
        ls[a] = b;
    }
}

int calc(int v, int j)
{
    if (f[v][j] < MAX) return f[v][j];
    if (v == 0 && j == 0) return f[0][0] = 0;
    if (v == 0 && j != 0) return f[0][j] = -1;
    int ret = calc(rs[v], j);
    if (ret != -1) ret++; else ret = MAX;
    int     a, b;
    for (int k = 0; k <= j - 1; k++)
    {
        a = calc(ls[v], k);
        b = calc(rs[v], j - k - 1);
        if (a < 0 || b < 0) continue;
        if (a + b < ret) ret = a + b;
    }
    if (ret == MAX) ret = -1;
    return f[v][j] = ret;
}

void solve()
{    
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= p; j++)
            f[i][j] = MAX;
    int     ans = calc(ls[1], p - 1);
    for (int i = 2; i <= n; i++)
    {
        int t = calc(ls[i], p - 1);
        if (t > -1 && t + 1 < ans) ans = t + 1;
    }
    printf("%d\n", ans);
}

int main()
{
    init();
    solve();
    return 0;
}
