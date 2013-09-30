//Cho day do dai n <= 100.000. Value <= 10^6
// Tim day con dai nhat ma 2 phan tu lien tiep co abs value <= k.

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

int n, k;
const int PSIZE = (int)(1e6);

int it[4 * PSIZE + 10];

void update(int i, int k, int l, int id, int val){
	if (k > l) return;
	if (k > id || l < id) return;

	if (k == l && l == id){
		if (it[i] < val) it[i] = val;
		return;
	}

	int mid = (k + l) / 2;
	update(2 * i , k, mid, id, val);
	update(2 * i + 1, mid + 1, l, id, val);

	it[i] = max (it[2 *i], it[2 * i + 1]);
}

int get(int i, int b, int e, int x, int y){
	int ret = 0;

	if (e < x || b > y) return 0;
	if (x <= b && e <= y){
		if (ret < it[i]) ret = it[i];
		return ret;
	}

	int mid = (b + e) / 2;
	int first = get(2 * i, b , mid , x , y);
	int second = get(2 * i + 1, mid + 1, e, x, y);

	if (ret < first) ret = first;
	if (ret < second) ret = second;

	return ret;
}

inline void run() {
	scanf("%d %d", &n, &k);
	int ret = -1, val;

	REP(i, n){
		scanf("%d", &val);

		int first = max(val - k, 1);
		int second = min(val + k, PSIZE);

		int longest = get(1, 1, PSIZE, first, second) + 1;
		if (longest > ret) ret = longest;
		update(1, 1, PSIZE, val, longest);
	}

	cout << ret ;
}
