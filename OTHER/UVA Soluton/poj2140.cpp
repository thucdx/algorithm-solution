#include <stdio.h>

int n;

int main()
{
    int cnt, i;
    while (scanf("%d", &n) != EOF)
    {        
        cnt = 0;
        for (i = 1; (i+1)*i/2 <= n; i++)
            if ( (n-(i-1)*i/2)%i == 0 ) 
                cnt++;
        printf("%d", cnt);    
    }
    return 0;    
}
