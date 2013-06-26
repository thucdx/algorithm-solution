#include <algorithm>
using namespace std;

int main()
{
    int     n, s;
    int     g[20][20];
    int     i, j;
    
    scanf("%d %d", &n, &s);    
    
    for (j = 0; j < n; j++)
        for (i = 0; i <= j; i++)
        {
            g[i][j] = s++;
            if (s == 10) s = 1;
        }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++) printf("  ");
        for (j = i; j < n; j++) printf("%d ", g[i][j]);
        printf("\n");        
    }
    
    system("pause");
    
    return 0;
}
