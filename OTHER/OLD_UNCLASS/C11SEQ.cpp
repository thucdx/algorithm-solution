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
struct Mog{
	ll value;
	int id;

	Mog(){}
	Mog(ll v, int i):value(v), id(i){}

	bool operator<(const Mog& o) const{
		if (value != o.value) return value < o.value;
		return id < o.id;
	}
	void print(){
		cout << value << " " << id << endl;
	}
};

int n, l, r;
Mog c[100005]; // sorted!
Mog a[100005];
int it[100005];

int getIDMinGreaterOrEqual(ll val){
	if (val <= c[0].value) return 0;
	if (val > c[n - 1].value) return n; // ko co


	int low = 0, hi = n - 1;
	while (hi - low > 1){
		int mid = (hi + low) / 2;
		if (c[mid].value >= val){
			hi = mid;
		}
		else low = mid + 1;
	}

	if (c[low].value >= val) return low;
	if (c[hi].value >= val) return hi;
	assert(false); // not exist;
}

int getIDMaxSmallerOrEqual(ll val){
	if (val < c[0].value) return -1; // ko co
	if (val >= c[n - 1].value) return n -1;

	int low = 0, hi = n - 1;
	while (hi - low > 1){
		int mid = (hi + low) / 2;
		if (c[mid].value <= val){
			low = mid;
		}
		else hi = mid - 1;
	}

	if (c[hi].value <= val) return hi;
	if (c[low].value <= val) return low;
	assert(false);
}

void update(int id){
	while (id <= n){
		it[id]++;
		id += id & -id;
	}
}

int getSmaller(int val){
	int sum = 0;
	while (val > 0){
		sum += it[val];
		val -= val & -val;
	}
	return sum;
}

inline void run() {
	scanf("%d %d %d", &n, &l, &r);
	ll sum = 0;
	int val;
	memset(it, 0, sizeof(it));

	REP(i, n){
		scanf("%d",&val);
		sum += val;
		c[i] = Mog(sum, i);
	}

	sort(c, c + n);

	REP(i, n){
		a[c[i].id] = Mog(c[i].value, i + 1);
	}

	ll total = 0;

	REP(i, n){
		int low = getIDMinGreaterOrEqual(a[i].value - r) + 1;
		int hi = getIDMaxSmallerOrEqual(a[i].value - l) + 1;

		if (a[i].value >= l && a[i].value <= r) total ++;

		if (low <= hi){
			total += getSmaller(hi) - getSmaller(low - 1);
		}

		update(a[i].id);
	}
	cout << total ;
}
