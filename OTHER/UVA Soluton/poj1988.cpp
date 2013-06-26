#include <algorithm>
using namespace std;
const int   MAXN = 30010;

int     n;
int     pnt[MAXN], num[MAXN], nt[MAXN];
char    op[2];

int find(int x)
{
    int temp = pnt[x];
    if (x != pnt[x]) 
    {
        pnt[x] = find(pnt[x]);
        nt[x] += nt[temp];
    }
    return pnt[x];
}

int main()
{
    int     i, a, b;
    scanf("%d", &n);
    for (i = 1; i < MAXN; i++) pnt[i] = i, num[i] = 1, nt[i] = 0;
    while (n--)
    {
        scanf("%1s", &op);
        if (op[0] == 'M')
        {
            scanf("%d %d", &a, &b);
            a = find(a);
            b = find(b);
            if (a != b)
            {
                pnt[b] = a;
                nt[b] = num[a];
                num[a] += num[b];                
            }
        }
        else
        {
            scanf("%d", &a);
            b = find(a);
            printf("%d\n", num[b] - nt[a] - 1);
        }        
    }    
    return 0;
}
