// Created : 4:05:30 PM Feb 15, 2013
// Task    : SOL

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
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

const int INF = (int) 1E9 + 5;  // enough ?
const double EPS = 1E-11;      // relevant ?
const ll MOD = (ll) 1e8 + 7;  // problem's mod ?

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

string str, status;
int k;

bool isPrime(int n ){
	if (n <= 3) return n >= 2;
	if (n % 2 == 0) return false;
	int root = (int) sqrt(n);
	for (int i = 3; i <= root; i += 2){
		if (n % i == 0) return false;
	}
	return true;
}

inline void init() {
	ntest = 1;
}

int furthestIndex[1505];
ll hash[1505];
ll power[1505];

inline void run() {
	cin >> str >> status >> k;
	int len = str.length();

	REP(i, len) str[i] -= 'a';
	REP(i, 26) status[i] -= '0';

	hash[0] = str[0], power[0] = 1;

	FOR(i, 1, len - 1) {
		hash[i] = hash[i - 1] * MOD + str[i];
		power[i] = power[i - 1] * MOD;
	}

	REP(i, len){
		int countBad = 0;
		int index;
		for (index = i; index < len; ++index) {
			countBad += 1 - status[str[index]];
			if (countBad > k) break;
		}
		furthestIndex[i] = index - 1;
	}

	int result = 0;
	FOR(l, 1, len) {
		set<ll> goodString;
		for (int i = 0; i <= len - l; ++i) {
			if (furthestIndex[i] >= i + l - 1) {
				ll h ;
				h = (i == 0) ? hash[l + i - 1] : hash[l + i - 1] - hash[i - 1] * power[l];
				goodString.insert(h);
			}
		}
		result += goodString.size();
	}
	cout << result;
}
