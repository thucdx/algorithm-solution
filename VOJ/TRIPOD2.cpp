#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define DOW(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define REP(i, a) for (int i = 0; i < a; ++i)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

#define dbg(x) cout << #x << " = " << x << endl
#define ok(x) cout << "[OK @ " << x << " ]" << endl
#define sz(x) x.size()
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

const double EPS = 1e-6;
const double INF = 1e50;

struct Point {
	double x, y;
	Point() {}
	Point(double _x, double _y) : x(_x), y(_y) {}
	bool operator<(const Point& other) const {
		if (x != other.x) return x < other.x;
		return y < other.y;
	}
	Point operator-(const Point& other) const {
		return Point(x - other.x, y - other.y);
	}

	Point operator+(const Point& other) const {
		return Point(x + other.x, y + other.y);
	}
} p[100005];

inline int cmp(ld a, ld b) {
	if (fabs(a - b) < EPS) return 0;
	return a > b ? 1 : -1;
}

bool cmpY(const Point& a, const Point& b) {
	if (b.y != a.y) return a.y < b.y;
	return a.x < b.x;
}

inline int ccw(Point& a, Point& b, Point& c) {
	ld v1x = b.x - a.x, v1y = b.y - a.y;
	ld v2x = c.x - b.x, v2y = c.y - b.y;
	return cmp(v1x * v2y - v2x * v1y, 0);
}

inline ld getArea(Point& a, Point& b, Point& c) {
	ld v1x = b.x - a.x, v1y = b.y - a.y, v2x = c.x - a.x, v2y = c.y - a.y;
	return 0.5 * fabsl(v1x * v2y - v1y * v2x);
}

inline ld sqr(ld x) {
	return x * x;
}

inline ld getLength(Point a) {
	return sqrt(sqr(a.x) + sqr(a.y));
}

inline ld getDist(Point a, Point b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

inline ld getRadius(ld a, ld b, ld c) {
	ld sa = a * a, sb = b * b, sc = c * c;
	if (sa >= sb + sc) return a / 2;
	if (sb >= sa + sc) return b / 2;
	if (sc >= sb + sa) return c / 2;
	ld p = (a + b + c) / 2, s = sqrtl(p * (p - a) * (p - b) * (p - c));
	return a * b * c / (4 * s);
}

inline ld getRadius(Point& a, Point& b, Point& c) {
	return getRadius(getDist(a, b), getDist(b, c), getDist(c, a));
}

ld res;

void go(int l, int r) {
	if (r - l == 1) return;
	if (r - l == 2) {
		res = min(res, getRadius(p[l], p[l + 1], p[l + 2]));
		return;
	}

	int m = (l + r) / 2;
	go(l, m); go(m + 1, r);

	vector<Point> a;
	ld twoRes = 2 * res;
	for (int i = m; i >= l && p[m].x - twoRes <= p[i].x; --i) a.pb(p[i]);
	for (int i = m + 1; i <= r && p[m].x + twoRes >= p[i].x; ++i) a.pb(p[i]);

	sort(a.begin(), a.end(), cmpY);

	int la = a.size();
	for (int i = 0; i < la; ++i)
		for (int j = i + 1; j < la && a[j].y - a[i].y <= twoRes; ++j)
			for (int k = j + 1; k < la && a[k].y - a[j].y <= twoRes; ++k) {
				res = min(res, getRadius(a[i], a[j], a[k]));
			}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	REP(i, n) scanf("%lf %lf", &p[i].x, &p[i].y);

	sort(p, p + n);
	res = 1e100;
	go(0, n - 1);
	printf("%.5lf\n", (double)res);
}

