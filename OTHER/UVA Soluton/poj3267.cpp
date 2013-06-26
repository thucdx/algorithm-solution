#include <algorithm>
#include <cstring>
using namespace std;

int     n, l;
char    s[310];
char    words[610][100];
int     f[310];

void calc(int k, int p)
{
    int t = k, i;
    int w = 0;
    for (i = 0; i < strlen(words[p]); i++)
    {
        while (s[t] != words[p][i])
        {
            t++;  w++;
            if (t >= l) return;
        }
        t++;
    }
    if (f[k] + w < f[t]) f[t] = f[k] + w;
}

int main()
{
    int     i, j;
    scanf("%d %d", &n, &l);
    scanf("%s", s);
    for (i = 0; i < n; i++)
        scanf("%s", words[i]);
    for (i = 0; i <= l; i++) f[i] = i;
    for (i = 0; i <= l; i++)
    {
        if (i > 1 && f[i-1] + 1 < f[i]) f[i] = f[i-1] + 1;
        for (j = 0; j < n; j++)
            if (s[i] == words[j][0] && i + strlen(words[j]) <= l)
                calc(i, j);
    }
    printf("%d\n", f[l]);
    return 0;
}
