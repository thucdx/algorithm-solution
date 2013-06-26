/* TIMXAD
* Task : 295B
* Desc : 
*/
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(a) a.size()

#define FOR(i, a, b) for (int _b = (b), i = (a); i <= _b; i++)
#define FORD(i, a, b) for (int _b = (b), i = (a); i >= _b; i--)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; i++)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

int a[505], n;
long long rs[505], d[505][505];

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	scanf("%d", &n);
	REP(i, n) REP(j, n) scanf("%I64d", &d[i][j]);
	REP(i, n) {
		scanf("%d", &a[i]);
		--a[i];
	}

	FORD(i, n - 1, 0) {
		FORD(j, n - 1, 0) FORD(k, n - 1, 0) {
			d[a[j]][a[k]] = min (d[a[j]][a[k]], d[a[j]][a[i]] + d[a[i]][a[k]]);
		}
		long long ans = 0;
		FORD(j, n - 1, i) FORD(k, n - 1, i)	ans += d[a[j]][a[k]];
		rs[i] = ans;
	}

	REP(i, n) printf("%I64d ", rs[i]);
}
