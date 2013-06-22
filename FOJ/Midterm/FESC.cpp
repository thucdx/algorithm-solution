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
#include <sstream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int _b = (b), i = (a); i <= _b; ++i)
#define DOWN(i, a, b) for (int _b = (b), i = (a); i >= _b; --i)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; ++i)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

#define dbg(x) cout << #x << " = " << x << endl
#define ok cout << "ok" << endl

typedef long long ll;

bool carry[25][25], fr[25];
int n, x[25], totalCow, maxCow;
ll curSum;

stringstream ss;
inline string toString(ll a) {
	string rs;
	ss.clear();
	ss << a;
	ss >> rs;
	return rs;
}

inline bool needCarryOut(ll a, ll b) {
	string stra = toString(a), strb = toString(b);
	int la = stra.length() - 1, lb = strb.length() - 1;
	for (; la >= 0 && lb >= 0; la--, lb--) {
		if (stra[la] - '0' + strb[lb] - '0' >= 10) return true;
	}
	return false;
}

void go(int step) {
//	cout << " step = " << step << " curSum = " << curSum << " totalCow = " << totalCow << endl;
	if (step >= n) {
		if (totalCow > maxCow) maxCow = totalCow;
		return;
	}

	// khong chon
	ll _curSum = curSum;
	int _totalCow = totalCow;
	go(step + 1);
	curSum = _curSum;
	totalCow = _totalCow;

	// thu chon
	if (!needCarryOut(curSum, x[step])) {
		bool shouldGo = true;
		REP(i, step) {
			if (!fr[i] && carry[i][step]) {
				shouldGo = false;
				break;
			}
		}

		if (shouldGo) {
			curSum += x[step];
			fr[step] = false;
			totalCow++;

			go(step + 1);

			totalCow--;
			fr[step] = true;
			curSum -= x[step];
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	scanf("%d", &n);
	REP(i, n) scanf("%d", &x[i]);
	REP(i, n) FOR(j, i + 1, n - 1) {
		if (needCarryOut(x[i], x[j]))
			carry[i][j] = carry[j][i] = true;
	}

	totalCow = maxCow = curSum = 0;
	memset(fr, true, sizeof(fr));
	go(0);
	printf("%d\n", maxCow);
}
