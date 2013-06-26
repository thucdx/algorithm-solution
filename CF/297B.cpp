/*
 * TIMXAD
 * Date : Apr 26, 2013, 6:00:45 PM
 * Task : 297B
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

int n, m, k;
vector<int> a, b;
vector<pair<int, int> > pa, pb;

void group(vector<int> &x, vector< pair<int, int> > &g) {
	sort(x.begin(), x.end());
	int last = x[0], cnt = 1;
	for (int i = 1; i < x.size(); ++i) {
		if (x[i] == last) cnt++;
		else {
			g.PB(MP(last, cnt));
			cnt = 1;
			last = x[i];
		}
	}
	g.PB(MP(last, cnt));
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	scanf("%d %d %d", &n, &m, &k);
	a.resize(n);
	b.resize(m);

	REP(i, n) scanf("%d", &a[i]);
	REP(i, m) scanf("%d", &b[i]);
	group(a, pa);
	group(b, pb);

	if (pa[SZ(pa) - 1].first > pb[SZ(pb) - 1].first) {
		puts("YES");
		return 0;
	}

	int i, j = SZ(pb) - 1, sumA = 0, sumB = 0;
	for (i = SZ(pa) - 1; i >= 0; --i) {
		sumA += pa[i].second;
		while (pb[j].first >= pa[i].first && j >= 0) {
			sumB += pb[j].second;
			--j;
		}
		if (sumA > sumB) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}
