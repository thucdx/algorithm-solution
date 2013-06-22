#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define DOW(i, A, a) for (int i = (A), _a = (a); i >= _a; --i)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)

const int MAX_N = 100000;
int prime[MAX_N + 5];
int p[10005], totalPrime;

void sieve() {
	fill(prime, prime + MAX_N + 1, 1);
	int r = sqrt(MAX_N);

	for (int i = 4; i <= MAX_N; i += 2) prime[i] = 0;
	for (int i = 3; i <= r; i += 2) {
		if (prime[i]) for (int j = i * i; j <= MAX_N; j += i) prime[j] = 0;
	}

	totalPrime = 0;
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= MAX_N; ++i) {
		if (prime[i]) p[totalPrime++] = i;
		prime[i] = totalPrime;
	}
}

//Fast input
const int bfsz = 1 << 16; char bf[bfsz + 5]; int rsz = 0;int ptr = 0;
char gc() { if (rsz <= 0) { ptr = 0; rsz = fread(bf, 1, bfsz, stdin); if (rsz <= 0) return EOF; } --rsz; return bf[ptr++]; }
void ga(char &c) { c = EOF; while (!isalpha(c)) c = gc(); }
int gs(char s[]) { int l = 0; char c = gc(); while (isspace(c)) c = gc(); while (c != EOF && !isspace(c)) { s[l++] = c; c = gc(); } s[l] = '\0'; return l; }
template<class T> bool gi(T &v) {
	v = 0; char c = gc(); while (c != EOF && c != '-' && !isdigit(c)) c = gc(); if (c == EOF) return false; bool neg = c == '-'; if (neg) c = gc();
    while (isdigit(c)) { v = v * 10 + c - '0'; c = gc(); } if (neg) v = -v; return true;
}
//End of fast input

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
//	freopen("./IO/output", "w", stdout);
#endif
	sieve();

	int ntest, n, k, pos;
	long long total;
	gi(ntest);
	while (ntest--) {
		gi(n); gi(k);
		total = 0;
		if (k == 0) total = (long long)(n-1) * (n)/2;
		else  {
			for (int i = 2; ; ++i) {
				pos = prime[i - 1];
				if (pos + k > totalPrime) break;
				int nextPrime = p[pos + k - 1];
				if (nextPrime > n) break;
				total += n - nextPrime + 1;
			}
		}
		printf("%lld\n", total);
	}
}

