#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int mod = (int)1e9 + 7;

inline int pow(int a, int b) {
	long long _a = a;
	long long result = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			result = result * _a % mod;
		}
		_a = _a * _a % mod;
	}
	return result % mod;
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
	freopen("./IO/input.txt", "r", stdin);
#endif
	int ntest, n;

	scanf("%d", &ntest);

	for (int i = 0; i < ntest; ++i) {
		gi(n);
		printf("%d\n", pow(2, n - 1));
	}
}

