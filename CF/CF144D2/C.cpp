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

string g[105];

inline void run() {
	int n, k;
	cin >> k;

	int t;
	for (t = 100; t >= 0; --t){
		int total = t * (t - 1) * (t-2) / 6;
		if (total <= k)
		{
			k -= total;
			break;
		}
	}
	vector<int> addMore;

	while (k != 0){
		for (int m = t + 1; m >= 0; --m){
			if ( m * (m-1)/ 2 <= k){
				k -= m * (m - 1) /2;
				addMore.PB(m);
				break;
			}
		}
	}

	n = t + addMore.size();

	REP(i, n){
		REP(j, n)
				g[i].PB('0');
	}

	REP(i, t) REP(j, t) g[i][j] = '0' + (i != j);

	REP(i, SZ(addMore)){
		int moreVer = addMore[i];
		REP(j, moreVer)
				g[t + i][j] = g[j][t + i] = '1';
	}
	cout << n << endl;
	REP(i, n) {
		REP(j, n) printf("%c", g[i][j]);
		puts("");
	}


}
