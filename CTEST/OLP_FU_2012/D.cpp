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
typedef long double ld;
typedef pair<int, int> pii;

const int INF = (int) 1E9 + 5;
const ld EPS = (ld) 1E-7;
const ll MOD = (ll) 1E9 + 7;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

inline void init() {
	scanf("%d", &ntest);
}

const int MAXN = 1000005;
const int MAXM = 1000005;

int n, m;
ld ax[MAXN], ay[MAXN];
ld bx[MAXM], by[MAXM];

inline ld sqr(ld a) {
	return (a * a);
}

inline ld sdist(ld x1, ld y1, ld x2, ld y2) {
	return (sqr(x1 - x2) + sqr(y1 - y2));
}

inline void run() {
	scanf("%d", &n);
	REP(i, n) {
		cin >> ax[i] >> ay[i];
	}

	ld OVERALL_MAX = -1;

	scanf("%d", &m);
	REP(i, m) {
		cin >> bx[i] >> by[i];

		ld MIN = INF;
		REP(j, n) {
			MIN = min(MIN, sdist(bx[i], by[i], ax[j], ay[j]));
		}
		OVERALL_MAX = max(OVERALL_MAX, MIN);
	}

	cout << setprecision(4) << fixed << sqrt(OVERALL_MAX) << endl;
}
