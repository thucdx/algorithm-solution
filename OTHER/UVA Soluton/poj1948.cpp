#include <algorithm>
#include <cmath>
using namespace std;

int n;
bool f[2][1650][1650];
int l[41];

int area(int x, int y, int z)
{
    double a = 1.0 * x + y + z;
    a /= 2;
    a = sqrt(a*(a-1.0*x)*(a-1.0*y)*(a-1.0*z));
    return int(a * 100);
}

int main()
{
//    freopen("pasture.3.in", "r", stdin);
//    freopen("pasture.out", "w", stdout);
    int tot = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", l + i);
        tot += l[i];
    }
    memset(f, 0, sizeof(f));
    int p = 0;
    f[p][0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        memset(f[1-p], 0, sizeof(f[1-p]));
        for (int j = 0; j <= tot; j++)
            for (int k = 0; k <= tot; k++)
                if (f[p][j][k])
                {
                    f[1-p][j+l[i]][k] = true;
                    f[1-p][j][k+l[i]] = true;
                    f[1-p][j][k] = true;
                }
        p = 1 - p;
    }
    int ans = -1;
    for (int i = 1; i <= tot; i++)
        for (int j = 1; j <= tot; j++)
            if (f[p][i][j])
            {
                int k = tot - i - j;
                if (i + j > k && i + k > j && k + j > i
                    && abs(i - j) < k && abs(i - k) < j && abs(k - j) < i)
                {
                    int t = area(i, j, k);
                    ans >?= t;
                }
            }           
    printf("%d\n", ans); 
//    fclose(stdout);
    return 0;
}
