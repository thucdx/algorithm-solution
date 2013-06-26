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
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

const int INF = (int) 1E9 + 5;
const double EPS = 1E-11;
const ll MOD = (ll) 1E9 + 7;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

int d[(int)(1e6 + 5)];
int uoc[(int)(1e6 + 5)];
vector<int> prime;

bool isPrime(int n){
	if (n <= 3) return n >= 2;
	if ( !(n & 1)) return false;
	int lim = sqrt(n);
	for (int i = 3; i <= lim;  i += 2){
		if (n % i == 0) return false;
	}

	return true;
}

inline void init() {
	ntest = 1;
	prime.PB(2);
	for (int i = 3; i <= 1e6; i += 2 ){
		if (isPrime(i))
			prime.PB(i);
	}
	cout << "Xong prime" << endl;
}


int findD(int n){
	if (d[n] != -1) return d[n];

	int sum = 0;
	do {
		sum += n % 10;
		n /= 10;
	}
	while (n != 0);
	d[n] = findD(sum);
	return d[n];
}

int findUoc(int n){
	cout << "find Uoc " << n << endl;
	if (uoc[n] != -1 ) return uoc[n];

	if (isPrime(n)){
		return uoc[n] = 2;
	}

	int i = 0;
	while(true){
		if (n % prime[i] == 0){
			int total = 1;
			int dem = 0;
			int _n  = n;
			while (n % prime[i] == 0){
				total *= prime[i];
				dem++;
				n /= prime[i];
			}

			if (total == _n) {
				return uoc[_n] = 1 + dem;
			}
			else return uoc[_n] = findUoc(n) * findUoc(total);

		}
		++i;
	}
}

inline void run() {
	int n;

	int cnt[10];

	ll total = 0;
	cin >> n;

	fill(uoc, uoc + (int)(1e6 + 5), -1);
	uoc[1] = 1;
	fill(d + 10, d + (int)(1e6 + 5), -1);
	REP(i, 10) d[i] = i;
	memset(cnt, 0, sizeof(cnt));

	FOR(i, 1, n){
		++cnt[findD(i)];
	}

	FOR(x, 1, 9)
	FOR(y, 1, 9)
	FOR(z, 1, 9)
	if ((z == x * y) && cnt[z] != 0){
		total += ((ll)cnt[x]) * cnt[y] * (cnt[z] - 1);
	}
}
