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
const int PSIZE = 1e5 + 5;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

inline void init() {
	ntest = 1;
}

int a[PSIZE];
int t[PSIZE][20];
int n, query;

void initRMQ(int t[PSIZE][20], int a[PSIZE], int n){
	REP(i, n) t[i][0] = i;
	for (int j = 1; 1 << j < PSIZE; ++j){
		for (int i = 0; ((i + (1 << j)) - 1) < n; ++i){
			if (a[t[i][j - 1]] <= a[t[i + (1 << (j - 1))][j - 1]] ){
				t [i][j] = t[i][j - 1];
			}
			else t[i][j] = t[i + (1 << (j - 1))][j - 1];
		}
	}
}

long long mul(long long a, long long b, long long MOD){ // a * b % MOD

}

long long power(long long a, long long b, long long MOD){ // ( a ^ b ) % MOD)
	long long ret = 1 % MOD;
	for (; b; b >>= 1){
		if (b & 1) {
			//ret = (ret * a) % MOD;
			ret = ret * a;
			if (ret > MOD) ret %= MOD;
		}
		a = (a * a )
	}
	return ret;

	/*long long rs = 1;
	for (int i = 0; i < b; ++i){
		rs *= a;
	}
	return rs;*/
}

int getMin(int low, int high){
	int k = log2(high - low + 1);
	if (a[t[low][k]] <= a[t[high - (1 << k) + 1][k]])
		return t[low][k];
	return t[high - (1 << k) + 1][k];
}

int getMinTrivial(int low, int high){
	int id = low;
	FOR(i, low + 1, high){
		if (a[i] < a[id])
			id = i;
	}
	return id;
}

inline void run() {
	scanf("%d %d", &n, &query);

	REP(i, n){
		scanf("%d", &a[i]);
	}

	initRMQ(t, a, n);

	REP(i, query){
		int l, hi;
		scanf("%d %d", &l, &hi);
		assert(getMin(l, hi) == getMinTrivial(l, hi));
	}
	cout << "OK";
}
