// [TIMXAD] ~ [PTIT136I] @ [Aug 28, 2013]
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

const int PARTS = 10000;

int k;
double p[2][10], q[2][10], f[2][PARTS + 10], w, d, a;

inline double poly(int id, double x) {
	double t = 0, m = 0;
	for (int i = k; i >= 0; --i) {
		t = t * x + p[id][i];
		m = m * x + q[id][i];
	}
	return t / m;
}

inline void init() {
	double delta = w / PARTS, x = delta / 2;
	for (int i = 0; i < PARTS; ++i, x += delta) {
		REP(j, 2) f[j][i] = poly(j, x);
	}
}

inline double getArea(double limit) {
	double rs = 0;
	for (int i = 0 ; i < PARTS; ++i)
		rs += max(f[0][i], limit) - max(f[1][i], limit);
	return rs * w / PARTS;
}

int main() {
	while (scanf("%lf", &w) != EOF) {
		scanf("%lf %lf %d", &d, &a, &k);

		REP(i, 2) {
			REP(j, k + 1) scanf("%lf", &p[i][j]);
			REP(j, k + 1) scanf("%lf", &q[i][j]);
		}

		init();

		double lo = -d, hi = 0, mid;
		while (fabsl(lo - hi) > 1e-7) {
			mid = (lo + hi) / 2;
			if (getArea(mid) > a) lo = mid;
			else hi = mid;
		}

		printf("%.5lf\n", (double) - mid);
	}
}

