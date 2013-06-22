/*
* Who  : timxad
* Task : MKJUMPS
* Date : Jun 13, 2013
* Desc :
*/
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define Sort(a) sort(all(a))
#define Unique(a) Sort(a); a.resize(unique(all(a) - a.begin()))

#define For(i, a, b) for (int _b = (b), i = (a); i <= _b; ++i)
#define Ford(i, a, b) for (int _b = (b), i = (a); i >= _b; --i)
#define Rep(i, a) for (int i = 0, _a = (a); i < _a; ++i)
#define Fit(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define nl puts("") // new line
#define sp printf(" ") // space
#define ok puts("ok")
#define show(x) cout << x << endl
#define dbg(x) cout << #x << " = " << x << endl

typedef pair<int, int> II;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;

const int INF		= (int) 1e9 + 5;
const ll INFL 		= (ll) 1e16 + 6;
const int MOD 		= (int) 1e9 + 7;
const double EPS 	= 1e-6;

int dx[] = {-2, -2, -1, -1,  1, 1,  2, 2};
int dy[] = {-1,  1, -2,  2, -2, 2, -1, 1};

bool vs[11][11];
const int MAX_COL = 10;
int n, cnt, reached, total;

void dfs(int x, int y) {
	cnt++;
	vs[x][y] = true;
	if (cnt > reached) reached = cnt;

	for (int i = 0; i < 8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < MAX_COL && !vs[nx][ny]) {
			dfs(nx, ny);
			vs[nx][ny] = false;
			cnt--;
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	int test = 0, start, len;

	while (1) {
		scanf("%d", &n);
		if (n == 0) break;

		test++;
		total = 0; reached = 0; cnt = 0;
		memset(vs, true, sizeof(vs));
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &start, &len);
			total += len;
			for (int j = start; j <= start + len - 1; ++j) {
				vs[i][j] = false;
			}
		}
		for (int j = 0; j < MAX_COL; ++j) {
			if (!vs[0][j]) {
				dfs(0, j);
				break;
			}
		}

		int notReached = total - reached;
		cout << "Case " << test << ", " << notReached << " " << (notReached == 1? "square" : "squares") << " can not be reached.\n";
//		printf("Case %d, %d squares can not be reached.\n", test, total - reached);
	}
}

