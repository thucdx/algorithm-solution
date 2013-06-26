#include <algorithm>
#include <vector>
using namespace std;

int     n, m;
int     f[16][4096];
int     ma[16];

const int   MOD = 100000000;


int main()
{
    int     i, j, k;
    scanf("%d %d", &n, &m);
    int     p = 1 << m;
    memset(ma, 0, sizeof(ma));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            scanf("%d", &k);
            if (!k) ma[i + 1] |= (1 << j);
        }


    vector<int> q;
    for (i = 0; i < p; i++)
        if ( !(i &(i << 1)) ) q.push_back(i);    
    memset(f, 0, sizeof(f));
    for (i = 0; i < p; i++) f[0][i] = 1;
    int     u;
    for (i = 1; i <= n; i++)
        for (j = 0; j < p; j++)
        {
            if (~j & ma[i]) continue;
            for (size_t k = 0; k < q. size(); k++)
            {
                u = q[k];
                if (u & j) continue;
                f[i][j] += f[i-1][u | ma[i-1]];
                f[i][j] %= MOD;  
            }
        }
    printf("%d\n", f[n][ma[n]]);
    return 0;
}
