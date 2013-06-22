#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

int cnt[25];

//Fast input
const int bfsz = 1 << 16; char bf[bfsz + 5]; int rsz = 0;int ptr = 0;
inline char gc() { if (rsz <= 0) { ptr = 0; rsz = fread(bf, 1, bfsz, stdin); if (rsz <= 0) return EOF; } --rsz; return bf[ptr++]; }
inline void ga(char &c) { c = EOF; while (!isalpha(c)) c = gc(); }
inline int gs(char s[]) { int l = 0; char c = gc(); while (isspace(c)) c = gc(); while (c != EOF && !isspace(c)) { s[l++] = c; c = gc(); } s[l] = '\0'; return l; }
template<class T> inline bool gi(T &v) {
	v = 0; char c = gc(); while (c != EOF && c != '-' && !isdigit(c)) c = gc(); if (c == EOF) return false; bool neg = c == '-'; if (neg) c = gc();
    while (isdigit(c)) { v = v * 10 + c - '0'; c = gc(); } if (neg) v = -v; return true;
}
//End of fast input

int main() {
	int n, num;
	gi(n);
	for (int i = 0; i < n; ++i) {
		gi(num);
		int b = 0;
		do {
			if (num & 1) ++cnt[b];
			num >>= 1;
			++b;
		} while (num);
	}

	long long total = 0;
	long long power = 1;
	for (int i = 0; i <= 20; ++i) {
		if (cnt[i])
			total += power * cnt[i] * (n - cnt[i]);
		power <<= 1;
	}

	cout << total << endl;
}

