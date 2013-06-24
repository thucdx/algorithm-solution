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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int m, n, h[105][105], w[105][105];
vector<II> vp[1005];

inline bool isBorder(int x, int y) {
	REP(i, 4) {
		int nx = x + dx[i], ny = y + dy[i];
		if (w[nx][ny] >= 0) return true;
	}
	return false;
}

void dfs(int x, int y, int height) {
//	cout << "dfs " << x << " " << y << " " << height << endl;
	REP(i, 4) {
		int nx = x + dx[i], ny = y + dy[i];
		if (w[nx][ny] == -1 && h[nx][ny] <= height) {
			w[nx][ny] = height; dfs(nx, ny, height);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
//	freopen("./IO/output", "w", stdout);
#endif

	int maxH = 0;
	scanf("%d %d", &m, &n);
	FOR(i, 1, m) FOR(j, 1, n) {
		scanf("%d", &h[i][j]);
		vp[h[i][j]].push_back(make_pair(i, j));
		if (h[i][j] > maxH) maxH = h[i][j];
	}

	FOR(i, 1, m) FOR(j, 1, n) w[i][j] = -1;
//	FOR(i, 1, m) w[i][0] = w[i][n + 1] = 0;
//	FOR(i, 1, n) w[0][i] = w[m + 1][i] = 0;

	FOR(i, 1, maxH) {
		REP(j, vp[i].size()) {
			int x = vp[i][j].first, y = vp[i][j].second;
			if (w[x][y] == -1 && isBorder(x, y)) {
				w[x][y] = i;
				dfs(x, y, i);
			}
		}
	}

	int res = 0;
	FOR(i, 1, m) FOR(j, 1, n) res += w[i][j] - h[i][j];
	cout << res << endl;
}
