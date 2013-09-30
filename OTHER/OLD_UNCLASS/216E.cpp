// Created : 5:55:23 AM Oct 18, 2012
// Task    : 216E

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

int a[100005];
ll  c[100005];

map<ll, int> cnt;
map<int, int> cntRemain; //for b = k - 1 only

inline int mod(int a, int p){
	return (a % p + p) % p;
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
	ntest = 1;
}

inline void run() {
	int k, b, n;
	scanf("%d %d %d", &k, &b, &n);
	REP(i, n){
		scanf("%d", &a[i]);
		c[i] = (i == 0) ? a[0] : c[i - 1] + a[i];
	}

	int sum = 0;
	ll total = 0;

	if (b != 0 && b != k - 1){
		REP(i, n){
			sum = mod (sum + a[i], k - 1);
			int prev = mod(sum - b, k - 1);

			total = total + cnt[prev] + (mod(sum , k - 1) == b);
			if (cnt.find(sum) != cnt.end()){
				cnt[sum]++;
			}
			else cnt[sum] = 1;
		}
	}
	else {
		if (b == 0){ // cumulative = 0
			REP(i, n){
				int tmp = cnt.find(c[i]) == cnt.end() ? 0 : cnt[c[i]];
				total += tmp;
				if (!c[i])  total++;
				++cnt[c[i]];
			}
		}
		else if (b == k - 1){
			REP(i, n){
				int equal = cnt[c[i]]++;
				int equalRemainder = cntRemain[c[i] % (k - 1)]++;

				total += equalRemainder - equal + (c[i] % (k - 1) == 0 && c[i] != 0);
			}
		}
	}

	cout << total << endl;
}
