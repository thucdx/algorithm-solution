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

#define dbg(x) cout << #x << " = " << x << endl
#define ok() cout << "ok" << endl

typedef long long ll;

const int MOD = (int) 1e9 + 7;

inline ll powMod(ll a, ll b) {
	ll rs = 1;
	for (; b; b >>= 1) {
		if (b & 1) rs = rs * a % MOD;
		a = a * a % MOD;
	}
	return rs;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
//	freopen("./IO/output", "w", stdout);
#endif
	string s;
	ll result = 0;
	ll weighted = 1;
	cin >> s;
	int len = s.length();
	FOR(i, 0, len - 1) {
		if (s[i] == '1') {
			result += powMod(2, 2 * (len - i - 1)) * weighted;
			result %= MOD;
//			cout << i << " " << result << endl;
		}
		weighted *= 2;
		weighted %= MOD;
	}
	cout << result << endl;
}
