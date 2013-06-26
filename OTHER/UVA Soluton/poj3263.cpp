#include <algorithm>
using namespace std;

struct  node
{
    int     a, b;
    node(int x = 0, int y = 0)
    {
        if (x < y) {a = x; b = y;}
        else {a = y; b = x;}
    }
};

node    seg[10010];
int     num[10010];

bool operator < (const node &x, const node &y)
{
    return x. a < y. a || x. a == y. a && x. b < y. b; 
}

bool operator == (const node &x, const node &y)
{
    return x. a == y. a && x . b == y. b;
}

int     n, p, h, m;

int main()
{
    scanf("%d %d %d %d", &n, &p, &h, &m);
    int     i, a, b;
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        seg[i] = node(a, b);
    }
    sort(seg, seg + m);
    int     k;
    k = std::unique(seg, seg + m) - seg;
    memset(num, 0, sizeof(num));
    for (i = 0; i < k; i++)
    {
        a = seg[i]. a;
        b = seg[i]. b;
        --num[a + 1];
        ++num[b];
    }
    a = 0;
    for (i = 1; i <= n; i++)
    {
        a += num[i];
        printf("%d\n", h + a);
    }
    return 0;
}
