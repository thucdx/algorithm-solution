/* TIMXAD
 * Task : LAZYPROG
 * Desc : http://poj.org/problem?id=2970
 */
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(a) a.size()

#define FOR(i, a, b) for (int _b = (b), i = (a); i <= _b; i++)
#define FORD(i, a, b) for (int _b = (b), i = (a); i >= _b; i--)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; i++)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

const int MAX = 100000;
int n, a[MAX + 5], b[MAX + 5], d[MAX + 5];
int post[MAX + 5];
vector<pair<int, int> > dd;

double c[MAX + 5];
vector<pair<int, int> > sa;

inline bool equal(double a, double b) {
	return abs(a - b) < 1e-6;
}

inline void pushHeap(pair<int, int> p) {
	sa.push_back(p);
	push_heap(sa.begin(), sa.end());
}

inline void popHeap() {
	pop_heap(sa.begin(), sa.end());
	sa.pop_back();
}

void sortD() {
	dd.clear();
	FOR(i, 1, n) {
		dd.PB(MP(d[i], i));
	}
	sort(dd.begin(), dd.end());
	REP(i, SZ(dd)) {
		post[i + 1] = dd[i].second;
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%d %d %d", &a[i], &b[i], &d[i]);
	}

	double t = 0;
	double cost = 0.0;

	sortD();
	FOR(i, 1, n) c[i] = (double) b[i] / a[i];
	FOR(z, 1, n) {
		int i = post[z];
		pushHeap(MP(a[i], i));

		if (t + b[i] <= d[i]) {
			t += b[i];
		} else {
			double down = t + b[i] - d[i];
			double cur = 0;
			while (cur < down) {
				int j = sa.front().second;
				double x = a[j] * c[j];
				if (x >= down - cur) {
					if (equal(x, down - cur)) {
						c[j] = 0;
						popHeap();
					} else {
						c[j] -= (down - cur) / a[j];
					}
					cost += (down - cur) / a[j];
					cur = down;
				} else {
					popHeap();
					cost += c[j];
					c[j] = 0;
					cur += x;
				}
			}
			t = d[i];
		}
	}
	printf("%.2lf\n", cost);
}
