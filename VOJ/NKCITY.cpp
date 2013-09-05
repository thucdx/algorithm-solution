// [TIMXAD] ~ [NKCITY] @ [Aug 6, 2013]
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
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

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
vector<ii> adj[1005];
int t[10005], n;
bool vs[1005];

void dfs(int ver, int time) {
	vs[ver] = true;
	FIT(it, adj[ver]) {
		int nxt = it->first, d = it->second;
		if (!vs[nxt] && d <= time) {
			dfs(nxt, time);
		}
	}
}

inline bool canGo(int time) {
	memset(vs, false, sizeof(vs));
	dfs(1, time);
	FOR(i, 2, n) if (!vs[i]) return false;
	return true;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	int m, u, v, _t;
	scanf("%d %d", &n, &m);
	REP(i, m) {
		scanf("%d %d %d", &u, &v, &_t);
		adj[u].pb(make_pair(v, _t));
		adj[v].pb(make_pair(u, _t));
		t[i] = _t;
	}
	
	sort(t, t + m);
	int low = 0, hi = m - 1, mid;
	while (low < hi - 1) {
		mid = (low + hi) / 2;
		if (canGo(t[mid])) hi = mid;
		else low = mid + 1;
	}
	if (canGo(t[low])) cout << t[low];
	else if (canGo(t[hi])) cout << t[hi];

}
