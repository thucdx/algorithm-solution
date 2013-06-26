#include <algorithm>
#include <vector>
using namespace std;

vector<int>     a[5010], b[5010];
int     n, m, ans;
int     num1[5010], num2[5010];

int main()
{
    int     i, j;
    vector<int>::iterator   it;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        scanf("%d%d", &i, &j);
        a[j].push_back(i);
        b[i].push_back(j);
    }
    memset(num1, 0, sizeof(num1));
    for (i = 1; i <= n; i++)
    {
        for (it = a[i]. begin(); it != a[i]. end(); it++)
            num1[i] += num1[*(it)];
        if (!num1[i]) num1[i] = 1;
    }
    memset(num2, 0, sizeof(num2));
    for (i = n; i > 0; i--)
    {
        for (it = b[i]. begin(); it != b[i]. end(); it++)
            num2[i] += num2[(*it)];
        if (!num2[i]) num2[i] = 1;
    }
    ans = 0;
    for (i = 1; i <= n; i++)
        for (it = b[i].begin(); it != b[i]. end(); it++)
        {
            j = *it;
            if (num1[i] * num2[j] > ans) ans = num1[i] * num2[j];
        } 
    printf("%d\n", ans);
    return 0;
}
