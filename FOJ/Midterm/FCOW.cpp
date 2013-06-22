// {user = timxad; task = FCOW; date = Jun 21, 2013};
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

const int MAX_N = 20000;
int n, a[5][MAX_N + 5], pos[5][MAX_N + 5], orginal[MAX_N + 5];

inline bool cmp(int x, int y) {
	int cnt = 0;
	REP(i, 5) {
		if (pos[i][x] > pos[i][y]) cnt++;
		else cnt--;
	}
	return cnt < 0;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	scanf("%d", &n);
	REP(i, 5) REP(j, n) {
		scanf("%d", &a[i][j]);
		pos[i][a[i][j]] = j;
	}

	REP(i, n) orginal[i] = a[0][i];

	sort(orginal, orginal + n, cmp);

	REP(i, n) printf("%d\n", orginal[i]);
}
