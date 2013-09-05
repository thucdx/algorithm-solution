// [TIMXAD] ~ [FWATER] @ [Aug 22, 2013]
#include <set>
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
const int MAX = 300;
int n, w[MAX + 5];
int parent[MAX + 5];

inline int getRoot(int v) {
	return v == parent[v] ? v : parent[v] = getRoot(parent[v]);
}

inline bool unite(int u, int v) {
	int pu = getRoot(u), pv = getRoot(v);
	if (pu == pv) return false;
	parent[pu] = pv;
	return true;
}

struct Edge {
	int u, v, cost;

	Edge() {}
	Edge(int _u, int _v, int _cost) {
		u = _u, v = _v, cost = _cost;
	}

	bool operator<(const Edge& other) const {
		if (cost != other.cost) return cost < other.cost;
		return v < other.v;
	}
};
vector<Edge> e;

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	scanf("%d", &n);
	REP(i, n) scanf("%d", &w[i]);
	int d;
	REP(i, n) {
		REP(j, n) {
			scanf("%d", &d);
			if (i != j) e.push_back(Edge(i, j, d));
		}
		e.push_back(Edge(i, n, w[i]));
	}

	sort(e.begin(), e.end());

	int cost = 0, cnt = 0;
	REP(i, n + 1) parent[i] = i;

	Edge cur;
	for (int i = 0; cnt < n; ++i) {
		cur = e[i];
		if (unite(cur.u, cur.v)) {
			cost += cur.cost;
			++cnt;
		}
	}

	cout << cost << endl;
}
