// [TIMXAD] ~ [VOLIS] @ [Sep 5, 2013]
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cassert>
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
#define sz(a) (int) a.size()
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = 2e9 + 1;

int f[1005];
int cur[1005];

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	int d, n, val;
	f[0] = - INF;
	FOR(i, 1, 1000) f[i] = INF;
	scanf("%d %d", &n, &d);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &val);
		FOR(j, 1, i) cur[j] = f[j];

		int l;
		for (l = 1; l <= i; ++l) {
			if (f[l - 1] <= val + d) {
				cur[l] = min(f[l], max(f[l - 1], val - d));
			} else break;
		}

		FOR(t, 1, min(l, i)) f[t] = cur[t];
	}

	int rs = 1;
	while (rs <= n && f[rs] < INF) ++rs;
	printf("%d\n", rs - 1);
}
