#include <queue>
#include <algorithm>
using namespace std;

int n;
int h[110][110];
int tmax, tmin;
const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };
bool mk[110][110];

bool check(int a, int b)
{
    memset(mk, 0, sizeof(mk));
    mk[1][1] = true;
    deque<pair<int, int> > q;
    if (h[1][1] < a || h[1][1] > b) return false;
    q. push_back(make_pair(1, 1));
    while (q. size())
    {
        int x = q. front(). first, y = q. front(). second;
        q. pop_front();
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx <= 0 || ty <= 0 || tx >= n + 1 || ty >= n + 1) continue;
            if (mk[tx][ty]) continue;
            if (h[tx][ty] < a || h[tx][ty] > b) continue;
            if (tx == n && ty == n) return true;
            q. push_back(make_pair(tx, ty));
            mk[tx][ty] = true;
        }
    }
    return false;
}

bool ok(int det)
{
    for (int i = tmin; i <= tmax - det; i++)
        if (check(i, det + i)) return true;
    return false;
}

void solve()
{
    scanf("%d", &n);
    tmin = 201, tmax = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &h[i][j]);
            tmin <?= h[i][j];
            tmax >?= h[i][j];
        }
    int low = -1, high = tmax - tmin;
    while (low + 1 < high)
    {
        int mid = (low + high) / 2;
        if (ok(mid)) high = mid; else low = mid;
    }
    printf("%d\n", high);
}

int main()
{
    int cases;
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++)
    {
        printf("Scenario #%d:\n", i);
        solve();
        printf("\n");
    }
    return 0;
}
