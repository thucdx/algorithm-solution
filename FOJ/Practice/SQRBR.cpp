// TIMXAD - [SQRBR] @ [Jun 26, 2013]
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

ll dp[45][25];
bool mustOpen[40];

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
//	freopen("./IO/output", "w", stdout);
#endif
	int ntest, n, k, x;
	scanf("%d", &ntest);
	while (ntest--) {
		scanf("%d %d", &n, &k);

		FOR(i, 0, 40) FOR(j, 0, 20) dp[i][j] = 0;
		memset(mustOpen, false, sizeof(mustOpen));

		REP(i, k) {
			scanf("%d", &x);
			mustOpen[x] = true;
		}

		dp[0][0] = 1;
		FOR(i, 1, 2 * n) {
			FOR(j, 0, min(i, n)) {
				if (j > 0) dp[i][j] = dp[i - 1][j - 1];      // open (
				if (!mustOpen[i]) dp[i][j] += dp[i - 1][j + 1];	 // close )
			}
		}

		cout << dp[2 * n][0] << endl;
	}

}
