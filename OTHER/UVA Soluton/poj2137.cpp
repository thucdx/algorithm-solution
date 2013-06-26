#include <algorithm>
#include <cmath>
using namespace std;

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt( (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) );    
}


int n, m;
double f[110][50];
int p[110][50][2];
int s[110];

double calc(int x)
{
    for (int i = 0; i < s[1]; i++) f[1][i] = dist(p[1][i][0], p[1][i][1], p[0][x][0], p[0][x][1]);
    for (int i = 2; i < n; i++)
        for (int j = 0; j < s[i]; j++)
        {
            f[i][j] = 1e20;
            for (int k = 0; k < s[i-1]; k++)
            {
                double t = f[i-1][k] + dist(p[i][j][0], p[i][j][1], p[i-1][k][0], p[i-1][k][1]);
                if (t < f[i][j]) f[i][j] = t;
            }
        }
    double ret = 1e20;
    for (int i = 0; i < s[n - 1]; i++)
    {
        double t = f[n-1][i] + dist(p[n-1][i][0], p[n-1][i][1], p[0][x][0], p[0][x][1]);
        ret <?= t;
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
        for (int j = 0; j < s[i]; j++)
            scanf("%d %d", &p[i][j][0], &p[i][j][1]);
    }
    double ans = 1e20;
    for (int i = 0; i < s[0]; i++)
        ans <?= calc(i);
    printf("%d\n", int (ans  * 100) );
    return 0;
}
