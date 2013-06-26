#include <algorithm>
using namespace std;

int     x[310], y[310];
int     n, m;
int     f[310], p[310];


int main()
{
    int     i, j, r, t, k;
    scanf("%d %d", &m, &n);
    memset(x, 0, sizeof(x));
    for (i = 1; i <= n; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }
    f[0] = 1; p[0] = 0;
    for (i = 1; i <= n; i++)
    {
        f[i] = 0x3fffffff;
        t = x[i], k = y[i];
        for (j = i - 1; j >= 0 && t <= m && k <= m; j--)
        {
            r = f[j] + 2 - (p[j] <= m - t);
            if (r < f[i] || r == f[i] && p[i] > k)
                f[i] = r, p[i] = k;
            t += x[j];
            k += y[j];
        }
    }
    printf("%d\n", f[n] + 1);
    return 0;
}
