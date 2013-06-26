/*
* TIMXAD
* Date : Apr 16, 2013, 2:41:12 PM
* Task : 107A
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

#define FOR(i, a, b) for (int _b = (b), i = (a); i <= _b; i++)
#define FORD(i, a, b) for (int _b = (b), i = (a); i >= _b; i--)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; i++)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

#define MAX 1000
const int INF = (int) (1e6 + 5);

int r[MAX + 5], maxD[MAX + 5], n, p;
bool in[MAX + 5], out[MAX + 5];

inline int getRoot(int x) {
	return x == r[x] ? x : r[x] = getRoot(r[x]);
}

inline void unite(int a, int b) {
	int ra = getRoot(a), rb = getRoot(b);
	r[rb] = ra;
	maxD[ra] = min(maxD[b], maxD[ra]);
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	while (scanf("%d %d", &n, &p) != EOF) {
		FOR(i, 1, n) r[i] = i, maxD[i] = INF;
		memset(in, false, sizeof(in));
		memset(out, false, sizeof(out));

		int a, b , d;
		REP(i, p) {
			scanf("%d %d %d", &a, &b, &d);
			in[b] = true; out[a] = true;
			maxD[b] = min(maxD[b], d);
			unite(a, b);
		}

		vector<pair<int, int> > tankAndTap;
		FOR(i, 1, n) {
			if (r[i] != i && !out[i] && in[i]) {
				tankAndTap.push_back(MP(getRoot(i), i));
			}
		}

		sort(tankAndTap.begin(), tankAndTap.end());
		printf("%d\n", tankAndTap.size());
		REP(i, tankAndTap.size()) {
			printf("%d %d %d\n", tankAndTap[i].first, tankAndTap[i].second, maxD[tankAndTap[i].first]);
		}
	}
}
