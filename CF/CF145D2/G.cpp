// Created : 5:08:16 AM Oct 18, 2012
// Task    : 234G

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

vector< vector<int> > first;

int n;

inline void arrange(int day, int start, int end){
	while (SZ(first) < day) first.PB( vector<int>());
	if (end - start <= 1){
		first[day - 1].PB(start);
		return;
	}

	int mid = (start + end) / 2;
	FOR(i, start, mid){
		first[day - 1].PB(i);
	}

	arrange(day + 1, start, mid);
	arrange(day + 1, mid + 1, end);
}

int main() {
//#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//#endif
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
	cin >> n;
	arrange(1, 1, n);

	cout << SZ(first) << endl;
	REP(i, SZ(first)){
		cout << SZ(first[i]);
		REP(j, SZ(first[i]))
			cout << " " << first[i][j];
		cout << endl;
	}
}
