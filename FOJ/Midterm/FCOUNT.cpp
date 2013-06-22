// {user = timxad; task = FCOUNT; date = Jun 21, 2013};
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

const int MAX = (int) 1e5;
int n, q, x[MAX + 5];

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	scanf("%d %d", &n, &q);
	REP(i, n) scanf("%d", &x[i]);
	sort(x, x + n);

	int a, b;
	REP(i, q) {
		scanf("%d %d", &a, &b);
		printf("%d\n", upper_bound(x, x + n, b) - lower_bound(x, x + n, a));
	}
}
