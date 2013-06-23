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

typedef long long ll;

ll n;
int mod;

ll** mulMod(ll* a[], ll* b[], int size, int mod) {
	ll ** rs = new ll* [size];

	REP(i, size) rs[i] = new ll[size];
	REP(i, size) REP(j, size) {
		rs[i][j] = 0;
		REP(t, size) {
			rs[i][j] += (a[i][t] * b[t][j]) % mod;

			// fast mod
			if (rs[i][j] < 0) rs[i][j] += mod;
			if (rs[i][j] > mod) rs[i][j] -= mod;
		}
	}
	return rs;
}

ll** powMod(ll* a[], int size, long long p, int mod) {
	ll ** rs = new ll* [size];
	REP(i, size) rs[i] = new ll[size];

	if (p == 1) REP(i, size) REP(j, size) rs[i][j] = a[i][j];
	else {
		ll** half = powMod(a, size, p / 2, mod);
		rs = mulMod(half, half, size, mod);
		if (p % 2) rs = mulMod(rs, a, size, mod);
	}

	return rs;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
//	freopen("./IO/output", "w", stdout);
#endif
	scanf("%lld %d", &n, &mod);

	ll** a = new ll* [2];
	REP(i, 2) a[i] = new ll[2];
	a[0][0] = 0, a[0][1] = 1;
	a[1][0] = -1, a[1][1] = 3;

	if (n == 2) {
		cout << 1 % mod;
	} else {
		a = powMod(a, 2, n - 2, mod);
		cout << ((long long)a[0][0] * 1 + (long long)a[0][1] * 2) % mod;
	}
}
