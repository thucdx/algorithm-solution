#include <algorithm>
using namespace std;
const int   MAXN = 5010;
int     n;
int     a[MAXN], b[MAXN];
int     bk, bm;

int count(int k)
{
    int     i, j, ret = 0;
    memcpy(b, a, sizeof(a));
    for (i = 0; i <= n - k; i++)
        if (b[i])
        {
            ret++;
            if (ret >= bm) return 100000;
            b[i + k] ^= 1;
        }
    for (; i < n; i++)
        if (b[i]) return 100000;
    return ret;
}

int main()
{
    int     i, t;
    char    c[2], dir;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for (i = 0, dir = 'F'; i < n; i++)
    {
        scanf("%s", c);
        if (c[0] != dir)
        {
            dir = c[0];
            a[i] = 1;
        }
    }
    bm = 100000;
    for (i = 1; i <= n; i++)
    {
        t = count(i);
        if (t < bm)
        {
            bm = t;
            bk = i;
        }
    }
    printf("%d %d\n", bk, bm);
    return 0;
}
