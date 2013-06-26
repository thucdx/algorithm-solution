#include <algorithm>
using namespace std;

int stk[50010];

int main()
{
    int n, w, a, b;
    int top = 0, ans = 0;
    scanf("%d %d", &n, &w);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        while (top  > 0 && b < stk[top - 1]) top--;
        if (top == 0 && b != 0 || b > stk[top - 1] && b != 0)
        {
            stk[top++] = b; 
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
