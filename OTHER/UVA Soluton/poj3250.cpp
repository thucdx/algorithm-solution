#include <algorithm>
using namespace std;

int     n;
int     h[100000], l[100000];

int main()
{
    int     i, c;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", h + i);
    for (i = n - 1; i >= 0; i--)
    {
        l[i] = i + 1;
        while (l[i] < n && h[l[i]] < h[i])
            l[i] = l[l[i]];
    }
    __int64 ans = 0;
    for (i = 0; i < n; i++)
        ans += l[i] - i - 1;
    printf("%I64d\n", ans);
    return 0;
}
