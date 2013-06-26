/* TIMXAD
* Task : 292D
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

int n, m, k, p[505], br[1005], ss[10005], ee[10005], imp[10005];
int totalBr;

inline int findRoot(int x) {
	while (x != p[x]) {
		p[x] = p[p[x]];
		x = p[x];
	}
	return x;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	scanf("%d %d", &n, &m);
	FOR(i, 1, m) scanf("%d %d", &ss[i], &ee[i]);

	totalBr = 0;
	FOR(i, 1, n) p[i] = i;
	FOR(i, 1, m) {
		int u = findRoot(ss[i]);
		int v = findRoot(ee[i]);
		if (u != v) {
			imp[i] = true;
			p[u] = v;
			br[totalBr++] = i;
		}
	}

	FOR(i, 1, n) p[i] = i;
	FORD(i, m, 1) {
		int u = findRoot(ss[i]);
		int v = findRoot(ee[i]);
		if (u != v) {
			if (!imp[i])
				br[totalBr++] = i;
			p[u] = v;
		}
	}

	scanf("%d", &k);
	int from, to;
	while (k--) {
		scanf("%d %d", &from, &to);
		FOR(i, 1, n) p[i] = i;
		REP(i, totalBr) {
			if (br[i] < from || br[i] > to) {
				int u = findRoot(ss[br[i]]);
				int v = findRoot(ee[br[i]]);
				if (u != v) p[u] = v;
			}
		}
		int ans = 0;
		FOR(i, 1, n) ans += (p[i] == i);
		printf("%d\n", ans);
	}
}
