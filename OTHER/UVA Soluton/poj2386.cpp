#include <algorithm>

const int dx[8] = {  0, -1, -1, -1, 0, 1, 1,  1};
const int dy[8] = { -1 ,-1,  0,  1, 1, 1, 0, -1};

int     n, m, i, j, t;
char    g[110][110];
int     mk[110][110];

void floodfill(int x, int y, int p)
{
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (g[x][y] != 'W') return;
    if (mk[x][y]) return;
    mk[x][y] = p;
    for (int i = 0; i < 8; i++)
        floodfill(x + dx[i], y + dy[i], p);
}


int main()
{
    scanf("%d %d", &n, &m);
    getchar();
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            g[i][j] = getchar();
            mk[i][j] = 0;
        }
        getchar();
    }
    t = 0;
    for (i = 0; i < n; i++)
        for ( j = 0; j < m; j++)
            if (g[i][j] == 'W' && !mk[i][j])
               floodfill(i, j, ++t);
    printf("%d\n", t);
    return 0;
}
