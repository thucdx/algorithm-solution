#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct Node
{
    int k, pos, d;
    Node(int _k = 0, int _pos = 0, int _d = 0) : k(_k), pos(_pos), d(_d) {}
};

int main()
{
    int p[5010];
    int n, m;
    int i, j;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    vector<vector<int> > g(n + 1);
    while (m--)
    {
        scanf("%d %d", &i, &j);
        g[i]. push_back(j);
        g[j]. push_back(i);
    }
    set<int> v[5010];
    deque<Node> q;
    q. push_back(Node(1, p[1], 0));
    v[1]. insert(p[1]);
    while (!q. empty())
    {
        Node t = q. front();
        q. pop_front();
        i = t. k; 
        int x = t. pos;
        for (j = 0; j < g[i]. size(); j++)
        {
            int y = g[i][j];
            int d = p[y] - p[i];
            if (d > 180) d -= 360;
            if (d < -180) d += 360;
            if (v[y]. find(x + d) == v[y]. end())
	        {
		        if (y == 1)
		        { 
                    printf("%d\n", t. d + 1); 
                    return 0; 
                }
		        q.push_back(Node(y, x + d, t. d + 1));
		        v[y]. insert(x + d);
	        }
        }
    }
    printf("-1\n");
    return 0;
}
