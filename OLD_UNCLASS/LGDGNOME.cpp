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
int a[15][1005];
int n, m;
int f[1005];
int first[1005];

inline void init() {
	ntest = 1;
}

inline void run() {
	scanf("%d %d", &n, &m);
	int val;
	REP(i, n){
		scanf("%d", &first[i]);
		first[i]--;
	}

	FOR(j, 1, m - 1){
		REP(i, n){
			scanf("%d", &val);
			a[j][val - 1] = i;
		}
	}

	int ret = -1;
	f[0] = 1;
	for(int i = 1; i < n; ++i){
		for (int j = 0; j < i ; ++j){
			if (f[j] + 1 <= f[i]) continue;
			bool isOk = true;
			for (int k = 1; k < m; k++){
				if (a[k][first[j]] > a[k][first[i]]){
					isOk = false;
					break;
				}
			}
			if (isOk && f[j] + 1 > f[i]) f[i] = f[j] + 1;
		}
		if (f[i] < 1) f[i] = 1;
		if (f[i] > ret ) ret = f[i];
	}
	printf("%d", ret);
}

