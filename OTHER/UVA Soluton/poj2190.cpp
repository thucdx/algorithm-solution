#include <stdio.h>

int main()
{
    int i, t = 0, x = 0;
    char a;
    bool flag;

    for (i = 10; i > 1; i--)
    {
        a = getchar();
        if (a == '?') x = i;
        else t = t + (a - '0') * i;
    }
    a = getchar();
    if (a == 'X') t += 10;
    else if (a >= '0' && a <= '9') t += a - '0';
    else if (a == '?') x = 1;
    
    for (i = 0, flag = false; i <= 9; i++)
        if ( (t + i * x) % 11 == 0)
        {
            flag = true;
            printf("%d\n", i);
            break;
        }
    if (x == 1 && !flag)
        if ( (t + 10) % 11 == 0)
        {
            flag = true;
            printf("X\n");        
        }
         
    if (!flag) printf("-1\n");
    return 0;
}
