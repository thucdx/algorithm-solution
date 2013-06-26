#include <algorithm>
#include <math.h>
using namespace std;

int     mina[17][50000], maxa[17][50000];
int     n, m;

int main()
{
    freopen("lineup.2.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int     i, j, k, l, a, b;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &j);
        mina[0][i] = maxa[0][i] = j;
    }
    for (l = 2, k = 1, i = 1; l <= n; l *= 2, k *= 2, i++)
        for (j = 1; j <= n; j++)
        {
            mina[i][j] = min ( mina[i-1][j], mina[i-1][j+k] );
            maxa[i][j] = max ( maxa[i-1][j], maxa[i-1][j+k] ); 
        }
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        for (l = 0, j = 1; a + j - 1 < b; j *= 2, l++);
        if (a + j - 1 > b) l--, j/= 2;
        k =  max(maxa[l][a], maxa[l][b-j+1]) - min(mina[l][a], mina[l][1+b-j]);
        printf("%d\n", k ); 
    }
    fclose(stdout);
    return 0;
}
