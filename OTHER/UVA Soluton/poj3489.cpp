#include <algorithm>
using namespace std;

int     n, x, k;

int gcd(int a, int b)
{
    return (a==0) ? b : gcd(b % a, a);
}

int main()
{
    while (scanf("%d%d%d", &n, &x, &k) != EOF)
    {
        int     d = 0, t;
        while (n--)
        {
            scanf("%d", &t);
            d = gcd(d, t);
        }
        while (d % k == 0) d /= k;
        if (x % d == 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
