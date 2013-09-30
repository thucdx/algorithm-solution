#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <conio.h>

using namespace std;

#define MAX 1000000
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define SIZE(a) (int) a.size()
#define INF 1000000000

struct V {
	int id, d;

	V() {
	}

	V(int _id, int _d) {
		id = _id;
		d = _d;
	}

	bool operator<(const V& that) const {
		if (d != that.d)
			return d < that.d;
		return id < that.id;
	}
};

int n, m, e[MAX + 5];
vector<int> a[MAX + 5], b[MAX + 5];
set<V> s;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);

	REP(i, m) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(y);
		b[x].push_back(z);
	}

	REP(i, n)
		e[i] = INF;

	e[0] = 0;

	s.insert(V(0, 0));

	while (!s.empty()) {
		int i = s.begin()->id;
		int d = s.begin()->d;
		s.erase(s.begin());

		if (i == n - 1) {
			printf("%d", d);
			return 0;
		}

		REP(l, SIZE(a[i])) {
			int j = a[i][l];
			int k = b[i][l];

			if (e[j] > e[i] + k) {
				e[j] = e[i] + k;
				s.insert(V(j, e[j]));
			}
		}
	}

	return 0;
}
