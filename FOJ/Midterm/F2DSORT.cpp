// {user = timxad; task = F2DSORT; date = Jun 21, 2013};
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
pair<int, int> x[MAX + 5];
int n, q;
int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	scanf("%d %d", &n, &q);

	int a, b;
	REP(i, n) {
		scanf("%d %d", &a, &b);
		x[i] = make_pair(a, b);
	}

	sort(x, x + n);

	pair<int, int> cur;
	REP(i, q) {
		scanf("%d %d", &a, &b);
		cur = make_pair(a, b);
		bool found = binary_search(x, x + n, cur);
		if (found) printf("Y"); else printf("N");
	}
}
