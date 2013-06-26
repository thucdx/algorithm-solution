// Created : 1:51:54 PM Oct 21, 2012
// Task    : C

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

#define DEBUG(x) cout << #x << " = "; cout << x << endl; // thank RR for that
#define PR(a,n) cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl;
#define PR0(a,n) cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl;

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

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

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

inline void init() {
	ntest = 1;
}

inline ll lcm(ll a, ll b, ll c){
	ll d = lcm (a , b);
	return lcm(d, c);
}

inline void run() {
	ll n;
	ll ret;

	cin >> n;
	switch(n){
	case 1: ret = 1; break;
	case 2 : ret = 2; break;
	case 3 : ret = 6; break;
	case 4 : ret = 12; break;
	default:
		if (n % 2 == 1){
			ret = n * (n - 1) * (n - 2); /// nguyen to cung nhau
		}
		else {
			ret = (n - 1) * (n - 2) * (n - 3);
			for (int i = 1; i < n - 1; ++i){
				ll cur = lcm(i , n , n - 1);
				if (cur > ret) ret = cur;

				ll cur2 = lcm(i, n , n - 3);
				if (cur2 > ret) ret = cur2;
			}
		}

		break;
	}

	cout << ret ;
}
