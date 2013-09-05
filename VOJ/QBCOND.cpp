// [TIMXAD] ~ [QBCOND] @ [Aug 8, 2013]
#include <set>
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

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int gt[15];
bool bit[15];

void init() {
	gt[0] = 1;
	FOR(i, 1, 10) gt[i] = i * gt[i - 1];
}

inline int solve(int n, int k) {
	int max = (1 << (n - 1)) - 1;
	int result = 0;

	for (int i = 0; i <= max; ++i) {
		int totalEqual = 0;
		int sum = gt[n];
		int cnt = 0;

		for (int j = 0; j < n - 1; ++j) {
			bit[j] = (i >> j) & 1;
			if (bit[j] == 0) cnt++;
			else {
				totalEqual += cnt * (cnt + 1) / 2;
				sum /= gt[cnt + 1];
				cnt = 0;
			}
		}
		totalEqual += cnt * (cnt + 1) / 2;
		sum /= gt[cnt + 1];

		if (totalEqual == k) result += sum;
	}
	return result;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	int n, k;

	init();
	while (1) {
		scanf("%d", &n);
		if (n < 0) break;
		scanf("%d", &k);
		printf("%d\n", solve(n, k));
	}
	
}
