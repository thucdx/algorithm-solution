// [TIMXAD] ~ [NKGAME] @ [Aug 27, 2013]
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
const int MAX = (int) 1e5;
int n, a[MAX + 5], b[MAX + 5];

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	scanf("%d", &n);
	ll rs = (int) 2e9;

	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) scanf("%d", &b[i]);

	sort(b, b + n);
	REP(i, n) {
		// a[i] + b[j] >= 0
		int j = lower_bound(b, b + n, -a[i]) - b;
		if (0 <= j && j < n && abs(a[i] + b[j]) < rs) rs = abs(a[i] + b[j]);
		--j;
		if (0 <= j && j < n && abs(a[i] + b[j]) < rs) rs = abs(a[i] + b[j]);
		if (rs == 0) break;
	}

	cout << rs << endl;
}
