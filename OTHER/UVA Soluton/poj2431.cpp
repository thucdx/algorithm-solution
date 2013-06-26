#include <algorithm>
using namespace std;

const int MAXN = 10000;
const int MAXD = 1000000;
const int MAXF = 100;

struct node
{
    int d, f;
};

node s[MAXN];
int n, fd, ff;
int cnt[MAXF+1];

void init()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &s[i]. d, &s[i]. f); 
    scanf("%d %d", &fd, &ff);
}

bool cmp(const node &a, const node &b)
{
    return a. d < b. d;
}

void solve()
{
    int ans = 0;
    sort(s, s + n, cmp);
    memset(cnt, 0, sizeof(cnt));
    while (1)
    {
        fd -= ff;
        ff = 0;
        while (n >= 1 && s[n - 1]. d >= fd)
        {
            cnt[s[n-1].f]++;
            n--;
        }
        if (fd <= 0) break;
        int i = MAXF;
        while (cnt[i] == 0)
        {
            i--;
            if (i == 0)
            {
                printf("-1\n"); 
                return;
            }
        }
        ff += i;
        cnt[i]--;
        ans++;
    }
    printf("%d\n", ans);
}

int main()
{
    init();
    solve();
    return 0;
}
