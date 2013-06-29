// TIMXAD - [LISA] @ [Jun 27, 2013]
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
typedef unsigned long long ul;

const ul MAXLL = (unsigned long long) -1;

ul dpmax[105][105], dpmin[105][105];
int a[55];
char ope[55]; // operator
string expression;

void solve() {
	FOR(i, 0, 100) FOR(j, 0, 100) {
		dpmax[i][j] = 0, dpmin[i][j] = MAXLL;
	}

	int n = 0, len = expression.length();
	for (int i = 0; i < len; ++i) {
		if (i % 2 == 0) {
			a[++n] = expression[i] - '0';
		} else {
			ope[n] = expression[i];
		}
	}

	for (int i = 1; i <= n; ++i) dpmax[i][i] = dpmin[i][i] = a[i];
	for (int l = 2; l <= n; ++l) {
		for (int i = 1; i <= n - l + 1; ++i) {
			int j = i + l - 1;
			for (int k = i; k < j; ++k) {
				if (ope[k] == '+') {
					dpmax[i][j] = max(dpmax[i][j], dpmax[i][k] + dpmax[k + 1][j]);
					dpmin[i][j] = min(dpmin[i][j], dpmin[i][k] + dpmin[k + 1][j]);
				} else {
					dpmax[i][j] = max(dpmax[i][j], dpmax[i][k] * dpmax[k + 1][j]);
					dpmin[i][j] = min(dpmin[i][j], dpmin[i][k] * dpmin[k + 1][j]);
				}
			}
		}
	}
	cout << dpmax[1][n] << " " << dpmin[1][n] << "\n";
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
//	freopen("./IO/output", "w", stdout);
#endif
	int ntest;
	ios_base::sync_with_stdio(false);
	cin >> ntest;
	while (ntest--) {
		cin >> expression;
		solve();
	}
}
