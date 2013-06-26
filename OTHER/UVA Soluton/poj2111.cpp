#include <algorithm>
using namespace std;

const int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int n;
int a[400][400];
int f[400][400];
int b[400][400];
pair<int, int> p[400][400];

void init()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    memset(f, -1, sizeof(f));
}

int calc(int x, int y)
{
    if (f[x][y] >= 0) return f[x][y];
    for (int d = 0; d < 8; d++)
    {
        int tx = x + dx[d], ty = y + dy[d];
        if (!(tx > 0 && tx <= n && ty > 0 && ty <= n)) continue;
        if (a[tx][ty] < a[x][y]) continue;
        int t = calc(tx, ty);
        if (t + 1 > f[x][y] || t + 1 == f[x][y] && a[tx][ty] < b[x][y]) 
        {
            f[x][y] = t + 1;
            b[x][y] = a[tx][ty];
            p[x][y]. first = tx, p[x][y]. second = ty;
        }
    }
    if (f[x][y] < 0) f[x][y] = 0;
    return f[x][y];
}

void printans(int x, int y)
{
    printf("%d\n", a[x][y]);
    if (f[x][y]) printans(p[x][y]. first, p[x][y]. second);
}

void solve()
{
    int ans = -1, x = 0, ax = 0, ay = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int t = calc(i, j);
            if (t > ans || t == ans && a[i][j] < x) 
            {
                ans = t, x = a[i][j];
                ax = i, ay = j;
            }
        }
    printf("%d\n", ans + 1);
    printans(ax, ay);
}

int main()
{
    init();
    solve();
    return 0;
}
