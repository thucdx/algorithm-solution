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
	ntest = 1;
}
int color[2005];

ll power(ll a, ll b){
	ll ret = 1;
	for (; b; b >>= 1){
		if ( b & 1)
			ret = (ret * a) % MOD;
		a = (a * a ) % MOD;
	}
	return ret % MOD;
}

ll n, m, k;

void change(int oldColor, int newColor){
	FOR(i, 1, n){
		if (color[i] == oldColor){
			color[i] = newColor;
		}
	}
}

inline void run() {
	cin >> n >> m >> k;
	if (n < k || k == 1) {cout << power(m, n); return;}

	int nColor = 0;
	for (int i = 1; i <= (k + 1) / 2; i++){
		color[k + 1 - i] = color[i] = ++nColor;
	}

	for (int j = k + 1; j <= n; ++j) {
		for (int pos = j - k + 1; pos <= (k + 1)/ 2 + (j - k); ++pos){
			int doixung = j - (pos - j + k - 1);

			if (color[doixung] != 0){
				int color1 = color[doixung];
				int color2 = color[pos];
				if (color1 > color2) swap(color1, color2);
				change(color2, color1);
			}
			else color[doixung] = color[pos];
		}
	}

	set<int> s;
	FOR(i, 1, n){
		s.insert(color[i]);
	}

	cout << power(m, s.size());
}
