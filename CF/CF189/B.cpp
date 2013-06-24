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

#define dbg(x) cout << #x << " = " << x << endl
#define ok() cout << "ok" << endl

typedef pair<int, int> II;
int nquery;
bool con[105][105];
II it[105];

bool vs[105];
bool found = true;
int destination;
int cnt = 0;

void dfs(int vertice) {
	if (found) return;
	if (vertice == destination) {
		found = true;
		return;
	}

	FOR(i, 1, cnt) {
		if (!vs[i] && con[vertice][i]) {
			vs[i] = true;
			dfs(i);
		}
	}
}

inline bool canMove(int from, int to) {
	II f = it[from], t = it[to];
	return (t.first < f.first && f.first < t.second)
			|| (t.first < f.second && f.second < t.second);
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
//	freopen("./IO/output", "w", stdout);
#endif
	int nquery, s, a, b;

	scanf("%d", &nquery);
	memset(con, false, sizeof(con));

	REP(i, nquery) {
		scanf("%d %d %d", &s, &a, &b);
		if (s == 1) {
			it[++cnt] = make_pair(a, b);
			FOR(j, 1, cnt - 1) {
				if (canMove(j, cnt)) con[j][cnt] = true;
				if (canMove(cnt, j)) con[cnt][j] = true;
			}
		} else {
			destination = b;
			found = false;
			memset(vs, false, sizeof(vs));
			vs[a] = true;
			dfs(a);
			if (found) puts("YES"); else puts("NO");
		}
	}
}
