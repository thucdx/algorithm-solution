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
	cin >> ntest;
}

int prime[] = {2, 3, 5, 7, 11, 13, 19 , 23, 29, 31};

ll ans;
int soUoc;

void dfs(int i, ll x, int uoc){
	if (uoc > soUoc) return;
	if (x > 1e6) return;

	if (uoc == soUoc && x < ans) ans = x;

	FOR(j, 1, 20){
		if (ans / prime[i] < x) break;
		x *= prime[i];
		if (soUoc % (j + 1) == 0){
			dfs(i + 1, x, uoc * (j + 1));
		}
	}
}

ll find(int k){
	soUoc = k;
	ans = 1e18 + 5;
	dfs(0, 1, 1);
	return ans;
}

inline void run() {
	int n;
	cin >> n;

	ll ans1 = find(2 * n - 1);
	ll ans2 = find(2 * n);

	if (min(ans1, ans2) > (int)(1e6)){
		puts("Too big");
	}
	//else printf("%ld\n", min(ans1, ans2));
	else cout << min(ans1, ans2) << endl;
}
