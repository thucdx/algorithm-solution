/* TIMXAD
 * Task : 300C
 * Desc :
 */
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(a) a.size()

#define FOR(i, a, b) for (int _b = (b), i = (a); i <= _b; i++)
#define FORD(i, a, b) for (int _b = (b), i = (a); i >= _b; i--)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; i++)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

typedef long long ll;

const int MOD = (int) 1e9 + 7;
const int MAX = (int) 1e6;
ll fact[MAX + 5];

int a, b, n;

void init(int n) {
	fact[0] = 1;
	FOR(i, 1, n)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}
}

inline int powMod(int a, int b, int mod) {
	ll result = 1;
	ll _a = a;
	for (; b; b >>= 1) {
		if (b % 2)
			result = (result * _a) % mod;
		_a = (_a * _a) % mod;
	}
	return (int) result;
}

inline int invert(int a, int primeMod) {
	return powMod(a, primeMod - 2, primeMod);
}

inline int c(int i, int n, int mod) {
	return ((ll) fact[n] * invert((ll) fact[i] * fact[n - i] % mod, mod)) % mod;
}

inline bool isNice(int number) {
	int dig;
	do {
		dig = number % 10;
		if (dig != a && dig != b) {
			return false;
		}
		number /= 10;
	} while (number > 0);
	return true;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif

			ll result = 0;

			cin >> a >> b >> n;
			init(n);

			FOR(i, 0, n) {
				if (isNice(a * i + b * (n - i))) {
					result = result + c(i, n, MOD);
					if (result >= MOD) result -= MOD;
				}
			}
			cout << result << endl;
		}
