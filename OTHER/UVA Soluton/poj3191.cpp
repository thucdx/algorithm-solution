#include <algorithm>
#include <math.h>
using namespace std;

int     n;
int     a[10010];

int main()
{
    scanf("%d", &n);
    int     k = 0;
    do
    {
        a[++k] = abs(n % 2);
        n =  - int( floor( (n - a[k]) / 2));        
    }while (n != 0);
    while (k)
        printf("%d", a[k--]);
    printf("\n");
    return 0;
}
