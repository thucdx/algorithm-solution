#include <algorithm>
using namespace std;

int n, d, k;
int f[1000];

void init()
{
    scanf("%d %d %d", &n, &d, &k);
    for (int i = 0; i < n; i++)
    {
        int tn;
        scanf("%d", &tn);
        f[i] = 0;
        while (tn--)
        {
            int t;
            scanf("%d", &t);
            f[i] |= 1 << (t - 1);
        }
    }    
}


void solve()
{
    int ans = 0;
    for (int m = 0; m < (1 << d); m++)
    {
        int cnt = 0;
        for (int i = 0; i < d; i++)
            cnt += (m>>i) & 1;
        if (cnt > k) continue;
        int t = 0;
        for (int i = 0; i < n; i++)
            t += ((f[i] & ~m) == 0);
        ans >?= t;
    } 
    printf("%d\n", ans);
}

int main()
{
    init();
    solve();
    return 0;
}
