#include <algorithm>
using namespace std;

int main()
{
    int     n, k;
    int     f[1010][40];
    scanf("%d%d", &n, &k);
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    int     i, j, l, g;
    for (i = 1; i <= k; i++)
        for (j = i; j <= n; j++)
        {
            g = 0;
            for (l = 0; l < 40; l++)
            {
                g = f[j][l] + f[j-i][l] + g;
                f[j][l] = g % 10;
                g /= 10;
            }
        }
    for (i = 39; ; i--)
        if (f[n][i]) break;
    while (i >= 0)
        printf("%d", f[n][i--]);
    printf("\n");
    return 0;
}
