#include <algorithm>
using namespace std;
int main()
{
    int     n, num[10000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    sort(num, num + n);
    printf("%d\n", num[n / 2]);
    return 0;
}
