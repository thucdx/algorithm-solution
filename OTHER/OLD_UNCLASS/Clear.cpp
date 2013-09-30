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
typedef pair<long long, long long> pll;

const int INF = (int) 1E9 + 5;
const double EPS = 1E-11;
const ll MOD = (ll) 1E9 + 7;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

bool f[1300];

bool internalIsClearNumber(int n, int step = 0){
	if (f[n]) return true;
	if (step >= 20) return false;

	int sum = 0;
	do{
		int dig = n % 10;
		sum += dig * dig;
		n /= 10;
	}
	while ( n != 0);
	if (sum == 1) return true;
	return internalIsClearNumber(sum, ++step);
}

inline void init() {
	ntest = 1;
	f[0] = false;
	for (int i = 1; i < 1300; ++i){
		f[i] = internalIsClearNumber(i);
		if (f[i]) cout << i << endl;
	}
}

bool isClearNumber(ll n){
	if (n < 1300) return f[n];

	int sum = 0;
	do {
		int dig = n % 10;
		sum += dig * dig;
		n /= 10;
	}
	while (n != 0);
	return f[sum];
}


inline void run() {
	int cnt = 0;
}
