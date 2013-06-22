// {user = timxad; task = FDIGIT; date = Jun 21, 2013};
// {description = ?; reference = ?};
#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
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

// Total number of digits need to write all the numbers 1...n
ll numDigits(ll n) {
    ll result = 0;
    for (ll p = 1; p <= n; p *= 10) result += n - p + 1;
    return result;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	int d, k;
	ll num = 0;
	cin >> d >> k;

	if (d > 0 && d < 9) {
		int l = k / 2 + 1;
		num = ((ll) powl(10, l) - 1) / 9 * d;
		cout << numDigits(num) - l + 1 << endl;
	} else {
		if (d == 0) {
			num = (ll) powl(10, k);
			cout << numDigits(num) - k + 1 << endl;
		} else if (d == 9) {
			int l = k - 1;
			num = (ll) powl(10, l + 1) - (ll)powl(10, l) - 1;
			cout << numDigits(num) - l + 1 << endl;
		}
	}
}
