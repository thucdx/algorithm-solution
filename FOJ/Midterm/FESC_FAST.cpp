// {user = timxad; task = FESC; date = Jun 21, 2013};
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

int n, x[25], maxCow, curCow, sumCur, sd[25];
ll cur;

inline int sumDig(ll x) {
	int sum = 0;
	while (x) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

void go(int step) {
	if (step >= n) {
		if (curCow > maxCow) maxCow = curCow;
		return;
	}

	if (curCow + n - step <= maxCow) return;

	// khong chon
	int _curCow = curCow;
	ll _cur = cur;
	go(step + 1);
	cur = _cur;
	curCow = _curCow;

	// thu chon
	ll newCur = cur + x[step];
	int newSum;
	if ((newSum = sumDig(newCur)) == sumCur + sd[step]) {
		cur = newCur;
		sumCur = newSum;
		++curCow;

		go(step + 1);

		--curCow;
		sumCur -= sd[step];
		cur = newCur - x[step];
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	scanf("%d", &n);
	REP(i, n) {
		scanf("%d", &x[i]);
		sd[i] = sumDig(x[i]);
	}

	maxCow = curCow = sumCur = cur = 0;
	go(0);
	printf("%d\n", maxCow);
}
