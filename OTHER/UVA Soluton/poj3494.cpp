#include <algorithm>
using namespace std;

int     n, m;
int     x[2020], y[2020];     

int main()
{
    int i, j, t, k, max;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        memset(x, 0, sizeof(x));
        max = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 1; j <= m; j++)
            {    
                scanf("%d", &t);
                if (t == 1) x[j]++; else x[j] = 0;
            }
            for (j = 1; j <= m; j++)
            {
                y[j] = j;
                while ( x[ y[j]-1 ] >= x[j] && y[j] > 1 ) y[j] = y[ y[j]-1 ];
            }
            for (j = m; j > 0; j--)
            {
                k = j;
                while ( x[ k+1 ] >= x[j] && k < m )
                    k = y[ k+1 ];
                if (  (k - y[j] + 1) * x[j] > max ) 
                    max = (k - y[j] + 1) * x[j];
                y[j] = k;
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
