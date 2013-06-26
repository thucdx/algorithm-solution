#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int     v, w;
    node(int _v = 0, int _w = 0)
    {
        v = _v;  w = _w;
    }
};

bool operator < (const node &a, const node &b)
{
    return a. w > b. w; 
}

int     n, m;
vector<node>     g[5010];
int     d[5010][2];
int     num[5010];
priority_queue<node>    q;

int main()
{
    scanf("%d %d", &n, &m);
    int     a, b, c;
    while (m--)
    {
        scanf("%d %d %d", &a, &b, &c);
        g[a]. push_back(node(b, c));
        g[b]. push_back(node(a, c));
    }
    memset(d, 0, sizeof(d));
    memset(num, 0, sizeof(num));
    d[1][0] = 0;
    q. push(node(1,0));
    int     tv, td;
    size_t  k;
    while (!q. empty())
    {
        tv = q. top(). v;  td = q.top(). w;
        q. pop();
        if (num[tv] < 2)
        {
            d[tv][num[tv]] = td;
            num[tv]++;
            for (k = 0; k < g[tv]. size(); k++)
                if (num[g[tv][k]. v] < 2)
                    q. push( node(g[tv][k].v, td + g[tv][k]. w) );
        }
    }
    printf("%d\n", d[n][1]);
    return 0;
}
