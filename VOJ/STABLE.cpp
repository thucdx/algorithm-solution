#include <set>
#include <map>
#include <queue>
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

#define dbg(x) cout << #x << " = " << x << endl
#define ok() cout << "ok" << endl

typedef pair<int, int> II;

const int MAXN = 10000;
set<II> edge;
vector<int> next[MAXN + 5], prev[MAXN + 5];
bool isStable[MAXN + 5];
int minDis[MAXN + 5];
int n, m, s;

void dfs(int x) {
	REP(i, next[x].size()) {
		int cur = next[x][i];
		if (!isStable[cur] && minDis[cur] == minDis[x] + 1) {
			isStable[cur] = true;
			dfs(cur);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
//	freopen("./IO/output", "w", stdout);
#endif
	scanf("%d %d %d", &n, &m, &s);
	int u, v;
	II p;
	REP(i, m) {
		scanf("%d %d", &u, &v);
		p = make_pair(u, v);
		if (!edge.count(p)) {
			next[u].push_back(v), prev[v].push_back(u), edge.insert(p);
		}
	}

	// Dijikstra
	priority_queue<II> q;

	int d, nxt;
	fill(minDis, minDis + n + 1, MAXN + 1);
	minDis[s] = 0;
	q.push(make_pair(0, s));

	while (!q.empty()) {
		d = -q.top().first, v = q.top().second;
		q.pop();
		if (d > minDis[v]) continue;
		REP(i, next[v].size()) {
			nxt = next[v][i];
			if (minDis[nxt] > d + 1) {
				minDis[nxt] = d + 1;
				q.push(make_pair(-d-1, nxt));
			}
		}
	}

	FOR(i, 1, n) {
		if (i != s) {
			int cnt = 0;
			REP(j, prev[i].size()) {
				if (minDis[prev[i][j]] + 1 == minDis[i]) {
					cnt++;
					if (cnt > 1) {
						isStable[i] = true;
						break;
					}
				}
			}
		}
	}

	int cnt = 0;
	FOR(i, 1, n) if (isStable[i]) dfs(i);
	FOR(i, 1, n) cnt += isStable[i];
	cout << cnt << endl;
}

