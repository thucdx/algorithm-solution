#include <algorithm>
using namespace std;

int     n, sum;
bool    mk[20];
int     a[20], p[20];
int     c[20][20];
bool    ok;

void prepare()
{
    int     i, j, k;
    for (k = 1; k <= n; k++)
    {
        memset(c, 0, sizeof(c));
        c[n][k] = 1;
        for (i = n - 1; i > 0; i--)
            for (j = 1; j <= i; j++)
                c[i][j] = c[i + 1][j] + c[i + 1][j + 1];
        p[k] = c[1][1];
    }
} 

void solve(int k, int s)
{
    if (s > sum) return;
    if (ok) return;
    if (k == n + 1)
    {
        if (s == sum)
        {
            for (int i = 1; i < n; i++)
                printf("%d ", a[i]);
            printf("%d\n", a[n]);
            ok = true;
        }
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!mk[i])
        {
            mk[i] = true;
            a[k] = i;
            solve(k + 1, s + p[k]*i);
            mk[i] = false;
        }
}

int main()
{
    scanf("%d%d", &n, &sum);
    prepare();
    memset(mk, 0, sizeof(mk));
    ok = false;
    solve(1, 0);
    return 0;
}
