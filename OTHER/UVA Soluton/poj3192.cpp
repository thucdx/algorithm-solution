#include <algorithm>
using namespace std;

int n, ans;
char s[8][8];
bool mk[8];
int a[8];
int len[8], lp[8][8];

void readr()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s[i]);
        len[i] = strlen(s[i]);
    }
    memset(lp, 0, sizeof(lp));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
            {
                int k = 0;
                bool ok = false;
                for (; k < len[i] - len[j]; k++)
                    if (strncmp(s[i] + k, s[j], len[j]) == 0)
                    {
                        lp[i][j] = len[j]; 
                        ok = true;
                        break;
                    }
                if (ok) break;
                k = max(0, len[i] - len[j]);
                for (; k < len[i]; k++)
                    if (strncmp(s[i] + k, s[j], len[i] - k) == 0)
                    {
                        lp[i][j] = len[i] - k;
                        break;
                    }
            }
}

void check()
{
    int tmp = len[a[0]];
    for (int i = 1; i < n; i++)
        tmp += len[a[i]] - lp[a[i-1]][a[i]];
    ans <?= tmp;
}

void search(int x)
{
    if (x == n)
    {
        check();
        return;
    }
    for (int i = 0; i < n; i++)
        if (!mk[i])
        {
            mk[i] = true;
            a[x] = i;
            search(x + 1);
            mk[i] = false;
        }
}

void solve()
{
    ans = 10000;
    memset(mk, 0, sizeof(mk));
    search(0);
    printf("%d\n", ans);
}

int main()
{
    readr();
    solve();
    return 0;
}
