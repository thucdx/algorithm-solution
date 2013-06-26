#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 200000; 

deque<int>  q;
int     dist[maxn];
int     n, k;

int bfs()
{
    int x, t;
    while (!q.empty())
    {
        x = q.front();
        t = dist[x];
        if (x + 1 <= maxn)  
            if (dist[x + 1] == -1)
            {
                dist[x + 1] = t + 1;
                if (x + 1 == k) return dist[x + 1];
                q.push_back(x + 1);
            }        
        if (x - 1 >= 0)
            if (dist[x - 1] == -1)
            {
                dist[x - 1] = t + 1;
                if (x - 1 == k) return dist[x - 1];
                q.push_back(x - 1);
            }
        if (2 * x <= maxn && x != 0)
            if (dist[x * 2] == -1)
            {
                dist[x * 2] = t + 1;
                if (x * 2 == k) return dist[x * 2];
                q. push_back(x * 2);
            }
        q. pop_front();
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    if (n == k) printf("0\n");
    else
    {
        q.clear();
        memset(dist, -1, sizeof(dist));
        q.push_back(n);
        dist[n] = 0;
        printf("%d\n", bfs());
    }
    return 0;
}
