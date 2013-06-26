#include <algorithm>
using namespace std;
const int MAXL = 1000000000;

struct Point
{
    int x, y;
};

int m, r, f, t;
int dis[10010];
Point link[1010];
int p[10010], d[10010], c[10010];

void init()
{
    scanf("%d", &m);
    scanf("%d", &r);
    for (int i = 1; i <= r; i++)
        scanf("%d %d", &link[i]. x, &link[i]. y);
    dis[0] = 0;
    for (int i = 1; i <= m; i++) dis[i] = MAXL;
    bool find = true;
    do
    {
        find = false;
        for (int i = 1; i <= r; i++)
        {
            if (dis[link[i]. x] + 5 < dis[link[i]. y])
            {
                find = true;
                dis[link[i]. y] = dis[link[i]. x] + 5;
            }
            if (dis[link[i]. y] + 5 < dis[link[i]. x])
            {
                find = true;
                dis[link[i]. x] = dis[link[i]. y] + 5;
            }
        }
    } while (find);
}

void solve()
{
    scanf("%d", &f);
    for (int i = 1; i <= f; i++)
        scanf("%d", &c[i]);
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
        scanf("%d %d", p + i, d + i);
    int pos = 1;
    int now = 0;
    for (int i = 1; i <= f; i++)
    {
        now += dis[c[i]];
        while (d[pos] < now) 
        {
            pos++;
            if (pos > t) 
            {
                printf("Being expected..");
                return;
            }
        }
        if (d[pos] == now && c[i] == p[pos])
        {
            printf("%d\n", now);
            return;
        }
        now += dis[c[i]];
    }
    for (int i = pos; i <= t; i++)
        if (p[i] == 0)
            printf("%d\n", d[i]); 
}


int main()
{
    init();
    solve();
    return 0;
}
