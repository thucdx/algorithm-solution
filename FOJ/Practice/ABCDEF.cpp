#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define DOW(i, A, a) for (int i = (A), _a = (a); i >= _a; --i)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)


const int MAX = (int) 1e6;
int n;
int x[105], val[MAX + 5];
int p[105][105];

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
//	freopen("./IO/output", "w", stdout);
#endif

	long long total = 0;
	scanf("%d", &n);
	REP(i, n) scanf("%d", &x[i]);

	int cnt = 0;

	REP(i, n) FOR(j, i, n) p[i][j] = p[j][i] = x[i] * x[j];
	REP(i, n) {
		if (x[i]) {
			REP(j, n) {
				REP(t, n) {
					val[cnt++] = p[i][t] + p[i][j];
				}
			}
		}
	}

	sort(val, val + cnt);

	int tmp;
	REP(i, n) {
		REP(j, n) {
			int cur = p[i][j];
			REP(t, n) {
				tmp = cur + x[t];
				total += upper_bound(val, val + cnt, tmp) - lower_bound(val, val + cnt, tmp);
			}
		}
	}
	cout << total;
}

