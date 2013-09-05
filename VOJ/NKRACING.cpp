// [TIMXAD] ~ [NKRACING] @ [Aug 27, 2013]
#include <set>
#include <map>
#include <queue>
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
#define sz(a) (int) a.size()
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int MAX_N = 10000;
int parent[MAX_N + 5];

struct Edge {
	int u, v, d;

	Edge(){ u = v = d = 0;}
	Edge(int _u, int _v, int _d) {
		u = _u, v = _v, d = _d;
	}

	bool operator<(const Edge& other) const {
		if (d != other.d) return d > other.d;
		return false;
	}
} e[100005];

inline int getParent(int v) {
	return v == parent[v] ? v : parent[v] = getParent(parent[v]);
}

inline bool unite(int u, int v) {
	int pu = getParent(u), pv = getParent(v);
	if (pu == pv) return false;
	parent[pu] = pv;
	return true;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	ll total = 0;
	int n, m, u, v, d;
	scanf("%d %d", &n, &m);
	REP(i, m) {
		scanf("%d %d %d", &u, &v, &d);
		total += d;
		e[i] = Edge(u, v, d);
	}

	FOR(i, 1, n) parent[i] = i;
	sort(e, e + m);
	REP(i, m) {
		if (unite(e[i].u, e[i].v)) total -= e[i].d;
	}
	cout << total << endl;
}
