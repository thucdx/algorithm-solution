#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 5010;
const __int64 MAXM = 10000000;
const __int64 INF = MAXM * MAXM;

struct Edge {
    int ev, rev;
    __int64 cap, flow;
    Edge(int p1 = 0, int p2 = 0, __int64 p3 = 0) : ev(p1), rev(p2), cap(p3), flow(0) {};
};

bool bad;
int n, m, src, dst; 
__int64 flow, total;
vector<Edge> g[MAXN];

int phase, last[MAXN], mk[MAXN];

void addEdge(int x, int y, __int64 cc) {
    g[x]. push_back(Edge(y, g[y]. size(), cc));
    g[y]. push_back(Edge(x, g[x]. size() - 1, 0));
}

__int64 augment(int cur = src, __int64 delta = INF)
{
    if (cur == dst) {
        flow += delta;
        return delta;
    }
    mk[cur] = phase;
    int i = last[cur];
    __int64 ret;
    Edge *e;
    do {
        e = &g[cur][i];
        if (mk[e->ev] != phase && e->flow < e->cap) {
            ret = augment(e->ev, min(e->cap - e->flow, delta));
            if (ret) {
                e->flow += ret;
                g[e->ev][e->rev]. flow -= ret;
                last[cur] = i;
                return ret;
            }
        }
        i++;
        if (i == g[cur]. size()) i = 0;
    } while (i != last[cur]);
    return 0;
}


__int64 maxFlow() {
    flow = 0, phase = 0;
    memset(mk, 0, sizeof(mk));
    memset(last, 0, sizeof(last));
    while (++phase, augment());
    return flow;
}

bool init(){
    if (scanf("%d %d", &n, &m) == EOF) return false;
    bad = true;
    total = 0; src = 0; dst = n + 1;
    for (int i = 0; i < MAXN; i++) g[i]. clear();
    __int64 t;
    for (int i = 1; i <= n; i++)
    {
        scanf("%I64d", &t);
        if (t > 0) { bad = false; addEdge(src, i, t); total += t; }
        else if (t < 0) addEdge(i, dst, -t);
    }
    int a, b;
    while (m--){
        scanf("%d %d", &a, &b);
        addEdge(a, b, INF);
    }
    return true;
}

int points;

void dfsvis(int cur) {
    mk[cur] = 1; 
    ++points;
    Edge *e;
    for (int i = 0; i < g[cur]. size(); i++){
        e = &g[cur][i];
        if (!mk[e->ev] && e->flow < e->cap) dfsvis(e->ev);
    }
}


void solve() {
    if (bad) {
        printf("0 0\n");  return;
    }
    __int64 ans = total - maxFlow();
    memset(mk, 0, sizeof(mk));
    points = 0;
    dfsvis(src);
    printf("%d %I64d\n", points - 1, ans);
}

int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    while (init()) solve();
    //fclose(stdout);
    return 0;
}
