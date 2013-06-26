#include <algorithm>
using namespace std;

int n, m;
bool mk[1010][90];
char graph[1010][90];
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int ans;

void floodfill(int x, int y, int &k)
{
    int tx, ty;
    mk[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        tx = x + dx[i];
        ty = y + dy[i];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= m)
            if (graph[tx][ty] == '*' && !mk[tx][ty])
                floodfill(tx, ty, ++k);
    }   
}

int main()
{
    memset(mk, 0, sizeof(mk));
    scanf("%d %d", &m, &n);
    int i, j, t;
    for (i = 1; i <= n; i++)
    {
        getchar();
        for (j = 1; j <= m; j++)
            graph[i][j] = getchar();
    }
    ans = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (graph[i][j] == '*' && !mk[i][j])
            {
                t = 1;
                floodfill(i, j, t);
                if (t > ans) ans = t;
            }
    printf("%d\n", ans);
    return 0;
}
