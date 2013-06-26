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
const ld EPS = (ld) 1E-8;
const ll MOD = (ll) 1E9 + 7;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

int n, k;
vector<int> prime;
ll memo[1200][20][200];

inline bool isPrime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

inline void init() {
	ntest = INF;
	prime.PB(0);
	prime.PB(2);
	for (int i = 3; i < 1200; i += 2) {
		if (isPrime(i)) {
			prime.PB(i);
		}
	}
	SET(memo, -1);
}

ll numWay(int n, int k, int last) {
	if (k == 0) {
		if (n == 0) {
			return 1L;
		}
		return 0L;
	}

	ll &ret = memo[n][k][last];
	if (ret >= 0) {
		return ret;
	}
	ret = 0;
	FOR(i, last + 1, SZ(prime) - 1) {
		if (prime[i] <= n) {
			ret += numWay(n - prime[i], k - 1, i);
		}
	}
	return ret;
}

inline void run() {
	cin >> n >> k;
	if (n == 0 && k == 0) {
		return stop();
	}
	cout << numWay(n, k, 0) << endl;
}
