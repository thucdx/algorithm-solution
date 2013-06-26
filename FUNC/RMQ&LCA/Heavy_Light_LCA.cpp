#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int ntest = 0, test = 0;
inline void init();
inline void run();
inline void stop() {
	ntest = test - 1;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	init();
	while (++test <= ntest) {
		run();
	}
	return 0;
}

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, a) for (int i = 0; i < (a); i++)
#define FIT(it, v) for (typeof((v).begin())it = (v).begin(); it != (v).end(); it++)

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SET(a, x) memset((a), (x), sizeof(a))
#define SORT(v) sort(ALL(v))
#define GSORT(v) sort(ALL(v), greater<typeof(*(v).begin())>())
#define UNIQUE(v) SORT(v); (v).resize(unique(ALL(v)) - (v).begin())

#define PB push_back
#define MP make_pair
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = (int) 1E9 + 5;
const double EPS = 1E-11;
const ll MOD = (ll) 1E9 + 7;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

inline void init() {
	ntest = 1;
}

const int PSIZE = 100;
vector<int> children[PSIZE + 5];
int n, parent[PSIZE + 5], level[PSIZE + 5], numChild[PSIZE + 5];

int dfs1(int ver, int levelVer){
	int nodes = 1;
	level[ver] = levelVer;
	for (int i = 0; i < SZ(children[ver]); ++i){
		nodes += dfs1(children[ver][i], levelVer + 1);
	}
	return numChild[ver] = nodes;
}

void dfs2(int curVer, int host){

}

inline void run() {
	scanf("%d", &n);
	int x, y;
	REP(i, n - 1){
		scanf("%d %d", &x, &y);
		children[x].PB(y);
		parent[y] = x;
	}

	dfs1(1, 0);

	/*for (int i = 1; i <= n; ++i){
		cout << i << " " << level[i] << " " << numChild[i] << endl;
	}*/


}
