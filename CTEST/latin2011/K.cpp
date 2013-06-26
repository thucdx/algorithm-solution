// Created : 2:34:58 PM Oct 23, 2012
// Task    : K

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

struct Hand {
	int a[3];
	int x, y, z;
	int rank;
	void init(int _x, int _y, int _z) {
		x = _x, y = _y, z = _z;
		a[0] = x, a[1] = y, a[2] = z;
		sort(a, a + 3, greater<int>());
		if (a[0] == a[1] && a[1] == a[2]) {
			rank = 3;
			a[1] = a[2] = -1;
		} else if (a[0] == a[1]) {
			rank = 2;
			a[1] = a[2], a[2] = -1;
		} else if (a[1] == a[2]) {
			rank = 2;
			a[1] = a[0], a[0] = a[2], a[2] = -1;
		} else {
			rank = 1;
		}
	}
	bool operator < (const Hand &o) const {
		if (rank != o.rank) {
			return rank < o.rank;
		}
		REP(i, 3) {
			if (a[i] != o.a[i]) {
				return a[i] < o.a[i];
			}
		}
		return false;
	}
	void print() {
		int w[3];
		w[0] = x, w[1] = y, w[2] = z;
		sort(w, w + 3);
		printf("%d %d %d\n", w[0], w[1], w[2]);
	}
};

int cnt;
Hand h[505];

inline void init() {
	ntest = INF;
	cnt = 0;
	FOR(x, 1, 13) {
		FOR(y, x, 13) {
			FOR(z, y, 13) {
				h[cnt].init(x, y, z);
				cnt++;
			}
		}
	}
	sort(h, h + cnt);
}

inline void run() {
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	if (x == 0) {
		return stop();
	}

	Hand curr;
	curr.init(x, y, z);

	bool found = 0;
	REP(i, cnt) {
		if (!(curr < h[i]) && !(h[i] < curr)) {
			found = 1;
			continue;
		}
		if (found == 1 && h[i].rank >= 2) {
			h[i].print();
			return;
		}
	}
	puts("*");
}
