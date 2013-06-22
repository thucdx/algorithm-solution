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

const int MAX_N = 4000;

int n, a[MAX_N  + 5], b[MAX_N + 5], c[MAX_N + 5], d[MAX_N + 5];
int se[MAX_N * MAX_N + 5];

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
	scanf("%d", &n);
	REP(i, n) {
		gi(a[i]);
		gi(b[i]);
		gi(c[i]);
		gi(d[i]);
	}

	int cnt = 0;
	REP(i, n) REP(j, n) se[cnt++] = -(c[i] + d[j]);

	sort(se, se + cnt);

	int total = 0, sum;
	REP(i, n) REP(j, n){
		sum = a[i] + b[j];
		total += upper_bound(se, se + cnt, sum) - lower_bound(se, se + cnt, sum);
	}
	printf("%d\n", total);
}


