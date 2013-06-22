#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define DOW(i, A, a) for (int i = (A), _a = (a); i >= _a; --i)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)

long long power(int a, int b) {
	long long rs = 1;
	for (int i = 1; i <= b; ++i) {
		rs *= a;
	}
	return rs;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
	freopen("./IO/output", "w", stdout);
#endif
	int n, c = 0;
	do {
		scanf("%d", &n);
		if (n == 0) break;
		long long rs = (n == 1 ? 1 : power(n, n - 2));
		c++;
		printf("Case %d, N = %d, # of different labelings = %lld\n", c, n, rs);
	} while (1);
}

