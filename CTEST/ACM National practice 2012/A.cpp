// Created : 1:46:31 PM Oct 22, 2012
// Task    : A

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <list>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (typeof(b) i = (a); i <= (b); i++)
#define FORD(i, a, b) for (typeof(a) i = (a); i >= (b); i--)
#define REP(i, a) for (typeof(a) i = 0; i < (a); i++)
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

#define DEBUG(x) cout << #x << " = "; cout << x << endl; // thank RR for that
#define PR(a,n) cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl;
#define PR0(a,n) cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

const double PI = 4 * atan(1);   // d / ld ?
const int INF = (int) 1E9 + 5;  // enough ?
const double EPS = 1E-11;      // relevant ?
const ll MOD = (ll) 1E9 + 7;  // problem's mod ?

const int PSIZE = (int)(1e5);
const int LOGPSIZE = 20;

int ntest = 0, test = 0;
inline void init();
inline void run();
inline void stop() {
	ntest = test - 1;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	init();
	while (++test <= ntest) {
		run();
	}
	return 0;
}

inline void init() {
	ntest = INF;
}

int n;
vector<int> children[PSIZE + 5];
vector<int> disx[PSIZE + 5];

int dp[PSIZE][LOGPSIZE], l[PSIZE + 5], parentOf[PSIZE + 5]; // level, parent
ll disFromRoot[PSIZE + 5];

void dfs(int nod, int level, ll dis){
	l[nod] = level;
	disFromRoot[nod] = dis;
	REP(child, SZ(children[nod])){
		int next = children[nod][child];
		int disNext = disx[nod][child];
		dfs(next, level + 1, dis + disNext);
	}
}

void buildDP(){
	REP(i, n){
		for (int j = 1; 1 << j < n; ++j)
			dp[i][j] = -1;
	}

	REP(i, n) dp[i][0] = parentOf[i];
	for (int j = 1; 1 << j < n; ++j){
		for (int i = 0; i < n; ++i){
			if (dp[i][j - 1] != -1){
				dp[i][j] = dp[dp[i][j - 1]][j - 1];
			}
		}
	}
}

int getLCA(int x, int y){
	if (l[x] < l[y]) swap(x, y);
	int logi = log2(x);

	for (int i = logi; i >= 0; --i){
		if (l[x] - (1 << i) >= l[y]){
			x = dp[x][i];
		}
	}
	if (x == y) return x;

	for (int i = logi; i >= 0; --i){
		if (dp[x][i] != -1 && dp[x][i] != dp[y][i]){
			x = dp[x][i];
			y = dp[y][i];
		}
	}

	return parentOf[x];
}

ll getDis(int i, int j){
	int lca = getLCA(i, j);
	return disFromRoot[i] - disFromRoot[lca] + disFromRoot[j] - disFromRoot[lca];
}

void clearMem(){
	REP(i, PSIZE + 5){
		children[i].clear();
		disx[i].clear();
		l[i] = 0;
		parentOf[i] = -1;
		disFromRoot[i] = INF;
	}
}

inline void run() {
	scanf("%d", &n);
	if (n == 0) return stop();
	clearMem();

	int v, d;
	REP(i, n - 1){
		scanf("%d %d", &v, &d);
		children[v].PB(i + 1);
		disx[v].PB(d);
		parentOf[i + 1] = v;
	}

	dfs(0, 1, 0);
	buildDP();

	int nQuery, first, second;
	scanf("%d", &nQuery);
	REP(i, nQuery){
		scanf("%d %d", &first, &second);
		//cout << getDis(first, second);
		printf("%I64d", getDis(first, second));
		if (i != nQuery - 1) printf(" ");
	}
	printf("\n");
}
