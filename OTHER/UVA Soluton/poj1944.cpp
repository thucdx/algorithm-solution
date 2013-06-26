#include <algorithm>
#include <vector>

using namespace std;

const int   MAXN = 1010;

vector<int>     g[MAXN * 2];
int     n, m;
int     lmax[MAXN * 2];

int calc(int s)
{
    int     a = 0, b = 0;
    int     i, ret = 0;

/*    vector<int>::iterator   it;
    for (i = s; i <= n + s - 1; i++)
    {
        printf("i = %d lmax[i] = %d\n", i, lmax[i]);
        for (it = g[i]. begin(); it != g[i]. end(); it++)
            printf("%d %d\n", i, *it);
    }
*/
    for (i = s; i <= n + s - 1; i++)
        if (lmax[i] > i)
        {
            if (i >= b)   
            {
                a = i; b = lmax[i];
                ret += lmax[i] - i;
            }
            else
            if (i < b && lmax[i] > b)
            {
                ret += lmax[i] - b;
                a = b;  b = lmax[i];                
            } 
            else
            if (lmax[i] < b)
                a = lmax[i];
        }
    return ret;
}

int main()
{
    int     i;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) g[i]. clear();
    memset(lmax, 0, sizeof(lmax));
    int     a, b;
    while (m--)
    {
        scanf("%d%d", &a, &b);
        if (a > b) swap(a, b);
        g[a]. push_back(b);
        if (b > lmax[a]) lmax[a] = b;
    }
    int     ans = 10000;
    int     t;
    vector<int>::iterator   it;
    for (i = 1; i <= n; i++)
    {
        t = calc(i);
        //printf("best = %d\n", t);
        if (t < ans) ans = t;
        for (it = g[i]. begin(); it != g[i]. end(); it++)
        {
            t = *it;
            g[t]. push_back(i + n);
            if (i + n > lmax[t]) lmax[t] = i + n;
        } 
    }
    printf("%d\n", ans);
    return 0;
}
