#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define DOW(i, A, a) for (int i = (A), _a = (a); i >= _a; --i)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)

const int MAX = (int) 1e6;

bool prime[MAX + 5];
int pp[200], p[80000], sum[200];

inline bool isPalindrome(string& s) {
	int i = 0, j = s.length() - 1;
	for (; i < j; i++, --j) {
		if (s[i] != s[j]) return false;
	}
	return true;
}

void sieve() {
	int r = sqrt(MAX);
	prime[2] = true;
	for (int i = 3; i <= MAX; i += 2) prime[i] = true;
	for (int i = 3; i <= r; i += 2) {
		if (prime[i]) for (int j = i * i; j <= MAX; j += i) prime[j] = false;
	}

	int cntPP = 0, cntP = 0;


	string rs;
	stringstream ss;
	for (int i = 2; i <= MAX; ++i) {
		if (prime[i]) {
			p[cntP++] = i;

			// to String
			ss.clear();
			ss << i;
			ss >> rs;
			if (isPalindrome(rs)) {
				pp[cntPP] = i;
				int s = 1;
				int  len = rs.length();
				REP(j, len) {
					if (rs[j] != '0')
						s *= rs[j] - '0';
				}
				sum[cntPP++] = s;
			}
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
//	freopen("./IO/output", "w", stdout);
#endif
	sieve();
	int ntest, n;
	scanf("%d", &ntest);
	REP(i, ntest) {
		scanf("%d", &n);
		--n;
		printf("%d %d\n", pp[n], p[sum[n] - 1]);
	}
}

