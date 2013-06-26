#include <algorithm>
using namespace std;

int     n;
int     f[2][2][2];    

int solve()
{
    int     i, t, k = 0;
    memset(f, 0, sizeof(f));
    for (i = 1; i <= n; i++)
    {
        k = 1 - k;
        scanf("%d", &t);
        f[k][0][0] = max(f[1-k][0][0], f[1-k][0][1]); 
        f[k][0][1] = max(f[1-k][1][0], f[1-k][1][1]) - t;
        f[k][1][0] = max(f[1-k][1][0], f[1-k][1][1]);
        f[k][1][1] = max(f[1-k][0][0], f[1-k][0][1]) + t;
    }
    t = max(f[k][0][0], f[k][0][1]);
    t = max(f[k][1][0], t);
    t = max(f[k][1][1], t);
    return t;   
}

int main()
{
    scanf("%d", &n);
    printf("%d\n", solve() );
}
