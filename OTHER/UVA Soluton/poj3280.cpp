//poj3280
#include <algorithm>
using namespace std;

int     n, m;
char    str[2010];
int     cost[26];
int     f[2010][2010];

int main()
{
    int     i, j, l;
    scanf("%d%d%s", &n, &m, str); 
    getchar();
    char    c;
    int     a, b;
    for (i = 0; i < n; i++)
    {
        c = getchar();
        scanf("%d%d", &a, &b);
        getchar();
        cost[c - 'a'] = min(a, b);        
    }
    memset(f, 0, sizeof(f));
    for (l = 0; l < m; l++)
        for (i = 0; i + l < m; i++)
        {
            j = i + l;
            if (i == j || i + 1 == j && str[i] == str[j])  f[i][j] = 0;
            else
            {
                f[i][j] = min( f[i + 1][j] + cost[str[i] - 'a'], f[i][j - 1] + cost[str[j] - 'a'] );
                if (str[i] == str[j] && f[i + 1][j - 1] < f[i][j])
                    f[i][j] = f[i + 1][j - 1];
            }
        }
    printf("%d\n", f[0][m - 1]);
    return 0;
}
