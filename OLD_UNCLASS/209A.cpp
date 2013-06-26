// Created : 2:41:51 PM Oct 20, 2012
// Task    : 209A

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

ll f[(int)(1e6) + 5][2];

inline void init() {
	ntest = 1;
	// red, blue, red
	// 0 : last red, 1 : last blue

	f[1][0] = 1; f[1][1] = 0;
	FOR(i, 2, (int)(1e6) ){
		if (i % 2) { // red
			f[i][0] = 1 + f[i - 1][1] + f[i - 1][0];
			f[i][1] = f[i - 1][1];
		}
		else {
			f[i][0] = f[i - 1][0];
			f[i][1] = 1 + f[i - 1][0] + f[i - 1][1];
		}

		if (f[i][0] > MOD) f[i][0] %= MOD;
		if (f[i][1] > MOD) f[i][1] %= MOD;
	}
}

inline void run() {
	int n;
	cin >> n;
	cout << (f[n][0] + f[n][1] ) % MOD;
}
