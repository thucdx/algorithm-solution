// [TIMXAD] ~ [LUBENICA] @ [Sep 2, 2013]
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cassert>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define DOW(i, A, a) for (int i = (A), _a = (a); i >= _a; --i)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

#define dbg(x) cout << #x << " = " << x << endl
#define ok() cout << "@OK!" << endl
#define pb push_back
#define mp make_pair
#define sz(a) (int) a.size()
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAX = (int) 1e5;

struct Node {
	int ver, maxDis, minDis;

	Node() { ver = maxDis = minDis = -1; }

	Node(int _v, int _min, int _max) {
		ver = _v, maxDis = _max, minDis = _min;
	}

	void set(int _v, int _min, int _max) {
		ver = _v, maxDis = _max, minDis = _min;
	}
};

int n, l[MAX + 5];
ii t[MAX + 5];
Node p[MAX + 5][20];
vector<ii> child[MAX + 5];

void dfs(int v, int level) {
	l[v] = level;
	FIT(it, child[v]) {
		if (!l[it->fi]) {
			t[it->fi] = ii(v, it->se);
			dfs(it->fi, level + 1);
		}
	}
}

void init() {
	int log = log2(n);
	FOR(i, 1, n) p[i][0].set(t[i].fi, t[i].se, t[i].se);

	for (int j = 1; j <= log; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (p[i][j - 1].ver != -1) {
				Node parent = p[p[i][j - 1].ver][j - 1];
				int v = parent.ver;
				if (v != -1) {
					int _max = max(p[i][j - 1].maxDis, parent.maxDis);
					int _min = min(p[i][j - 1].minDis, parent.minDis);
					p[i][j].set(v, _min, _max);
				}
			}
		}
	}
}

inline Node LCA(int x, int y) {
	if (l[x] < l[y]) swap(x, y);
	int minDist = (int) 1e6 + 1, maxDist = 0, log = log2(l[x]);
	for (int i = log; i >= 0; --i) {
		if (l[x] - (1 << i) >= l[y]) {
			minDist = min(minDist, p[x][i].minDis);
			maxDist = max(maxDist, p[x][i].maxDis);
			x = p[x][i].ver;
		}
	}

	if (x == y) return Node(x, minDist, maxDist);

	for (int i = log; i >= 0; --i) {
		if (p[x][i].ver != -1 && p[x][i].ver != p[y][i].ver) {
			minDist = min(minDist, min(p[x][i].minDis, p[y][i].minDis));
			maxDist = max(maxDist, max(p[x][i].maxDis, p[y][i].maxDis));
			x = p[x][i].ver;
			y = p[y][i].ver;
		}
	}

	minDist = min(minDist, min(t[x].se, t[y].se));
	maxDist = max(maxDist, max(t[x].se, t[y].se));

	return Node(t[x].fi, minDist, maxDist);
}

//Fast input
const int bfsz = 1 << 16; char bf[bfsz + 5]; int rsz = 0;int ptr = 0;
char gc() { if (rsz <= 0) { ptr = 0; rsz = fread(bf, 1, bfsz, stdin); if (rsz <= 0) return EOF; } --rsz; return bf[ptr++]; }
void ga(char &c) { c = EOF; while (!isalpha(c)) c = gc(); }
int gs(char s[]) { int l = 0; char c = gc(); while (isspace(c)) c = gc(); while (c != EOF && !isspace(c)) { s[l++] = c; c = gc(); } s[l] = '\0'; return l; }
template<class T> bool gi(T &v) {
v = 0; char c = gc(); while (c != EOF && c != '-' && !isdigit(c)) c = gc(); if (c == EOF) return false; bool neg = c == '-'; if (neg) c = gc();
while (isdigit(c)) { v = v * 10 + c - '0'; c = gc(); } if (neg) v = -v; return true;
}
//End of fast input

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	gi(n);
	int u, v, d, q;
	REP(i, n - 1) {
		gi(u), gi(v), gi(d);
		child[u].pb(ii(v, d));
		child[v].pb(ii(u, d));
	}

	memset(t, -1, sizeof(t));
	dfs(1, 1);
	init();

	gi(q);
	while (q--) {
		gi(u), gi(v);
		Node rs = LCA(u, v);
		printf("%d %d\n", rs.minDis, rs.maxDis);
	}
}

