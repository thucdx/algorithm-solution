#include <algorithm>
using namespace std;

bool    a[15][15], p[15][15];
bool    answer[15][15], w[15][15];
int     n, m, ans;
bool    list[15];

void init()
{
    int     i, j, k, t;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            scanf("%d", &t);
            a[i][j] = ( t == 1 );
        }
}

void flip(int x, int y)
{
    p[x][y] = !p[x][y];
    if (x > 0) p[x-1][y] = !p[x-1][y];
    if (x < n - 1) p[x+1][y] = !p[x+1][y];
    if (y > 0) p[x][y-1] = !p[x][y-1];
    if (y < m - 1) p[x][y+1] = !p[x][y+1]; 
}

bool check()
{
    int     i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            p[i][j] = a[i][j];
    for (i = 0; i < m; i++)
    {
        w[0][i] = list[i];
        if (w[0][i]) flip(0, i);
    }
    for (i = 1; i < n; i++)
        for (j = 0; j < m; j++)
        {
            w[i][j] = p[i - 1][j];
            if (p[i - 1][j]) flip(i, j);
        }
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (p[i][j]) return false;
    return true;
}

void update()
{
    int     i, j, k = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (w[i][j]) k++;
    if (k < ans) 
    {
        ans = k;              
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                answer[i][j] = w[i][j];
    }
}

void search(int k)
{
    if (k == m) 
    {
        if (check()) update();
        return;
    }
    list[k] = false;
    search(k + 1);
    list[k] = true; 
    search(k + 1);
}

void solve()
{
    ans = 1000000;
    search(0);
    if (ans == 1000000) 
    {
        printf("IMPOSSIBLE\n");
        return;
    }
    int  i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {    
            printf("%d", answer[i][j]);
            if (j == m - 1) printf("\n"); else printf(" ");
        }
}

int main()
{
    init();
    solve();   
}
