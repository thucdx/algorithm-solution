#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 50010;

int n, k, m;
int nbs[MAXN], next[MAXN*2], ev[MAXN*2], ew[MAXN*2];
bool mk[MAXN];

void init(){	
	scanf("%d %d", &n, &k);
	int u, v, w;
	memset(nbs, 0, sizeof(nbs));
	int num = 0;
	for (int i = 1; i <= n - 1; i++){
		scanf("%d %d %d", &u, &v, &w);
		next[++num] = nbs[u]; nbs[u] = num;
		ev[num] = v; ew[num] = w;
		next[++num] = nbs[v]; nbs[v] = num;
		ev[num] = u; ew[num] = w;
	}
	scanf("%d", &m);
	memset(mk, 0, sizeof(mk));
	for (int i = 0; i < m; i++){
		scanf("%d", &u);
		mk[u] = true;	
	}
}

struct Node{
	int left, right;
	bool mk;
	int l, f;
	Node(){
		left = right = l = f = mk = 0;
	}	
};

Node p[MAXN];

void build(int x, int y){
	for (int i = nbs[x]; i; i = next[i]){
		int t = ev[i];
		if (t != y){
			if (mk[t]) p[t].mk = true;
			p[t].l = ew[i];
			p[t].right = p[x].left;
			p[x].left = t;
			build(t, x);
			if (p[t].mk) p[x].mk = true;
		}	
	}
}	

int ans;
void calc(int x, int d){
	if (!p[x].mk) return;
	if (d > ans) ans = d;
	int t = p[x].left;
	while (t != 0){
		calc(t, d + p[t].l);
		if (p[t].mk) p[x].f += p[t].f + p[t].l;
		t = p[t].right;	
	}
}

void solve(){
	build(k, 0);
	ans = 0;
	calc(k, 0);
	printf("%d\n", p[k].f*2 - ans);
}

int main(){
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	init();
	solve();
	return 0;
}	
