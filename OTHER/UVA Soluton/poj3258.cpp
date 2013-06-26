#include <algorithm>
using namespace std;

const int   MAXN = 50000;
int     l, n, m;
int     p[MAXN];
 
void init()
{
    scanf("%d %d %d", &l, &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", p + i);
}

void solve()
{
    sort(p, p + n);
    int     low = 0, high = l + 1, mid;
    int     i, d, num; 
    
    while (low + 1 < high)
    {
        mid = (low + high) >> 1;
        d = 0;
        num = 0;
        for (i = 0; i < n; i++)
            if (p[i] - d < mid)
                num++;
            else d = p[i];
        if (num <= m) low = mid; else high = mid;
    }
    printf("%d\n", low);
}

int main()
{
    init();
    solve();
    return 0;
}
