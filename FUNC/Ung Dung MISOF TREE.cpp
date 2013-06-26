#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <string> vs;
typedef istringstream iss;
typedef ostringstream oss;

const int INF = (int) 1E9 + 5;
const ll LINF = (ll) 4E18 + 5;

const ld PI = acos(-1.0);
const ld E = 2.718281828459045L;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, a) for (int i = 0; i < (a); i++)
#define REPD(i, a) for (int i = ((a) - 1); i >= 0; i--)
#define FIT(it, v) for (typeof((v).begin())it = (v).begin(); it != (v).end(); ++it)
#define FITD(it, v) for (typeof((v).rbegin())it = (v).rbegin(); it != (v).rend(); ++it)

#define VAR(a, b) typeof(b) a(b)
#define ALL(v) (v).begin(), (v).end()
#define SET(a, x) memset((a), (x), sizeof(a))
#define SIZE(a) ((int)(a).size())

#define EXIST(a, b) (find(ALL(a), (b)) != (a).end())
#define SORT(x) sort(ALL(x))
#define GSORT(x) sort(ALL(x), greater<typeof(*((x).begin()))>())
#define UNIQUE(v) SORT(v); (v).resize(unique(ALL(v)) - (v).begin())
#define ENUM(v) FIT(it, (v)) cout << *it << " "; cout << endl

#define PF push_front
#define PB push_back
#define MP make_pair
#define F first
#define S second

template<typename T> T gcd(T a, T b) { return (b == 0) ? abs(a) : gcd(b, a % b); }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> inline T mod(T a, T b) { return (a % b + b) % b; }
template<typename T> inline T sqr(T x) { return x * x; }

template<typename T> inline string toString(const T& x) { oss os; os << x; return os.str(); }
inline ll toInt(const string& s) { iss is(s); ll x; is >> x; return x; }
inline ld toDouble(const string& s) { iss is(s); ld x; is >> x; return x; }
inline string toLower(string s) { FIT(it, s) *it = tolower(*it); return s; }
inline string toUpper(string s) { FIT(it, s) *it = toupper(*it); return s; }

const char DEBUG_PARAM[] = "__LOCAL_TESTING";

const char IN[] = "_.in";
const char OUT[] = "_.out";

inline void init();
inline void run();

int ntest = 0, test;

int main(int argc, char* argv[]) {
	if (argc > 1 && strcmp(argv[1], DEBUG_PARAM) == 0) {
		freopen(IN, "r", stdin);
		freopen(OUT, "w", stdout);
	}
	init();
	if (ntest == 0) { puts("ntest = ?"); return 0; }
	for (test = 1; test <= ntest; test++) {
		run();
	}
	return 0;
}

inline void stop() {
	ntest = test - 1;
}

/* IMPLEMENTATION */

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

const ld EPS = 1E-9;
const ll MODULE = 1000000007LL;

inline void init() {
	ntest = 1;
}

const int MAXN = 16;
int tr[205][MAXN + 1][1 << MAXN];
void insert(int w, int x) { FOR(i, 0, MAXN) tr[w][i][x]++, x >>= 1; }
void erase(int w, int x) { FOR(i, 0, MAXN) tr[w][i][x]--, x >>= 1; }
int kThElement(int w, int k) {
	int a = 0, b = MAXN;
	while (b--) a <<= 1, k -= (tr[w][b][a] < k ? tr[w][b][a++] : 0);
	return a;
}

const int MAXK = 50005;

int n;
int prob[MAXK], user[MAXK], ti[MAXK];
double t[MAXK], whatTime[205][MAXK];
int bestTime[205][10005], currentRank[205][10005];
int numSub[205];

inline int findRank(int p, int val) {
	int left = 0, right = numSub[p];
	while (right - left > 1) {
		int mid = (left + right) >> 1;
		int x = kThElement(p, mid);
		if (val <= x) {
			right = mid;
		} else {
			left = mid;
		}
	}
	return right;
}

inline void run() {
	scanf("%d", &n);
	vector<pii> v;
	REP(i, n) {
		scanf("%d%d%lf", &prob[i], &user[i], &t[i]);
		ti[i] = (int)(t[i] * 1000 + EPS) * 50000 + i;
		v.PB(MP(ti[i], i));
	}
	SORT(v);
	REP(i, SIZE(v)) {
		ti[v[i].S] = i;
		whatTime[prob[v[i].S]][i] = t[v[i].S];
	}
	SET(bestTime, -1);
	SET(numSub, 0);
	REP(i, n) {
		int &bt = bestTime[prob[i]][user[i]];
		if (bt < 0) {
			bt = ti[i];
			insert(prob[i], bt);
			numSub[prob[i]]++;
		} else if (ti[i] >= bt) {
			puts("submission ignored");
			continue;
		} else {
			erase(prob[i], bt);
			bt = ti[i];
			insert(prob[i], bt);
		}
		int x = kThElement(prob[i], 1);
		int y = findRank(prob[i], bt);
		printf("%d %04d %.3lf %.3lf %d\n", prob[i], user[i], t[i],
				whatTime[prob[i]][x], y);
	}
}
