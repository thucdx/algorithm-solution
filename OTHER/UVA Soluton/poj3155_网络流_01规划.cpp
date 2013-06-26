//最大密度子图 0-1分数规划+网络流

#include <algorithm>
using namespace std;

const int MAXN = 110;
const int MAXM = 1010;

struct Edge{
    int u, v;
    Edge(int u = 0, int v = 0):u(u), v(v){};
};

int n, m;
int deg[MAXN];
Edge e[MAXM];
const double INF = 1e20;
int N, src, dst;
double c[MAXN][MAXN], f[MAXN][MAXN], d[MAXN]; 
int pnt[MAXN], open[MAXN], mk[MAXN];

void init(){
    scanf("%d %d", &n, &m);	
	src = 0; dst = n + 1; N = n + 2;
	int u, v;
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i <= m; i++){
        scanf("%d %d", &u, &v);
        e[i] = Edge(u, v);
        deg[u]++; deg[v]++;
    }
}

double maxFlow(int n = N, int s = src, int t = dst)
{
	int cur, tail, u, v; double flow=0;  memset(f,0,sizeof(f));
	do{ memset(mk,0,sizeof(mk)); memset(d,0,sizeof(d));
		open[0]=s; mk[s]=1; d[s]=INF;
		for(pnt[s]=cur=tail=0;cur<=tail&&!mk[t];cur++)
			for(u=open[cur],v=0;v<n;v++)if(!mk[v]&&f[u][v]<c[u][v]){
				mk[v]=1; open[++tail]=v; pnt[v]=u;
				if(d[u]<c[u][v]-f[u][v])d[v]=d[u];
					else d[v]=c[u][v]-f[u][v];
			}
		if(!mk[t])break; flow+=d[t];
		for(u=t;u!=s;){v=u;u=pnt[v];f[u][v]+=d[t]; f[v][u]=-f[u][v];}
	}while(d[t]>0); return flow;
}

int ans;
void dfsvis(int u){
	mk[u]=1; ans++;
	for(int v = 0; v < N; ++v) if( dcmp(f[u][v]-c[u][v]) < 0 && !mk[v] )
		dfsvis(v);
}


double h(double g){
	memset(c, 0, sizeof(c));
    for (int i = 1; i <= m; i++) {c[e[i]. u][e[i]. v] = 1.0; c[e[i]. v][e[i]. u] = 1.0;}
    for (int i = 1; i <= n; i++) {c[src][i] = m; c[i][dst] = m + 2*g - deg[i];}
    double f = maxFlow();
    return 1.0*m*n - f;
}

void solve(){
	if (m == 0){ puts("1\n1"); return;};
    double low = 0.0, high = m, mid;
    while (low + 1.0/n/n< high){
        mid = (low + high) / 2;
        if (h(mid) <= 0) high = mid; else low = mid;
    }
    h(low);
    ans = 0; memset(mk, 0, sizeof(mk));
    dfsvis(src);
    printf("%d\n", ans - 1);        
    for (int i = 1; i <= n; i++) 
        if (mk[i]) printf("%d\n", i);
}


int main(){
    init();
    solve();
    return 0;
}
