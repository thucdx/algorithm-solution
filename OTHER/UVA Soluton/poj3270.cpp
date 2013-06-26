#include <algorithm>
using namespace std;

const int   MAX_N = 10000;

struct  node 
{
    int p, i;
} cow[MAX_N];

int     n;
bool operator < (const node &a, const node &b)
{
    return a. p < b. p;
}

int main()
{
    int     i, j, k, w, next, ans, t;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &cow[i].p);  
        cow[i]. i = i;
    }
    sort(cow, cow + n);
    t = cow[0].p;
    for (i = ans = 0; i < n; i++)
        if (cow[i]. i != -1)
        {
            j = cow[i]. i;
            w = cow[i]. p;
            k = 1;
            cow[i]. i = -1;
            while (j != i)
            {
                ans += cow[j]. p;
                next = cow[j]. i;
                cow[j]. i = -1;
                j = next;
                k++;
            }
            ans += min( w*(k-1), t*(k-1)+2*(t+w) );
        }
    printf("%d\n", ans);
    return 0;
}
