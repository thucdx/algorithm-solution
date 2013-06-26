#include <algorithm>
using namespace std;

int n, l;
int p[1010];
int f[1010][1010][2];

int solve(int x, int y, int st)
{
    if (x == 0 && y == n) return 0;
    if (f[x][y][st] != -1) return f[x][y][st];
    int &ret = f[x][y][st];
    ret = 0x7fffffff;
    int t, u;
    if (st == 0) t = x; else t = y;
    
    if (x != 0)
    {
        u = solve(x - 1, y, 0) + abs(p[t] - p[x-1]) * (x + n - y - 1);
        if (u < ret) ret = u;
    }
    if (y != n)
    {
        u = solve(x, y + 1, 1) + abs(p[t] - p[y+1]) * (x + n - y - 1);    
        if (u < ret) ret = u;
    }
    return ret;
}


int main()
{
    scanf("%d %d", &n, &l);
    int i, j;
    for (i = 0; i < n; i++)
        scanf("%d", p + i);
    p[n++] = l;
    sort(p, p + n);
    int t ;
    for (i = 0; i < n; i++)
        if (p[i] == l)
        {
            t = i;
            break;
        }
    memset(f, -1, sizeof(f));
    int ans = solve(t, t, 0);
    printf("%d\n", ans);
    return 0;
}
