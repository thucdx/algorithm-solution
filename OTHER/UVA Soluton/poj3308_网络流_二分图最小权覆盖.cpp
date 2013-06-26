//网络流_二分图最小权覆盖
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 110;
const double INF = 1e10;
double c[MAXN][MAXN];
int n, m;
int N, src, dst;

void init(){
    int p;
    scanf("%d %d %d", &n, &m, &p);
    N = n + m + 2; src = 0; dst = n + m + 1;
    memset(c, 0, sizeof(c)); 
    for (int i = 1; i <= n; i++) 
    {
        double t; scanf("%lf", &t);
        c[src][i] = log(t);
    }
    for (int i = 1; i <= m; i++){
        double t; scanf("%lf", &t);
        c[i + n][dst] = log(t);
    }
    int u, v;
    while (p--){
        scanf("%d %d", &u, &v);
        c[u][v + n] = INF;
    }
}

double f[MAXN][MAXN], d[MAXN];
int pnt[MAXN], open[MAXN], mk[MAXN];

double maxflow(int s = src, int t = dst)
{
	int cur, tail, i, j, u, v;
    double flow=0;  memset(f,0,sizeof(f));
	do{ memset(mk,0,sizeof(mk)); memset(d,0,sizeof(d));
		open[0]=s; mk[s]=1; d[s]=INF;
		for(pnt[s]=cur=tail=0;cur<=tail&&!mk[t];cur++)
			for(u=open[cur],v=0;v<N;v++)if(!mk[v]&&f[u][v]<c[u][v]){
				mk[v]=1; open[++tail]=v; pnt[v]=u;
				if(d[u]<c[u][v]-f[u][v])d[v]=d[u];
					else d[v]=c[u][v]-f[u][v];
			}
		if(!mk[t])break; flow+=d[t];
		for(u=t;u!=s;){v=u;u=pnt[v];f[u][v]+=d[t]; f[v][u]=-f[u][v];}
	}while(d[t]>0); return flow;
}

void solve(){
    double ans = maxflow();
    ans = exp(ans);
    printf("%.4lf\n", ans);
}

int main(){
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    int cases; scanf("%d", &cases);
    while (cases--) init(), solve();
    return 0;
}
