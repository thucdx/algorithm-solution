#include <algorithm>
using namespace std;

int     n;
int     a[400][400];

int main()
{
    int     i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);
    for (i = 2; i <= n; i++)
        for (j = 1; j <= i; j++)
            a[i][j] += max(a[i-1][j], a[i-1][j-1]);
    for (j = 1, i = 2; i <= n; i++)
        if (a[n][i] > a[n][j]) j = i;
    printf("%d\n", a[n][j]);
    return 0;
}
