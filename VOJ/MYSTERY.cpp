// [TIMXAD] ~ [MYSTERY] @ [Aug 27, 2013]
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

const int MOD = 20122007;

inline int powMod(int d) {
	ll rs = 1, base = 3;
	for(; d; d >>= 1) {
		if (d & 1) rs = (rs * base) % MOD;
		base = base * base % MOD;
	}
	return (rs + MOD - 1) % MOD;
}

bool isPrime(int n) {
	if (n <= 3) return n >= 2;
	if (n % 2 == 0) return false;
	int r = sqrt(n);
	for (int i = 3; i <= r; i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}

int total;
ll rs = 1;
map<int, int> u;
vector<pair<int, int> > uoc;

void go(int step, ll val) {
	if (step >= total) {
		rs = rs * powMod(val) % MOD;
		return;
	}

	int more = 1, totalUoc = uoc[step].second;
	for (int i = 0; i <= totalUoc; ++i) {
		go(step + 1, val * more);
		more *= uoc[step].first;
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	int n;
	cin >> n;
	if (n == 1) { cout << 2; return 0; }

	for (int i = 2; i * i <= n; ++i) {
		if (n % i) continue;
		int d = 0;
		while (n % i == 0) {
			++d;
			n /= i;
		}
		u[i] = d;
	}
	if (n != 1) u[n] = 1;

	total = 0;
	FIT(it, u) uoc.pb(make_pair(it->first, it->second));

	rs = 1; total = uoc.size();
	go(0, 1);
	cout << rs << endl;
}
