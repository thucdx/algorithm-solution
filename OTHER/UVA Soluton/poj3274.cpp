#include <algorithm>
using namespace std;

const int   Hash_Size = 997001;
const int   Max_N = 100010;
int     h[1000000];
int     N, k, ans;
int     d[Max_N][30];

int hash(int v[])
{
    int     i, p, can, j;
    for (p = 0, i = 0; i < k; i++)
        p=((p<<2)+(v[i]>>4))^(v[i]<<10);
    p %= Hash_Size;
    if (p < 0) p +=Hash_Size;
    for (can = 0; !can && h[p] != -1; p++)
        for (j = h[p], can = 1, i = 0; can && i < k; i++)
            can = (v[i] == d[j][i]);
    if (can) p--;
    return p;
}

int main()
{
    int     i, j, a, s, p, l;
    memset(h, -1, sizeof(h));
    scanf("%d %d", &N, &k);
    for (k--, i = 0; i < k; i++) d[0][i] = 0;
    h[hash(d[0])] = 0;
    for (ans = 0, i = 1, l = 0; i <= N; i++, l++)
    {
        scanf("%d", &a);
        for (s = a % 2, a = (a>>1), j = 0; j < k; j++, a = (a>>1) )
            d[i][j] = d[l][j] + (a % 2) - s;
        p = hash(d[i]);
        if (h[p] == -1) h[p] = i;
        if (i - h[p] > ans) ans = i - h[p];
    }
    printf("%d\n", ans);
    return 0;
}
