// [TIMXAD] ~ [Rhombs] @ [Sep 4, 2013]
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cassert>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define DOW(i, A, a) for (int i = (A), _a = (a); i >= _a; --i)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

#define dbg(x) cout << #x << " = " << x << endl
#define ok() cout << "@OK!" << endl
#define pb push_back
#define mp make_pair
#define sz(a) (int) a.size()
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int C = 50;

struct Point {
	int x, y;
	Point() {x = y = 0;}
	Point(int _x, int _y) {
		x = _x, y = _y;
	}

	bool operator==(const Point& other) const {
		return x == other.x && y == other.y;
	}

	bool operator!=(const Point& other) const {
		return x != other.x || y != other.y;
	}

	bool operator<(const Point& other) const {
		if (x != other.x) return x < other.x;
		return y < other.y;
	}

	void show() {
		printf("{%2d %2d} ", x, y);
	}
};

struct Rect {
	Point p[4];
	Rect() {}
	Rect(Point a, Point b, Point c, Point d) {
		p[0] = a, p[1] = b, p[2] = c, p[3] = d;
		sort(p, p + 4);
	}

	bool operator<(const Rect& other) const {
		REP(i, 4) if (p[i] != other.p[i]) return p[i] < other.p[i];
		return false;
	}

	bool operator==(const Rect& other) const {
		REP(i, 4) if (p[i] != other.p[i]) return false;
		return true;
	}

	bool operator!=(const Rect& other) const {
		REP(i, 4) if (p[i] != other.p[i]) return true;
		return false;
	}
};

vector<pair<int, int> > s[20005];
int exist[105][105], n;
Point p[1505];

inline int sqr(int x) { return x * x; }

void init() {
	for (int i = 1; i <= 100; ++i) {
		int ii = i * i;
		for (int j = 1; j <= 100; ++j) {
			int sum = ii + j * j;
			s[sum].pb(make_pair(i, j));
			s[sum].pb(make_pair(i, -j));
			s[sum].pb(make_pair(-i, -j));
			s[sum].pb(make_pair(-i, j));
		}
	}

	for (int j = 1; j <= 100; ++j) {
		int sum = j * j;
		s[sum].pb(make_pair(0, j));
		s[sum].pb(make_pair(0, -j));
		s[sum].pb(make_pair(j, 0));
		s[sum].pb(make_pair(-j, 0));
	}
}

inline int count(int x, int y) {
	x += C, y += C;
	return (0 <= x && x <= 100 && 0 <= y && y <= 100) ? exist[x][y] : 0;
}

inline int count(Point a) { return count(a.x, a.y); }

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

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	init();
	gi(n);
	REP(i, n) {
		gi(p[i].x), gi(p[i].y);
		++exist[p[i].x + C][p[i].y + C];
	}

	ll total = 0;
	Point n1, n2;

	sort(p, p + n);

	REP(i, n) FOR(j, i + 1, n - 1) {
		if (p[i] == p[j]) continue;
		int ds = sqr(p[i].x - p[j].x) + sqr(p[i].y - p[j].y);
		pair<int, int> cur;

		FIT(it, s[ds]) {
			cur = *it;
			int x = cur.first, y = cur.second;
			n1 = Point(p[i].x + x, p[i].y + y);
			if (n1 == p[j]) continue;
			n2 = Point(p[j].x + x, p[j].y + y);
			if (n2 == p[i]) continue;
			total += count(n1) * count(n2);
		}
	}

	cout << total / 4 << endl;
}
