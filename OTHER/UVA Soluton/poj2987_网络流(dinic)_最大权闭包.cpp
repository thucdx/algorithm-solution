//网络流 求最大权闭合图
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 5010;
const __int64 MAXM = 10000000;
const __int64 INF = MAXM * MAXM;

int N, src, dst;
int n, m;
__int64 total;
bool bad;
__int64 c[MAXM], f[MAXM];
int ev[MAXM], be[MAXM], next[MAXM], num;
int nbs[MAXN], g[MAXN], open[MAXN], d[MAXN], mk[MAXN];

void addEdge(int u, int v, __int64 cc){
    next[++num] = nbs[u]; nbs[u] = num; be[num] = num + 1;
    ev[num] = v; c[num] = cc; f[num] = 0;
    next[++num] = nbs[v]; nbs[v] = num; be[num] = num - 1;
    ev[num] = u; c[num] = 0; f[num] = 0;
}

bool build(int s = src, int t = dst){
    int cur, tail, i, j, u, v;
    memset(d, 0xff, sizeof(d)); memset(g, 0, sizeof(g));
    open[0] = s; d[s] = 0; g[s] = nbs[s];
    for (cur = tail = 0; cur <= tail && d[t] == -1; cur++)
        for (u = open[cur], j = nbs[u]; j; j = next[j]){
            v = ev[j];
            if (d[v] == -1 && f[j] < c[j]){
                open[++tail] = v; 
                d[v] = d[u] + 1; 
                g[v] = nbs[v]; 
            }
        }
    return (d[t] > 0);    
}

__int64 augment(int x = src, __int64 low = INF, int t = dst){
    if (x == t) return low;
    int ret = 0, v;
    for (int &i = g[x]; i; i = next[i]){
        v = ev[i]; 
        if ((c[i] > f[i]) && (d[v] == d[x] + 1)){
            ret = augment(v, low <? c[i] - f[i]);
            if(ret){
                f[i] += ret; f[be[i]] -= ret;
                return ret;
            }
        } 
    }
    return 0;
}

__int64 maxFlow(){
    __int64 flow, ret = 0;
    while (build()) while (flow = augment(src)) ret += flow;
    return ret;
}



bool init(){
    if (scanf("%d %d", &n, &m) == EOF) return false;
    bad = true;
    total = 0; src = 0; dst = n + 1;
    num = 0; memset(nbs, 0, sizeof(nbs));
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
    mk[cur] = 1; points++;
    for (int i = nbs[cur]; i; i = next[i])
        if (f[i] < c[i] && !mk[ev[i]]) dfsvis(ev[i]);
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
    while (init()) solve();
    return 0;
}
