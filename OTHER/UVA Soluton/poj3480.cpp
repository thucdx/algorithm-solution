#include <stdio.h>

int main()
{
    int     cases, n, i, t;
    int     a[100];
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {    
            scanf("%d", &a[i]);
            a[i] = (a[i] > 1);
        }
        t = 0;
        for (i = 0; i < n; i++)
            t ^= a[i];
        printf("%d\n", t);
        if (t == 1) printf("John\n"); else printf("Brother\n");
    }
    return 0;
}
