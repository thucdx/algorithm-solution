#include <algorithm>
using namespace std;

const int MAXN = 500;
const int INF = 10000000;
const __int64 tmp = 0xfffff;
const __int64 INFt = tmp * tmp;
int n, m;
int src, dst, tot, tot2, N;
int a[MAXN], b[MAXN];
__int64 g[MAXN][MAXN];
int c[MAXN][MAXN];
__int64 tmax;

void init(){
    scanf("%d %d", &n, &m);
    src = 0, dst = n * 2 + 1; 
    memset(c, 0, sizeof(c));
    tot = tot2 = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        c[src][i] = a[i]; tot += a[i];
        c[n + i][dst] = b[i]; tot2 += b[i];
    }
    memset(g, 0, sizeof(g));
    int u, v; __int64 t;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %I64d", &u, &v, &t);
        if (v != u && (g[u][v] == 0 || t < g[u][v]))
            g[u][v] = g[v][u] = t;
    }
    if (tot > tot2) return;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++) if (g[i][k] > 0)
            for (int j = 1; j <= n; j++) if (j != i && g[k][j] > 0)
                if (g[i][k] + g[k][j] < g[i][j] || g[i][j] == 0)
                    g[i][j] = g[i][k] + g[k][j];
    tmax = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (g[i][j] > tmax) tmax = g[i][j];
}


int pnt[MAXN], open[MAXN], d[MAXN], mk[MAXN];
int f[MAXN][MAXN], height[MAXN], e[MAXN];
int list[MAXN], next[MAXN], len, head;

void push(int u, int v)
{
	int d = e[u]<?c[u][v]-f[u][v];
	f[u][v] += d;
	f[v][u] =- f[u][v];
	e[u] -= d; e[v] += d;
}

void discharge(int u)
{
	int v;
	while(e[u]>0) {
		for (v = 0; v < N && e[u] > 0; ++v)
			if (c[u][v]-f[u][v] > 0 && height[u] == height[v]+1) push(u,v);
		if (e[u] > 0) {
			height[u] = INF;
			for (v = 0; v < N; ++v) if (c[u][v]-f[u][v] > 0 && height[u] > height[v]+1)
				height[u] = height[v]+1;
		}
	}
}

int maxFlow_a(int s, int t)
{
	int i, j, u, v, old, last;
	memset(f, 0, sizeof(f)); memset(e, 0, sizeof(e)); len = 0;
	memset(height, 0, sizeof(height));
	for (i = 0; i < N; ++i) if (c[s][i])
		e[i] += c[s][i], e[s] -= c[s][i], f[s][i] = c[s][i], f[i][s] =- c[s][i];
	height[s] = n ;
	for (head = i = 0; i < N; ++i) if (i != s && i != t) 
    {
		list[len] = i, next[len] = len+1;
		len++;
	} 
    i = head; next[len-1] = -1; last = -1;
	while( i != -1 )
	{
		u = list[i];
		old = height[u];
		discharge(u);
		if (height[u] > old && head != i)
			next[last] = next[i], next[i] = head, head = i;
		last = i, i = next[i];
	}
	return e[t];
}


int maxFlow(int n, int s, int t) {
	int cur, tail, i, j, u, v, flow=0;  memset(f,0,sizeof(f));
	do{ memset(mk,0,sizeof(mk)); memset(d,0,sizeof(d));
		open[0]=s; mk[s]=1; d[s]=INF;
		for(pnt[s]=cur=tail=0;cur<=tail&&!mk[t];cur++)
			for(u=open[cur],v=0;v<=n;v++)if(!mk[v]&&f[u][v]<c[u][v]){
				mk[v]=1; open[++tail]=v; pnt[v]=u;
				if(d[u]<c[u][v]-f[u][v])d[v]=d[u];
					else d[v]=c[u][v]-f[u][v];
			}
		if(!mk[t])break; flow+=d[t];
		for(u=t;u!=s;){v=u;u=pnt[v];f[u][v]+=d[t]; f[v][u]=-f[u][v];}
	}while(d[t]>0); return flow;
}
bool check(__int64 x)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j + n] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ((i == j)||(g[i][j] != 0 && g[i][j] <= x)) c[i][j + n] = INF; 
    
    int flow;
    if (m < n) flow = maxFlow(2 * n + 1, src, dst);    
    else flow = maxFlow_a(0, N-1);
    return (flow == tot);
}

void solve() {
    if (tot > tot2) {
        puts("-1");  return ;
    }
    __int64 low, high, mid;
    low = 0; high = tmax + 1;
    N = n * 2 + 2;
    while (low + 1 < high) {
        mid = (low + high) / 2;
        if (check(mid)) high = mid; else low = mid;
    }
    if (high == tmax + 1) puts("-1");
    else printf("%I64d\n", high);
}

int main()
{
    //freopen("ombro.2.in", "r", stdin);
    //freopen("ombro.out", "w", stdout);
    init();
    solve();
    //fclose(stdout);
    return 0;
}

