// Created : 11:59:35 AM Oct 22, 2012
// Task    : C

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

const double PI = 4 * atan(1);
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

inline void init() {
	ntest = INF;
}

inline bool dcmp(ld a, ld b){
	if (fabsl(a - b) < 1e-11) return 0;
	if ( a < b) return -1;
	return 1;
}

int x[105], y[105];

inline int ccw(int t, int i, int j){
	int dxi = x[t] - x[i];
	int dyi = y[t] - y[i];

	int dxj = x[t] - x[j];
	int dyj = y[t] - y[j];

	int val = dxi * dyj - dxj * dyi;
	if (val == 0) return 0;
	if (val < 0) return -1;
	return 1;
}

inline ld sqr(ld a){
	return a * a;
}

inline ld dis(int i, int j){
	int dx = x[i] - x[j];
	int dy = y[i] - y[j];

	return sqrt(sqr(dx) + sqr(dy));
}

inline ld goc(int t, int i, int j){
	int xi = x[t] - x[i];
	int yi = y[t] - y[i];

	int xj = x[t] - x[j];
	int yj = y[t] - y[j];

	ld val = xi * xj + yj * yi;

	return acos(val / dis(i, t) / dis(j, t));
}

inline void run() {
	int n;
	cin >> n;
	if (n == 0) return stop();

	REP(i, n){
		scanf("%d %d", &x[i], &y[i]);
	}

	int ret = min(2, n);

	REP(i, n){
		FOR(j, i + 1, n - 1){

			vector<ld> slope;
			REP(t, n){
				if ((t == i) || (t == j)) continue;
				int cc = ccw(t, i, j);
				if (cc == 0) continue;

				ld g = goc(t, i, j);
				if (cc < 0) g = PI - g;
				slope.PB(g);
			}

			sort(ALL(slope));
			int maxLeng = 2;
			int cur = 2 + (slope.size() > 1);

			FOR(i, 1, SZ(slope) - 1){
				if (dcmp(slope[i], slope[i - 1]) == 0){
					cur ++;
				}
				else {
					if (cur > maxLeng) maxLeng = cur;
					cur = 3;
				}
			}
			if (cur > maxLeng) maxLeng = cur;

			if (maxLeng > ret) ret = maxLeng;
		}
	}

	cout << ret << endl;
}
