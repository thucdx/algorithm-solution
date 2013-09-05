// TIMXAD - [BRIDGES] @ [Jul 4, 2013]
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

const int MAX = 10000;

struct Edge {
	int num;
	int ver1, ver2, length;
	double weighted;

	Edge() {
		num = -1, ver1 = ver2 = length = 0;
		weighted = 0;
	}

	Edge(int _n, int _v1, int _v2, int _l) {
		num = _n, ver1 = _v1, ver2 = _v2, length = _l;
		weighted = 0;
	}

	void setWeighted(double w) {
		weighted = w;
	}

	bool operator<(const Edge& other) const {
		return weighted > other.weighted;
	}

	int getOtherVer(int ver) {
		if (ver1 == ver) return ver2;
		if (ver2 == ver) return ver1;
		return -1;
	}
} e[MAX + 5];

vector<int> adj[MAX + 5]; // edge
bool vs[MAX + 5];
int numChild[MAX + 5], k, n, vp, vc;

int dfs(int ver) {
	int sum = 1;
	REP(i, adj[ver].size()) {
		int edgeNum = adj[ver][i];
		int nxt = e[edgeNum].getOtherVer(ver);
		if (!vs[nxt]) {
			vs[nxt] = true;
			sum += dfs(nxt);
		}
	}
	return numChild[ver] = sum;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif

	scanf("%d %d %d %d", &n, &k, &vp, &vc);

	int u, v, l;
	FOR(i, 1, n - 1) {
		scanf("%d %d %d", &u, &v, &l);
		e[i] = Edge(i, u, v, l);
		adj[u].push_back(i);
		adj[v].push_back(i);
	}

	vs[1] = true;
	dfs(1);

	double unit = 1.0/vp - 1.0/vc;
	FOR(i, 1, n - 1) {
		ll minNum = min(numChild[e[i].ver1], numChild[e[i].ver2]);
		e[i].setWeighted(minNum * (n - minNum) * e[i].length * unit);
	}

	sort(e + 1, e + n);
	FOR(i, 1, k) printf("%d ", e[i].num);
}
