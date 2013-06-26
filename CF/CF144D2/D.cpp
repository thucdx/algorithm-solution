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

ll c[1005][1005];

inline void init() {
	ntest = 1;

	REP(i, 1001 ) REP(j, 1001) c[i][j] = 0;
	REP(i, 1001) c[0][i] = 1;
	FOR(i, 1, 1000) FOR(j, i, 1000){
		c[i][j] = (c[i-1][j - 1] + c[i][j - 1]);
		if (c[i][j] > MOD) c[i][j] -= MOD;
	}
}


ll power(ll x, ll n){
    if(n == 0) return 1;
    ll y = power(x, n/2);
    y = y * y % MOD;
    if(n%2 == 1) y = y * x % MOD;
    return y;
}

/*
ll power( ll a, ll b){
	//cout << a <<  "  "<< b << endl;
	ll ret = 1;
	for (; b ; b >>= 1){
		if (b & 1)
			ret = (ret * a) % MOD;
		a = (a * a) % MOD;
	}
	return ret % MOD;
}
*/

ll part[1005];
ll dp[105][10109];
ll a[1005];

inline void run() {
	ll n, m, k;
	cin >> n >> m >> k;

	REP(i, 105)
	REP(j, 10105) dp[i][j] = 0;

	dp[0][0] = 1;

	REP(i, n){
		ll p = (m - 1 - i + n) / n;
		REP(x, n + 1) a[x] = power(c[x][n], p);
		REP(j, n * n + 1){
			REP(x, n + 1){
				if (dp[i][j] > 0){
					dp[i + 1][j + x] = (dp[i + 1][j + x] + (dp[i][j] * a[x] ) % MOD );
					if (dp[i + 1][j + x] > MOD) dp[i + 1][j + x] -= MOD;
				}
			}
		}
	}

	cout << dp[n][k] << endl;
}
