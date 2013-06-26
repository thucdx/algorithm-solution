#include <stdio.h>
#define MASK (0xFFFFF << 1)

int count (int bowl, int n, int k) 
{
    if ( (bowl & MASK) == 0) return k;
    if (n == 1) return 99999;
    if (bowl & (1 << n))   
        return count(bowl ^ (7 << (n-2)), n - 1, k + 1);
    return count(bowl, n-1, k);
}

int main() 
{
    int i, t, st, a, b;

    for (i = 0, st = 0; i < 20; i++) 
    {
        scanf("%d", &t);
        st = (st << 1) | t;
    }
    st = st << 1;
    a = count(st^(3<<19), 20, 1);
    b = count(st, 20, 0);
    if (b < a) a = b;
    printf("%d\n", a);
    return 0;
}
