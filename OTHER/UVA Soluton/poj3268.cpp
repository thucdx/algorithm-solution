#include <algorithm>
using namespace std;

int     n, m, x;
int     g[1010][1010];
int     d[1010], d1[1010];
bool    mk[1010];

int main()
{
    int     i, j, min;
    scanf("%d%d%d", &n, &m, &x);
    memset(g, -1, sizeof(g));
    int temp;
    while (m--)
    {
        scanf("%d%d", &i, &j);
        scanf("%d", &g[i][j]);
    }
    memset(mk, 0, sizeof(mk));
    for (i = 1; i <= n; i++) d[i] = 0x3fffffff;
    d[x] = 0;
    while(1)
    {
        j = 0;  min = 0x3fffffff;
        for (i = 1; i <= n; i++) 
            if (!mk[i] && d[i] < min)
            {
                min = d[i];  j = i;
            }
        if (!j) break;
        mk[j] = true;
        for (i = 1; i <= n; i++)
            if (!mk[i] && g[j][i] != -1 && min + g[j][i] < d[i])
                d[i] = min + g[j][i];
    }

    memset(mk, 0, sizeof(mk));
    for (i = 1; i <= n; i++) d1[i] = 0x3fffffff;
    d1[x] = 0;
    while(1)
    {
        j = 0;  min = 0x3fffffff;
        for (i = 1; i <= n; i++) 
            if (!mk[i] && d1[i] < min)
            {
                min = d1[i];  j = i;
            }
        if (!j) break;
        mk[j] = true;
        for (i = 1; i <= n; i++)
            if (!mk[i] && g[i][j] != -1 && min + g[i][j] < d1[i])
                d1[i] = min + g[i][j];
    }
    int ans = 0;
    for (i = 1; i <= n; i++)
        if (d[i] + d1[i] > ans) 
            ans = d[i] + d1[i];
    printf("%d\n", ans);
    return 0;
}
