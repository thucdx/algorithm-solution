// TIMXAD - [ROTATION] @ [Jul 3, 2013]
#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define DOW(i, A, a) for (int i = (A), _a = (a); i >= _a; --i)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl
#define OK() cout << "@" << endl
#define PB push_back
#define MP make_pair

typedef long long ll;
typedef pair<int, int> II;
typedef vector<int> VI;

int n;
bool vs[1005], found = false, dir;
vector<pair<int, bool> > adj[1005];

void dfs(int ver, bool direction) {
	if (found) return;
	if (ver == n) found = true, dir = direction;

	REP(j, adj[ver].size()) {
		int cur = adj[ver][j].first;
		if (!vs[cur]) {
			vs[cur] = true;
			dfs(cur, direction ^ adj[ver][j].second);
			vs[cur] = false;
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
//	freopen("./IO/output", "w", stdout);
#endif
	scanf("%d", &n);
	int u, v, type;
	REP(i, n - 1) {
		scanf("%d %d %d", &u, &v, &type);
		adj[u].push_back(make_pair(v, type));
		adj[v].push_back(make_pair(u, type));
	}
	found = false;
	dfs(1, 0);
	cout << dir << endl;
}
