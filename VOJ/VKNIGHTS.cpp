// {User = TIMXAD; Task = VKNIGHTS; Date = Jun 25, 2013};
// {Description = ?};
#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int _b = (b), i = (a); i <= _b; ++i)
#define DOWN(i, a, b) for (int _b = (b), i = (a); i >= _b; --i)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; ++i)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

#define dbg(x) cout << #x << " = " << x << endl
#define ok cout << "ok" << endl
typedef long long ll;

struct Node {
	ll maxKnight;
	ll number;

	Node() : maxKnight(0), number(0){}

	void set(ll max, ll num) {
		maxKnight = max;
		number = num;
	}

};

Node dp[105][10][10];
int n, z[105];

inline void extract(int x, int* a) {
	REP(i, 3) a[i] = x % 2, x >>= 1;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	scanf("%d", &n);
	z[0] = -1;
	FOR(i, 1, n) {
		scanf("%d", &z[i]);
		--z[i];
	}
	if (n == 1) {
		cout << (3 - (z[1] >= 0)) << " " << 1 << endl;
		return 0;
	}

	int a[5], b[5], c[5], cnt;
	// init
	// dp[1][x][y] = ?
	FOR(i, 0, 7) {
		extract(i, a);
		FOR(j, 0, 7) {
			extract(j, b);
			if (z[1] >= 0 && b[z[1]]) continue;
			if ((a[0] && b[2]) || (a[2] && b[0])) continue;
			cnt = 0; REP(t, 3) cnt += b[t];
			dp[1][i][j].set(cnt, 1);
		}
	}

	FOR(col, 2, n) {
		FOR(i, 0, 7) {
			extract(i, a);
			if (z[col - 1] >= 0 && a[z[col - 1]]) continue;
			FOR(j, 0, 7) {
				extract(j, b);
				if (z[col] >= 0 && b[z[col]]) continue;
				if ((a[0] && b[2]) || (a[2] && b[0])) continue; // no conflict
				cnt = 0; REP(t, 3) cnt += b[t];
				FOR(t, 0, 7) {
					extract(t, c);
					if (z[col - 2] >= 0 && c[z[col - 2]]) continue;
					if (((c[0] || c[2]) && b[1]) || (c[1] && (b[0] || b[2]))) continue;
					if ((c[0] && a[2]) || (c[2] && a[0])) continue;

					ll & kti = dp[col - 1][t][i].maxKnight;
					ll & kij = dp[col][i][j].maxKnight;

					ll cur = kti + cnt;
					if (cur > kij) {
						kij = cur;
						dp[col][i][j].number = dp[col - 1][t][i].number;
					} else {
						if (cur == kij) {
							if (col > 2)
								dp[col][i][j].number += dp[col - 1][t][i].number;
							else dp[col][i][j].number = dp[col - 1][t][i].number;
						}
					}
				}
			}
		}
	}

	int max = 0;
	FOR(i, 0, 7) FOR(j, 0, 7) {
		if (dp[n][i][j].maxKnight > max) {
			max = dp[n][i][j].maxKnight;
		}
	}

	ll total = 0;
	FOR(i, 0, 7) FOR(j, 0, 7) {
		if (dp[n][i][j].maxKnight == max) {
				total += dp[n][i][j].number;
		}
	}

	cout << max << " " << total << endl;
}
