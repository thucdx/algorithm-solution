#include <algorithm>
#include <string.h>
using namespace std;

#define MAXN 1500
#define MAXM 4 * MAXN * MAXN
#define INF 0x3fffffff

int total;
int N, src, dst;
int c[MAXM], f[MAXM], ev[MAXM], be[MAXM], next[MAXM], num;
int nbs[MAXN], g[MAXN], open[MAXN], d[MAXN], mk[MAXN];

void addEdge(int u, int v, int cc){
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

int augment(int x = src, int low = INF, int t = dst){
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

int maxFlow(){
    int flow, ret = 0;
    while (build()) while (flow = augment(src)) ret += flow;
    return ret;
}

void solve(){
	int n, m, dj;
	char s[100];
	int jump[100][100];
	scanf("%d%d", &n, &dj);
	memset(nbs, 0, sizeof(nbs));  num = 0;
	getchar();
	int u, v, w;
	for (int i = 0; i < n; i++){
		gets(s);  
		if (i == 0) {
			m = strlen(s); 
			src = n * m * 2; dst = n * m * 2 + 1 ;
			N = n * m * 2 + 2;
		}
		for (int j = 0; j < m; j++){
			u = i * m + j;  v = i * m + j + n * m;
			w = s[j] - '0';
			jump[i][j] = w;
			if (w != 0) addEdge(u, v, w);
		}
	}
	total = 0;
	for (int i = 0; i < n; i++){
		gets(s);
		for (int j = 0; j < m; j++)
			if (s[j] == 'L'){
				total++;
				u = src;  v = i * m + j; w = 1;
				addEdge(u, v, w);
			}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (jump[i][j]) {
			u = i * m + j + n * m;
			for (int ii = -1; ii <= n; ii++)
				for (int jj = -1; jj <= m; jj++){
					if ((ii == -1 || ii == n || jj == -1 || jj == m) && (abs(ii - i) + abs(jj - j) <= dj)) {
						v = dst; w = INF;
						addEdge(u, v, w);						
					}
					else
					if (jump[ii][jj] && abs(ii - i) + abs(jj - j) <= dj && abs(ii - i) + abs(jj - j) >= 1) {
						v = ii * m + jj; w = INF;
						addEdge(u, v, w);
					}	
				}
		}
}


int main(){
	int cases;  scanf("%d", &cases);
	for (int tc = 1; tc <= cases; tc++){
		solve();
		int ans;
		ans = total - maxFlow();
		if (ans > 1) printf("Case #%d: %d lizards were left behind.\n", tc, ans);
		else
		if (ans == 1) printf("Case #%d: 1 lizard was left behind.\n", tc);
		else printf("Case #%d: no lizard was left behind.\n", tc);
	}
    return 0;
}
