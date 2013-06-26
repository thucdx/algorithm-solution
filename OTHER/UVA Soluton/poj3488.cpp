#include <algorithm>
using namespace std;

char s[1000][1000];
char ts[1000];
int l, i, j, n, t;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
            scanf("%s", s[i]);
        l = strlen(s[0]);
        t = (l * n);
        for (j = 0; j < l; j++)
            for (i = 0; i < n; i++)
                ts[--t] = s[i][j];  
        l = l * n;      
        for (i = 0; i < l; i++)
        {
            if (ts[i] == '_') ts[i] = ' ';
            else 
            if (ts[i] == '\\') ts[i] ='\n';
        }
        while (ts[l-1] == '_') l--;
        for (i = 0; i < l; i++)
            printf("%c", ts[i]);
        printf("\n");
        printf("\n"); 
    }    
    return 0;
}
