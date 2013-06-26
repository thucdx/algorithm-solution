// Created : 3:28:56 PM Oct 17, 2012
// Task    : 217B

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

struct step{
	int totalStep;
	int mistakeStep;

	step(int t = 0, int m = 0){
		totalStep = t;
		mistakeStep = m;
	}
};


inline step countStep(int a, int b){
	//cout << a << " " << b << endl;

	if (a == 0){
		return (b == 1) ? step(0, 0) : step(INF, INF);
	}
	if (b == 0 && a != 0) return step(INF, INF);

	int moreMistakeStep = 0;
	step prev;
	if (a < b){
		prev = countStep(a, b - a);
		moreMistakeStep = (a < b - a);
	}
	else // a >= b
	{
		prev = countStep(a - b, b);
		moreMistakeStep = (a - b >= b);
	}

	return step(prev.totalStep + 1, prev.mistakeStep + moreMistakeStep);
}

inline string printStep(int a, int b, int n){
	string ret = "";
	while (a != 0){
		if (a < b){
			ret.PB('B');
			b = b - a;
		}
		else { // a >= b
			ret.PB('T');
			a = a - b;
		}
	}

	string result = "";
	FORD(i, SZ(ret) - 1, 0){
		result.PB(ret[i]);
	}
	return result;
}

int main() {
#ifdef LOCAL
	freopen("input.txt" ,"r", stdin);
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

inline void run() {
	int n, r;
	cin >> n >> r;
	int bestTop, bestBottom, minMistake = INF;

	FOR(i, 1, r){
		step curOne = countStep(i, r);
		step curTwo = countStep(r, i);
		if (curOne.totalStep == n && curOne.mistakeStep < minMistake){
			minMistake = curOne.mistakeStep;
			bestTop = i, bestBottom = r;
		}

		if (curTwo.totalStep == n && curTwo.mistakeStep < minMistake){
			minMistake = curTwo.mistakeStep;
			bestTop = r, bestBottom = i;
		}
	}

	//cout << bestTop << "  " << bestBottom << endl;

	if (minMistake >= INF) cout << "IMPOSSIBLE";
	else {
		cout << minMistake << endl << printStep(bestTop, bestBottom, n);
	}
}
