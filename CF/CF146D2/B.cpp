// Created : 1:51:46 PM Oct 21, 2012
// Task    : B

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
const ll MOD = (ll) 1073741824;  // problem's mod ?


int ntest = 0, test = 0;
inline void init();
inline void run();
inline void stop() {
	ntest = test - 1;
}

int d[105];

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

inline int gcd(int a, int b){
	int r;
	while (b != 0){
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

inline int uocMul(int a, int b){
	int uoc = gcd(a, b);
	return d[a] / d[uoc] * d[b];
}

vector<int> prime;
vector<int> fact[105];

/*inline int uocMul(int a, int b, int c){
	// a * b * c
}*/

inline bool isPrime(ll n){
	if (n <= 3) return n >= 2;
	if (n % 2 == 0) return false;

	ll root = sqrt(n);
	for (int i = 3; i <= root; i += 2){
		if (n % i == 0) return false;
	}
	return true;
}

inline void init() {
	ntest = 1;
	REP(i, 101){
		if(isPrime(i)) prime.PB(i);
	}

	FOR(i,1, 101){
		fact[i].resize(prime.size());
		REP(j, prime.size()){

			int curPrime = prime[j];
			int cnt = 0;
			int cur = i;
			while (cur % curPrime == 0){
				cur /= curPrime;
				cnt++;
			}
			fact[i][j] = cnt;
			/*if (cnt != 0)
				cout << "\t" << j << " " << prime[j] << " " << cnt  << endl;*/
		}
	}
}

inline ll getVal(int a, int b, int c){
	vector<int> mu;
	ll ret = 1;
	mu.resize(prime.size());

	REP(i, prime.size()){
			mu[i] += fact[a][i];
			mu[i] += fact[b][i];
			mu[i] += fact[c][i];
			ret = (ret * (mu[i] + 1)) % MOD;
	}
	return ret;
}

inline void run() {
	int a, b, c;
	cin >> a >> b >> c;
	ll ret = 0;
	FOR(i, 1, a)
	FOR(j, 1, b)
	FOR(t, 1, c){
		ret = (ret + getVal(i, j, t)) % MOD;
	}
	cout << ret ;
}
