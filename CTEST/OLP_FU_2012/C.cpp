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
	scanf("%d", &ntest);
}

const int MAXN = 105;

int n, m, a, b;
vector<pii> e[MAXN];
int limit[MAXN];

inline void run() {
	scanf("%d%d%d%d", &n, &m, &a, &b);
	int x, y, h;
	FOR(i, 1, n) {
		e[i].clear();
	}
	REP(i, m) {
		scanf("%d%d%d", &x, &y, &h);
		e[x].PB(MP(h, y));
		e[y].PB(MP(h, x));
	}
	FOR(i, 1, n) {
		GSORT(e[i]);
		limit[i] = 0;
	}
//	vector<pii> heap;
	set<pii, greater<pii> > heap;
//	heap.PB(MP(INF, a));
//	make_heap(heap.begin(), heap.end());
	heap.insert(MP(INF, a));
	limit[a] = INF;
	while (!heap.empty()) {
//		pii top = heap.front();
//		heap.pop_back();
//		pop_heap(heap.begin(), heap.end());
		pii top = *heap.begin();
		heap.erase(heap.begin());
		int u = top.S;
		int h = top.F;
		if (u == b) {
			break;
		}
		if (h < limit[u]) {
			continue;
		}
		FIT(it, e[u]) {
			int nextH = min(h, it->F);
			if (nextH <= limit[it->S]) {
				continue;
			}
			limit[it->S] = nextH;
//			heap.PB(MP(nextH, it->S));
//			push_heap(heap.begin(), heap.end());
			heap.insert(MP(nextH, it->S));
		}
	}
	cout << limit[b] << endl;
}
