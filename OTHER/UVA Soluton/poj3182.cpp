#include <algorithm>
#include <queue>
using namespace std;

const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

struct Node
{
    int x, y, mk;
    Node() {};
    Node(int x, int y, int z) : x(x), y(y), mk(z) {};   
};

int n, m;
char a[60][60];
int f[2][60][60];
deque<Node> q;

void bfs(const int sx, const int sy, const int rx, const int ry)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[0][i][j] = f[1][i][j] = 0x3fffffff;
    f[0][sx][sy] = 0;
    q. push_back(Node(sx, sy, 0));
    while (!q. empty())
    {
        Node cur = q. front();
        int step = f[cur. mk][cur. x][cur. y];
        q. pop_front();
        for (int d = 0; d < 8; d++)
        {
            Node nxt(cur. x + dx[d], cur. y + dy[d], cur. mk);
            if (nxt. x <= 0 || nxt. x > n || nxt. x <= 0 || nxt. y > m) continue;
            if (a[nxt. x][nxt. y] == 'X') continue;
            if (cur. x == rx - 1 && nxt. x == rx && nxt. y < ry) continue;
            if (cur. x == rx && nxt. x == rx - 1 && cur. y < ry)
            {
                nxt. mk++;
                if (nxt. mk > 1) continue;
            } 
            if (step + 1 < f[nxt. mk][nxt. x][nxt. y])
            {
                f[nxt. mk][nxt. x][nxt. y] = step + 1;
                q. push_back(nxt);
            }
        }
    }
    printf("%d\n", f[1][sx][sy]);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        getchar();
        for (int j = 1; j <= m; j++)
            a[i][j] = getchar();
    }
    int xr, yr = 0, sx, sy = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 'X' && !yr)
                xr = i, yr = j;
            if (a[i][j] == '*') 
                sx = i, sy = j;
        }
    bfs(sx, sy, xr, yr);
    return 0;
}
