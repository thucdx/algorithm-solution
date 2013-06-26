#include <algorithm>
using namespace std;

int     n, w;
int     f[1010][40][2];

int main()
{
    int     i, j, t;
    scanf("%d%d", &n, &w);
    memset(f, -1, sizeof(f));
    f[0][0][1] = f[0][0][0] = 0;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &t);
        t--;
        f[i][0][t] = f[i-1][0][t] + 1;
        f[i][0][1-t] = f[i-1][0][1-t];
        for (j = 1; j <= w; j++)
        {
            f[i][j][t] = max( f[i-1][j][t], f[i-1][j-1][1-t] ) + 1;
            f[i][j][1-t] = max( f[i-1][j][1-t], f[i-1][j-1][t] );
        }        
    }
    int     ans = 0;
    for (i = 0; i <= w; i++)
    {
        if (f[n][i][0] > ans) ans = f[n][i][0];
        if (f[n][i][1] > ans) ans = f[n][i][1];
    }
    printf("%d\n", ans);
    return 0;
}
