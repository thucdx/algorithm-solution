// Created : 3:51:36 PM Oct 20, 2012
// Task    : 198C

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

#define DEBUG(x) cout << #x << " = "; cout << x << endl;
#define PR(a,n) cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl;
#define PR0(a,n) cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

const long double PI = acos((ld) -1);   // d / ld ?
const int INF = (int) 1E9 + 5;  // enough ?
const double EPS = 1E-11;      // relevant ?
const ll MOD = (ll) 1E9 + 7;  // problem's mod ?


int ntest = 0, test = 0;
inline void init();
inline void run();
inline void stop() {
	ntest = test - 1;
}
bool exist = false;

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


inline int dcmp(ld a, ld b){
	if (fabs(a - b) < EPS) return 0;
	if (a < b) return -1;
	return 1;
}

ld xp, yp, vp;
ld x, y, v, r;

ld RP, vAngle, initAngle;
const ld TWO_PI = 2 * PI;

inline ld mod(ld angle){
	angle -= ((ll)(angle / (TWO_PI))) * (TWO_PI);
	while (angle >= TWO_PI) angle -= TWO_PI;
	while (angle < 0)  angle += TWO_PI;
	return angle;
}

inline void getPosition(ld t, ld &x, ld &y){ // start from vp, yp, move vp
	ld angle = t * vAngle + initAngle;
	angle = mod(angle);

	x = cos(angle) * RP;
	y = sin(angle) * RP;
}

inline ld distance(ld x1, ld y1, ld x2, ld y2){
	ld dx = x1 - x2;
	ld dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}

inline ld getAngle(ld a, ld b, ld oposite){
	return acos((a * a + b * b - oposite * oposite ) / (2 * a * b));
}

inline ld getLeng(ld a, ld b, ld angle){
	return sqrt(a * a + b * b - 2 * a * b * cos(angle));
}

inline bool isOk(ld t){
	ld tx , ty;

	getPosition(t, tx, ty);
	//cout << "t = " << t << " tx = " << tx << " ty =  " << ty << endl;

	ld ab = distance(x, y, tx, ty);
	ld oa = sqrt(x * x + y * y);
	ld ob = sqrt(tx * tx + ty * ty);
	ld h = fabs(x * ty - y * tx) / ab;

	ld oab = getAngle(oa, ab, ob);
	ld oba = getAngle(ob, ab, oa);

	ld pathleng;
	//cout << fabs(x * ty - y * tx) << endl;
	//cout << "ab oa ob: " << ab << " " << oa << " " << ob << endl;
	//cout << "h oab oba : " << h << " " << oab << " " << oba << endl;
	if (dcmp(h, r) <= 0 && dcmp(oab, PI/2) <= 0 && dcmp(oba, PI/2) <= 0){
		//cout << "a cut" << endl;
		// cut
		ld ac = sqrt(x * x + y * y - r * r);
		ld bd = sqrt(tx * tx + ty * ty - r * r);
		ld aob = getAngle(oa, ob, ab);
		ld aoc = getAngle(oa, r, ac);
		assert(dcmp(aoc, acos(r/oa)) == 0);

		ld bod = getAngle(ob, r, bd);
		assert(dcmp(bod, acos(r/ob)) == 0);

		//cout << aob << " "<< aoc << " " << bod << endl;
		assert(dcmp(aob, aoc + bod) >= 0);

		ld cod = aob - aoc - bod;
		pathleng = ac + bd + cod * r;
	}
	else {
		//cout << "not cut" << endl;
		pathleng = ab;
	}

	return dcmp(pathleng, t * v) <= 0;
}

inline double toRadian(double degree){
	return degree / 180 * PI;
}

inline double toDegree(double radian){
	return radian / PI * 180;
}

inline void run() {
	cin >> xp >> yp >> vp;
	cin >> x >> y >> v >> r;

	RP = sqrt(xp * xp + yp * yp);
	vAngle = vp / RP; // t / (2PI * r) * 2PI/r = 2PU
	initAngle = atan2(yp, xp);

	if (dcmp(xp, x ) == 0 && dcmp(yp, y) == 0){
		cout << 0;
		return;
	}
	//cout << initAngle << endl;

	ld lowT = 0, hiT = 3 * 1e4 + 5;

	REP(step, 1000){
		ld mid = (lowT + hiT) / 2;
		bool ret = isOk (mid);
		if (ret) hiT = mid;
		else lowT = mid;
	}

	cout << setprecision(12) << lowT << endl;
}
