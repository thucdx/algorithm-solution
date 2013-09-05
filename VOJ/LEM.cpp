/*
* Who  : timxad
* Task : LEM
* Date : May 31, 2013
* Desc :
*/
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define Sort(a) sort(all(a))
#define Unique(a) Sort(a); a.resize(unique(all(a) - a.begin()))

#define For(i, a, b) for (int _b = (b), i = (a); i <= _b; ++i)
#define Ford(i, a, b) for (int _b = (b), i = (a); i >= _b; --i)
#define Rep(i, a) for (int i = 0, _a = (a); i < _a; ++i)
#define Fit(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define nl puts("") // new line
#define sp printf(" ") // space
#define ok puts("ok")
#define show(x) cout << x << endl
#define dbg(x) cout << #x << " = " << x << endl

typedef pair<int, int> II;
typedef vector<int> vi;
typedef long long ll;

const int INF		= (int) 1e9 + 5;
const ll INFL 		= (ll) 1e16 + 6;
const int MOD 		= (int) 1e9 + 7;
const double EPS 	= 1e-6;

//Fast input
const int bfsz = 1 << 16; char bf[bfsz + 5]; int rsz = 0;int ptr = 0;
char gc() { if (rsz <= 0) { ptr = 0; rsz = fread(bf, 1, bfsz, stdin); if (rsz <= 0) return EOF; } --rsz; return bf[ptr++]; }
void ga(char &c) { c = EOF; while (!isalpha(c)) c = gc(); }
int gs(char s[]) { int l = 0; char c = gc(); while (isspace(c)) c = gc(); while (c != EOF && !isspace(c)) { s[l++] = c; c = gc(); } s[l] = '\0'; return l; }
template<class T> bool gi(T &v) {
v = 0; char c = gc(); while (c != EOF && c != '-' && !isdigit(c)) c = gc(); if (c == EOF) return false; bool neg = c == '-'; if (neg) c = gc();
while (isdigit(c)) { v = v * 10 + c - '0'; c = gc(); } if (neg) v = -v; return true;
}
//End of fast input

struct Point {
	int x, y;
	Point() { x = y = 0; }
	void read() {
		gi(x), gi(y);
	}
} a[1005], b[1005];

inline double sqr(double a) {
	return a * a;
}

inline double sqrDist(Point& a, Point& b) {
	return sqr(b.y - a.y) + sqr(b.x - a.x);
}

inline double dist(Point& a, Point& b) {
	return sqrt(sqr(b.y - a.y) + sqr(b.x - a.x));
}

inline int cmp(double a, double b) {
	if (fabs(a - b) < 1e-6) return 0;
	return a > b ? 1 : -1;
}

inline double dist(Point& a, Point& b, Point& c) {
	double ab = sqrDist(a, b), ac = sqrDist(a, c), bc = sqrDist(b, c);
	double d = (ab + ac + bc) / 2;
	if (cmp(ab, d) >= 0 || cmp(ac, d) >= 0) {
		return sqrt(min(ab, ac));
	}

	return fabs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)) / sqrt(bc);
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	Rep(i, n) a[i].read();
	Rep(i, m) b[i].read();

	double res = 1e100, d;
	Rep(i, n) Rep(j, m - 1) {
		d = dist(a[i], b[j], b[j + 1]);
		if (res > d) res = d;
	}

	Rep(i, m) Rep(j, n - 1) {
		d = dist(b[i], a[j], a[j + 1]);
		if (res > d) res = d;
	}

	printf("%.3lf\n", (double)res);
}


