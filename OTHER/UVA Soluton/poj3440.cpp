#include <algorithm>
#include <cmath>
using namespace std;
const double PI = 3.1415926535897932;

int n, m, l, d;

int solve()
{
    int cases;
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++)
    {
        if (i > 1) putchar('\n');
        printf("Case %d:\n", i);
        scanf("%d %d %d %d", &n, &m, &l, &d);
        double r = 1.0 * d / 2;
        double area = (1.0 * l * l * m * n);
        double a = 1.0 * (n - 2) * (m - 2) * (l - d) * ( l - d);
        a += 4 * (l - r) * (l - r);
        a += 2 * (n - 2) * (l - r) * (l - d);
        a += 2 * (m - 2) * (l - r) * (l - d);
        a /= area;
        printf("Probability of covering 1 tile  = %.4lf", 100 * a);
        putchar(37);  putchar('\n');
        
        double b = 1.0 * (n - 2) * (m - 2) * 4 * r * (l - d);
        b += 4 * 2 * r * (l - r);
        b += 2 * (n - 2) * ( 2 * r * (l - r) + r * (l - d) );
        b += 2 * (m - 2) * ( 2 * r * (l - r) + r * (l - d) );
        b /= area;
        printf("Probability of covering 2 tiles = %.4lf", 100 * b);
        putchar(37);  putchar('\n');
        
        double d = 1.0 * (n - 1) * (m - 1) * PI * r * r;
        d /= area;
        double c = fabs(1 - a - b - d);
        printf("Probability of covering 3 tiles = %.4lf", 100 * c);
        putchar(37);  putchar('\n');
        
        printf("Probability of covering 4 tiles = %.4lf", 100 * d);
        putchar(37);  putchar('\n');
    }
    return 0;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++)
    {
        if (i > 1) putchar('\n');
        solve();
    }
    return 0;
}
