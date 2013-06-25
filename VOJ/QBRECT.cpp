#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>

using namespace std;

#define FOR(i, a, b) for(int i=(a), _b=(b); i <= _b; ++i)
#define DOWN(i, a, b) for(int i=(a), _b=(b); i >= _b; --i)
#define MAXN 1111
int l[MAXN], r[MAXN], h[MAXN], a[MAXN][MAXN];

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif

	int m, n, kq = 0;
	scanf("%d %d", &m, &n);
	FOR(i, 1, m) FOR(j, 1, n) scanf("%d", &a[i][j]);

	FOR(i, 1, m) {
		FOR(j, 1, n) h[j] = (a[i][j] == 1) ? h[j] + 1 : 0;

		h[0] = -1; h[n + 1] = -1;
		FOR(j, 1, n) {
			l[j] = j;
			while (h[l[j] - 1] >= h[j]) l[j] = l[l[j] - 1];
		}

		DOWN(j, n, 1) {
			r[j] = j;
			while (h[r[j] + 1] >= h[j]) r[j] = r[r[j] + 1];
		}

		FOR(j, 1, n) kq = max(kq, h[j] * (r[j] - l[j] + 1));
	}

	printf("%d", kq);
}
