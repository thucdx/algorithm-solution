#include <algorithm>
using namespace std;

int     a[100000];
int     n, m;
int     low, high, mid;

bool ok(int x)
{
    int     i, t = a[0], p = 1; 
    for (i = 1; i < n; i++)
    {
        t += a[i];
        if ( t > x ) { t = a[i]; p++;} 
    }
    return (p > m);
}

int main()
{    
    scanf("%d %d", &n, &m);
    int     i;
    for (high = low = i = 0; i < n; i++)
    {    
        scanf("%d", a + i);
        high += a[i];
        if (a[i] > low) low = a[i];
    }
    while (low < high)
    {
        mid = (low + high) / 2;
        if (ok(mid)) low = mid + 1; else high = mid;
    }
    printf("%d\n", high);
    return 0;
}
