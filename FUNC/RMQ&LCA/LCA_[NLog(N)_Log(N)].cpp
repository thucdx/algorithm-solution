/*
 * LCA : DP , preprocess in NLOGN
 * ans query in Log(n)
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

const int PSIZE = (int) 1e6;
const int LOGPSIZE = 40;

// Base 0;
inline void init() {
	ntest = 1;
}

int t[PSIZE + 5], l[PSIZE];
int p[PSIZE][LOGPSIZE];
vector<int> children[PSIZE + 5];
int n;

void dfs(int node, int level){
	l[node] = level;
	REP(i, SZ(children[node])){
		dfs(children[node][i], level + 1);
	}
}

void buildP(){
	REP(i, n){
		for (int j = 1; 1 << j < n; ++j)
			p[i][j] = -1;
	}

	REP(i, n) p[i][0] = t[i];

	for (int j = 1; 1 << j < n; ++j){
		for (int i = 0; i < n; ++i){
			if (p[i][j - 1] != -1)
				p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}
}

int LCA(int x, int y){
	if (l[x] < l[y]) swap(x, y);
	int log = log2(x);
	for (int i = log; i >= 0; --i){
		if (l[x] - (1 << i) >= l[y])
			x = p[x][i];
	}

	if (x == y) return x;

	for	(int i = log; i >= 0; --i){
		if (p[x][i] != -1 && p[x][i] != p[y][i]){
			x = p[x][i];
			y = p[y][i];
		}
	}

	return t[x];
}

inline void run() {
	scanf("%d ", &n);
	int father, child;
	for (int i = 0; i < n - 1; ++i){
		scanf("%d %d", &father, &child);
		father --;
		child --;
		t[child] = father;
		children[father].push_back(child);
	}

	dfs(0, 1);
	buildP();

	int nQuery, x , y;
	scanf("%d", &nQuery);

	REP(i, nQuery){
		scanf("%d %d",&x, &y);
		--x;
		--y;
		printf("%d\n", LCA(x, y) + 1);
	}
}
