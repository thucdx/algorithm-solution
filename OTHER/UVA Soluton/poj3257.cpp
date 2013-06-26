#include <algorithm>
#include <vector>
using namespace std;

const int MAXL = 1001;

struct node 
{
    int t, f, c;
    node (int _t = 0, int _f = 0, int _c = 0)
    {
        t = _t; f = _f; c = _c;
    }
};

int l, n, b;
vector<vector<node> > g;

int f[MAXL][MAXL*2];

void init()
{
    int tx, tl, tf, tc;
    scanf("%d %d %d", &l, &n, &b);
    g. resize(l);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d %d %d", &tx, &tl, &tf, &tc);
        g[tx]. push_back(node(tx + tl, tf, tc));
    }
}

void solve()
{
    memset(f, 255, sizeof(f));
    for (int i = 0; i <= b; i++) f[0][i] = 0;
    for (int i = 0; i < l; i++)
        for (int j = 0; j <= b; j++)
        {
            if (f[i][j] == -1) continue;
            for (int k = 0; k < g[i]. size(); k++)
                f[g[i][k].t][j+g[i][k].c] >?= f[i][j] + g[i][k]. f;
        }
    printf("%d\n", f[l][b]);
}

int main()
{
    init();
    solve();
    return 0;   
}
