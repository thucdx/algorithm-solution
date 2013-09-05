// [TIMXAD] ~ [CNMARBLE] @ [Sep 3, 2013]
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cassert>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define DOW(i, A, a) for (int i = (A), _a = (a); i >= _a; --i)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

priority_queue<pair<int, int> > q;

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	int n, m, val;
	scanf("%d %d", &n, &m);
	FOR(i, 1, n) {
		scanf("%d", &val);
		q.push(make_pair(val, i));
	}

	vector<pair<int, int> > v;
	pair<int, int> top;
	while (!q.empty()) {
		v.clear();
		REP(i, m) {
			top = q.top(); q.pop();
			printf("%d ", top.second);
			if (top.first > 1)
				v.push_back(make_pair(top.first - 1, top.second));
		}
		printf("\n");
		FIT(it, v) q.push(*it);
	}
}
