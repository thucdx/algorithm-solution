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
typedef long double ld;
typedef pair<int, int> pii;

const int INF = (int) 1E9 + 5;
const ld EPS = (ld) 1E-8;
const ll MOD = (ll) 1E9 + 7;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

inline void init() {
	ntest = INF;
}

const int MAXN = 505;
const int MAXM = 55;

struct Point {
	double x, y, z;

	Point() {
	}

	Point(double _x, double _y, double _z) {
		x = _x, y = _y, z = _z;
	}

	void input() {
		cin >> x >> y >> z;
	}

	void output() {
		cout << x << " " << y << " " << z << endl;
	}

	double getVectorLength() {
		return x * x + y * y + z * z;
	}
};

int n, m;
Point star[MAXN], tele[MAXM];
double phi[MAXM];
bool seen[MAXN];

inline double getAngle(Point &a, Point &b) {
	double mul = a.x * b.x + a.y * b.y + a.z * b.z;
	double side_one = sqrt(a.getVectorLength());
	double side_two = sqrt(b.getVectorLength());
	return acos(mul / side_one / side_two);
}

inline void run() {
	cin >> n;
	if (n == 0) {
		return stop();
	}
	REP(i, n) {
		star[i].input();
	}
	cin >> m;
	REP(i, m) {
		tele[i].input();
		cin >> phi[i];
	}

	SET(seen, false);

	int cnt = 0;
	REP(i, m) {
		REP(j, n) {
			if (seen[j]) {
				continue;
			}
			double angle = getAngle(tele[i], star[j]);
			if (angle >= -EPS && angle <= phi[i] + EPS) {
				seen[j] = true;
				cnt++;
				break;
			}
		}
	}

	cout << cnt << endl;
}
