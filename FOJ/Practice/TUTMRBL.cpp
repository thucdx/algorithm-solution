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

const int MAX = (int)1e7;
int sieve[MAX + 5];

void init() {
	int r = (int) sqrt(MAX);
	for (int i = 2; i <= r; i++) {
		if (!sieve[i])	for (int j = i * i; j <= MAX; j += i) {
			if (!sieve[j])
				sieve[j] = i;
		}
	}

	for (int i = 2; i <= MAX; ++i) {
		if (!sieve[i]) sieve[i] = i;
//		if (i <= 100) {
//			cout << i << " " << sieve[i] << endl;
//		}
	}
}

void solve(int n) {
	int _n = n, total = 1, cnt = 0, last = -1;
	printf("%d =", n);

	while (sieve[n] != n) {
		printf(" %d *", sieve[n]);

		if (sieve[n] == last) {
			cnt++;
		} else {
			total *= (1 + cnt);
			last = sieve[n];
			cnt = 1;
		}

		n /= sieve[n];
	}

	if (n == last) {
		cnt++;
	} else {
		total *= (1 + cnt);
		cnt = 1;
	}
	total *= 1 + cnt;
	total = (total + 1) / 2;
	printf(" %d\n", n);
	printf("With %d marbles, %d different rectangles can be constructed.\n", _n, total);
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
//	freopen("./IO/output", "w", stdout);
#endif
	init();
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		solve(n);
	}
}

