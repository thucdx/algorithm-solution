#include <algorithm>
using namespace std;


int main()
{
    int     n, k, m, t, ans;
    bool    mk[10010];
    scanf("%d%d", &n, &k);
    memset(mk, 0, sizeof(mk));
    m = k;  
    ans = 0;  
    while (n--)
    {
        scanf("%d", &t);
        if (!mk[t]) 
        {
            m--;
            mk[t] = 1;
        }
        if (m == 0)
        {
            ans++;
            memset(mk, 0, sizeof(mk));
            m = k;
        }
    }
    printf("%d\n", ans + 1);
    return 0;
}
