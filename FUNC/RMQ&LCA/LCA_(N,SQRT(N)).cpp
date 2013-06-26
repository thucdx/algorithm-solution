/*
 * LCA, preprocessing in O(N) - dfs
 * query in SQRT(n)
 */
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




// t : parent, p : ancestor in last level of next section, l : level of node
// 1-based
inline void init() {
	ntest = 1;
}

const int PSIZE = (int) 1e6;
int t[PSIZE + 5], p[PSIZE], l[PSIZE];
vector<int> children[PSIZE + 5];
int n, nr;
void dfs(int node, int level){
	l[node] = level;

	if (level % nr == 0){
		p[node] = t[node];
	}
	else p[node] = p[t[node]];

	REP(i, SZ(children[node])){
		dfs(children[node][i], level + 1);
	}
}

int LCA(int x, int y){
	while (p[x] != p[y]){
		if (l[x] > l[y])
			x = p[x];
		else y = p[y];
	}

	while (x != y){
		if (l[x] > l[y])
			x = t[x];
		else y = t[y];
	}

	return x;
}

inline void run() {
	scanf("%d ", &n);
	int father, child;
	for (int i = 0; i < n - 1; ++i){
		scanf("%d %d", &father, &child);
		t[child] = father;
		children[father].push_back(child);
	}

	nr = sqrt(n);

	dfs(1, 1); // from node 1 at level 1.

	int nQuery, x , y;
	scanf("%d", &nQuery);

	REP(i, nQuery){
		scanf("%d %d",&x, &y);
		printf("%d\n", LCA(x, y));
	}
}
