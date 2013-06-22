// {user = timxad; task = FGEN; date = Jun 21, 2013};
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

bool fr[15];
int cur[15], n, k;

void go(int step) {
	if (step > k) {
		FOR(i, 1, k) printf("%d ", cur[i]);
		printf("\n");
		return;
	}

	for (int i = cur[step - 1] + 1; i <= n - (k - step); ++i) {
		if (fr[i]) {
			cur[step] = i;
			fr[i] = false;
			go(step + 1);
			fr[i] = true;
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	scanf("%d %d", &n, &k);
	cur[0] = 0;
	memset(fr, true, sizeof(fr));
	go(1);
}
