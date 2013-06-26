#include <stdio.h>
#include <math.h>
int main()
{
    int r, m, y;
    double t;
    while (scanf("%d %d %d", &r, &m, &y) != EOF)
    {
        t = 1 + (double)r/100; 
        printf("%d\n", int( m * pow(t, y) ) ); 
    }
    return 0;
}
