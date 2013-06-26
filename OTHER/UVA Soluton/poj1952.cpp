#include <algorithm>
#include <set>
using namespace std;

int     n, i, j, ans, num;
int     price[5010];
int     f[5010], b[5010];
set<int>     temp, kt;


int main()
{
    while (scanf("%d", &n) == 1 && n)
    {
        for (i = 0; i < n; i++)
            scanf("%d", &price[i]);
        for (i = 0; i < n; i++) f[i] = 1;
        ans = num = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < i; j++)
                if (price[j] > price[i] && f[j] + 1 > f[i])
                    f[i] = f[j] + 1;
            if (f[i] > ans) ans = f[i];
        }
        for (i = 0; i < n; i++)
        {
            if (f[i] == 1) b[i] = 1;
            else
            {
                temp.clear();
                for (b[i] = 0, j = i - 1; j >= 0; j--)
                    if (price[j] > price[i] && f[j] + 1 == f[i] && temp.find(price[j]) == temp.end() ) 
                    {    
                        b[i] += b[j];
                        temp.insert(price[j]);
                    }
            }
        }
    
        kt.clear();
        for (i = n - 1; i >= 0; i--)
        {
            if (f[i] == ans && kt.find(price[i]) == kt.end() )
            {
                kt.insert(price[i]);
                num += b[i];
            }
        }
    
        printf("%d %d\n", ans, num);
    }
    return 0;
}
