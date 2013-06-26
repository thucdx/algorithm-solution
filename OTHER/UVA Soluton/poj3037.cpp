#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

const int MAXN = 110;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
double v0;
int n, m;
double h[MAXN][MAXN];
double d[MAXN][MAXN];
int mk[MAXN][MAXN];
deque<pair<int, int> > q;

int main()
{
    scanf("%lf %d %d", &v0, &n, &m);
    double h0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i == 0 && j == 0)
            {
                scanf("%lf", &h0);
                h[i][j] = 1;
                d[i][j] = 0;
            }
            else
            {
                scanf("%lf", &h[i][j]);
                h[i][j] = pow(2.0, h[i][j] - h0);
                d[i][j] = 1e50;
            }
    q. clear();
    memset(mk, 0, sizeof(mk));
    q. push_back(make_pair(0, 0));
    int p = 0;
    while (++p, !q. empty())
    {
        int x = q. front(). first;
        int y = q. front(). second;
        q. pop_front();
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
            if (d[x][y] + h[x][y] < d[tx][ty])
            {
                d[tx][ty] = d[x][y] + h[x][y];
                if (mk[tx][ty] != p)
                {
                    q. push_back(make_pair(tx, ty));
                    mk[tx][ty] = p;
                }
            }
        }
    }
    printf("%.2lf\n", d[n - 1][m - 1] / v0); 
    return 0;
}
