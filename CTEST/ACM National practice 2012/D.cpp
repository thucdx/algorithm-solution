// Created : 9:56:00 AM Oct 22, 2012
// Task    : D

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


int ntest = 0, test = 0;
inline void init();
inline void run();
inline void stop() {
	ntest = test - 1;
}
const int ARRMAX = (int)1e5;

vector<int> f[ARRMAX + 5];
map<int, vector<int> >  m;

void split(int n, int& a, int& b, int& t){
	b = 0;
	a = 1;
	int _n = n;
	while (n > 9){
		a *= 10;
		n /= 10;
	}
	b = _n - a * n;
	t = n;
	a *= t;
}

vector<int> find(int n){
	if (n <= ARRMAX) // calc ARRMAX
		return f[n];

	vi ret(10, 0);

	int a, b, c;
	split(n, a, b, c);
	vi fb = find(b);
	REP(i, 10) ret[i] = fb[i];
	ret[c] += b + 1;

	int sumDig = 0;
	REP(i, 10) sumDig += fb[i];

	int nDig = log10(a);
	ret[0] += (int)nDig * (b + 1) - sumDig;

	vi t;
	if (m.count(a - 1) > 0)
		t = m[a-1];
	else t = find(a - 1);

	REP(i, 10) ret[i] += t[i];
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	while (++test <= ntest) {
		run();
	}
	return 0;
}

inline void init() {
	ntest = INF;

	for(int i = 0; i <= ARRMAX; ++i)
		f[i] = vector<int>(10, 0);

	f[0][0] = 1;
	for(int i = 1; i <= ARRMAX; ++i){
		int n = i;

		REP(j, 10) f[i][j] = f[i - 1][j];
		do{
			int dig = n % 10;
			f[i][dig]++;
			n /= 10;
		}
		while (n != 0);
	}

	int s = 9;
	while (s < 1e8 + 5){
		if (s <= ARRMAX){
			m[s] = f[s];
		}
		else {
			m[s] = find(s);
		}
		s = s * 10 + 9;
	}
}

inline void run(){
	int n, m;
	scanf("%d %d",&n, &m);
	if (n == 0) return stop();
	vi low = find(n - 1);
	vi hi = find(m);
	REP(i, 10){
		cout << hi[i] - low[i];
		if (i != 9) printf(" ");
	}
	printf("\n");
}
