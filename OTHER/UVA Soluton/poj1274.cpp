#include <algorithm>
using namespace std;

bool    g[210][210];
int     n, m, ans;
int     link[210];
bool    y[210];

bool find(int u)
{
    for (int i = 1; i <= m; i++)
        if (g[u][i] && !y[i])
        {
            y[i] = true;
            if (link[i] == 0 || find(link[i]))
            {    
                link[i] = u;
                return true;
            }
        }
    return false;
}

int main()
{
    int     i, t, p, j;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        memset(g, 0, sizeof(g));
        for ( i = 1; i <= n; i++)
        {   
            scanf("%d", &t);
            for (j = 0; j < t; j++)
            {   
                scanf("%d", &p);
                g[i][p] = true;
            }
        }
        memset(link, 0, sizeof(link));
        for (ans = 0, i = 1; i <= n; i++)
        {
            memset(y, 0, sizeof(y));
            if (find(i)) ans++;
        }
        printf("%d\n", ans); 
    }
}
