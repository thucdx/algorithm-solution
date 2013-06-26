// Created : 3:43:04 PM Oct 23, 2012
// Task    : I

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
	ntest = INF;
}

string BRAILLE[10] = {
	".***..", "*.....",
	"*.*...", "**....",
	"**.*..", "*..*..",
	"***...", "****..",
	"*.**..", ".**..."
};

int numDigit;
char t;

inline void toBraille() {
	string s, result[3];
	getline(cin, s);
	FIT(it, s) {
		REP(i, 3) {
			result[i] += " " + BRAILLE[*it - '0'].substr(i * 2, 2);
		}
	}
	REP(i, 3) {
		result[i].erase(0, 1);
		printf("%s\n", result[i].c_str());
	}
}

inline void toLatin() {
	string s, digit[105];
	REP(i, 3) {
		getline(cin, s);
		s = " " + s;
		REP(i, numDigit) {
			digit[i] += s.substr(1, 2);
			s.erase(0, 3);
		}
	}
	REP(i, numDigit) {
		REP(d, 10) {
			if (digit[i] == BRAILLE[d]) {
				printf("%d", d);
				break;
			}
		}
	}
	puts("");
}

inline void run() {
	scanf("%d\n", &numDigit);
	if (numDigit == 0) {
		return stop();
	}
	scanf("%c\n", &t);
	if (t == 'S') {
		toBraille();
	} else {
		toLatin();
	}
}
