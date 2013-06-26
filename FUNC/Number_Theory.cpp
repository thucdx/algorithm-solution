// Created : 3:06:12 AM Oct 14, 2012

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
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <sstream>
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
#define FILL(a, x, n) fill(a, a + n, x)
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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector< vi > vvi;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

const double PI = 4.0f * atan(1);  // double or long double ?
const int INF = (int) 1E9 + 5;    // enough ?
const double EPS = 1E-11;        // enough ?
const ll MOD = (ll) 1E9 + 7;    // of problem ?



// b * e mod n
ll mul(ll b, ll e, ll n){
	ll ret = 0;
	while (e){
		if (e & 1) ret = (ret + b) % n;
		e >>= 1;
		b = (b << 1) % n;
	}
	return ret;
}

// (a ^ b ) % m
inline ll power(ll a, ll b, ll m){
	ll ret = 1;
	for( ; b ; b >>= 1){
		if (b & 1) ret = (ret * a) % m;
		a = (a * a) % m;
	}
	return ret % m;
}

// a ^ b
inline ll power(ll a, ll b){ // might overflow
	ll ret = 1;
	for( ; b ; b >>= 1){
			if (b & 1) ret *= a;
			a *= a;
	}
	return ret;
}

// is n square
inline bool isSquare(ll n){
	ll ret = sqrt (n + 1e-5);
	return (ret * ret == n);
}

// isPrime
inline bool isPrime(ll n){
	if (n <= 3) return n >= 2;
	if (n % 2 == 0) return false;

	ll root = sqrt(n);
	for (int i = 3; i <= root; i += 2){
		if (n % i == 0) return false;
	}
	return true;
}

/*
// isPrime, miller rabin
const int PRIME[] = {2, 3, 5, 7, 11, 13, 17, 19,
		23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

// if n >= 4e9 use this function
bool rabinMiller(ll x, int numTry = 15) {
	if (x <= 2 || (x & 1) == 0) {
		return (x == 2 ? true : false);
	}
	ll k = x - 1;
	int m = 0;
	for (; (k & 1) == 0; k >>= 1, m++);
	for (int i = 0; i < numTry && PRIME[i] < x; i++) {
		ll t = power(PRIME[i], k, x);
		if (t == 1 || t == x - 1) {
			continue;
		}
		for (int j = 0; j < m && t != x - 1; j++) {
			t = mod(t * t, x);
		}
		if (t != x - 1) {
			return false;
		}
	}
	return true;
}


// if n <= 4e9, try with 2, 7 , 61 , use with
int PRIME2[3] = {2 , 7, 61};
bool rabinMiller(ll x) {
	int numTry = 3;

	if (x <= 2 || (x & 1) == 0) {
		return (x == 2 ? true : false);
	}
	ll k = x - 1;
	int m = 0;
	for (; (k & 1) == 0; k >>= 1, m++);
	for (int i = 0; i < numTry && PRIME2[i] < x; i++) {
		ll t = fastPow(PRIME2[i], k, x);
		if (t == 1 || t == x - 1) {
			continue;
		}
		for (int j = 0; j < m && t != x - 1; j++) {
			t = mod(t * t, x);
		}
		if (t != x - 1) {
			return false;
		}
	}
	return true;
}
*/

inline ll sqr(ll n){
	return n * n;
}

ll fib(int n){
	if (n <= 2) {
		return (n ? 1 : 0);
	}
	if (n & 1) {
		return sqr(fib(n >> 1)) + sqr(fib((n >> 1) + 1));
	}
	ll x = fib(n >> 1);
	return (2 * fib((n >> 1) - 1) + x) * x;
}


int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif



}
