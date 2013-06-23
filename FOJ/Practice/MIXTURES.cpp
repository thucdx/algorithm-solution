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
#define DOW(i, A, a) for (int i = (A), _a = (a); i >= _a	; --i)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)

typedef long long ll;

const int MAXLL = (int) 1e9;
int n, x[105], s[105];
int f[105][105];

inline int getSum(int low, int hi) {
	return ((s[hi] - s[low] + x[low]) % 100 + 100 ) % 100;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
	//freopen("./IO/output", "w", stdout);
#endif
	while (scanf("%d", &n) != EOF) {
		REP(i, n) scanf("%d", &x[i]);
		s[0] = x[0];

		// Calculate cummulative sum s[i] = (x[0] + ... + x[i]) % 100;
		FOR(i, 1, n - 1) {
			s[i] = s[i - 1] + x[i];
			if (s[i] >= 100) s[i] -= 100;
		}

		// DP
		REP(i, n) {
			f[i][i] = 0;
			DOW(j, i - 1, 0) {
				f[j][i] = MAXLL;
				FOR(t, j, i - 1) {
					f[j][i] = min(f[j][i], f[j][t] + f[t + 1][i] + getSum(j, t) * getSum(t + 1, i));
				}
			}
		}

		printf("%d\n", f[0][n - 1]);
	}
}

