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


const int MAX = (int) 1e6;
int n, l[2005];

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
//	freopen("./IO/output", "w", stdout);
#endif
	while (scanf("%d", &n) && n) {
		REP(i, n) scanf("%d", &l[i]);
		sort(l, l + n);

		int total = 0;
		REP(i, n) {
			FOR(j, i + 1, n - 1) {
				int pos = upper_bound(l + j  + 1, l + n, l[i] + l[j]) - l;
				int cnt = n - pos;
				if (cnt < 0) cnt = 0;
				total += cnt;
			}
		}

		printf("%d\n", total);
	}
}

