// [TIMXAD] ~ [AREA] @ [Aug 7, 2013]
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
const int MAX = 30000;

struct Edge {
	int x, y0, y1, sign;

	Edge(){x = y0 = y1 = sign = -1;}
	Edge(int _x, int _y0, int _y1, int _s) {
		x = _x, y0 = _y0, y1 = _y1, sign = _s;
	}

	bool operator<(const Edge& other) const {
		return x < other.x;
	}

	void show() {
		cout << x << " " << y0 << " " << y1 << " " << sign << endl;
	}
};

vector<Edge> edges;
int it[4 * MAX + 5], cnt[4 * MAX + 5];

inline void update(int node, int u, int v, int x, int y, int sign) {
	if (x > v || y < u) return;
	if (u >= x && v <= y) {
		cnt[node] += sign;
	} else {
		int mid = (u + v) / 2;
		update(node * 2, u, mid, x, y, sign);
		update(node * 2 + 1, mid + 1, v, x, y, sign);
	}

	if (cnt[node] > 0) {
		it[node] = v - u + 1;
	} else {
		it[node] = 0;
		if (v > u) {
			it[node] = it[node * 2] + it[node * 2 + 1];
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	int n, x0, y0, x1, y1;

	scanf("%d", &n);
	REP(i, n) {
		scanf ("%d %d %d %d", &x0, &y0, &x1, &y1);
		edges.pb(Edge(x0, y0, y1 - 1, 1));
		edges.pb(Edge(x1, y0, y1 - 1, -1));
	}

	sort(edges.begin(), edges.end());

	Edge cur;
	int area = 0, lastx = 0;
	FIT(i, edges) {
		area += it[1] * (i->x - lastx);
		lastx = i->x;
		update(1, 0, MAX, i->y0, i->y1, i->sign);
	}

	cout << area << endl;
}
