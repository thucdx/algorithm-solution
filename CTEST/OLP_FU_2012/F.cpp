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
	scanf("%d\n", &ntest);
}

const int MAXN = 105;

struct Rect {
	int top, bottom, left, right;
	Rect() {
	}
	Rect(int _bottom, int _top, int _left, int _right) {
		bottom = _bottom, top = _top, left = _left, right = _right;
	}
};

int a, b;
vector<int> ngang, doc;

bool isEqual(Rect &a, Rect &b) {
	return (a.bottom == b.bottom && a.top == b.top && a.left == b.left
			&& a.right == b.right);
}

int getValue(Rect &x, Rect &a) {
	if (x.bottom > a.top || x.top < a.bottom || x.left > a.right || x.right
			< a.left) {
		return 1;
	}
	Rect joint(max(x.bottom, a.bottom), min(x.top, a.top), max(x.left, a.left),
			min(x.right, a.right));
	if (isEqual(x, joint)) {
		return 0;
	}
	if ((x.bottom == joint.bottom && x.top == joint.top && x.left < joint.left
			&& x.right > joint.right) || (x.bottom < joint.bottom && x.top
			> joint.top && x.left == joint.left && x.right == joint.right)) {
		return 2;
	}
	return 1;
}

inline void run() {
	scanf("%d%d\n", &a, &b);

	int x;
	string s;

	ngang.clear();
	doc.clear();

	getline(cin, s);
	istringstream is1(s);
	while (is1 >> x) {
		if (x > -a && x < a) {
			ngang.PB(x);
		}
	}
	ngang.PB(-a);
	ngang.PB(a);
	UNIQUE(ngang);

	getline(cin, s);
	istringstream is2(s);
	while (is2 >> x) {
		if (x > -a && x < a) {
			doc.PB(x);
		}
	}
	doc.PB(-a);
	doc.PB(a);
	UNIQUE(doc);

	Rect SMALL_SQUARE(-b, b, -b, b);

	int cnt = 0;
	FOR(i, 0, SZ(ngang) - 2) {
		FOR(j, 0, SZ(doc) - 2) {
			Rect piece(ngang[i], ngang[i + 1], doc[j], doc[j + 1]);
			cnt += getValue(piece, SMALL_SQUARE);
		}
	}
	printf("%d\n", cnt);
}
