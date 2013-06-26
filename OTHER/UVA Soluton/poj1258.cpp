#include <stdio.h>

int main()
{
    int n, ans;
    int i, j, min;
    int g[100][100];
    int d[100];
    int mk[100];
    
    while (scanf("%d", &n)!= EOF && n)
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &g[i][j]);
        ans = 0;
        for (i = 0; i < n; i++) d[i] = g[0][i], mk[i] = 0;
        while (1)
        {
            min = 0x3fffffff; j = -1;
            for (i = 0; i < n; i++)
                if (!mk[i] && d[i] < min)
                {
                    min = d[i];
                    j = i;
                }
            if (j == -1) break;
            mk[j] = 1;
            ans += min;
            for (i = 0; i < n; i++)
                if (!mk[i] && g[j][i] < d[i])
                    d[i] = g[j][i];
        }
        printf("%d\n", ans); 
    }
    return 0;
}
