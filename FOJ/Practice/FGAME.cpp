/*
 * Who  : timxad
 * Task : FGAME_SOLVE
 * Date : Jun 5, 2013
 * Desc :
 */
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define Sort(a) sort(all(a))
#define Unique(a) Sort(a); a.resize(unique(all(a) - a.begin()))

#define For(i, a, b) for (int _b = (b), i = (a); i <= _b; ++i)
#define Ford(i, a, b) for (int _b = (b), i = (a); i >= _b; --i)
#define Rep(i, a) for (int i = 0, _a = (a); i < _a; ++i)
#define Fit(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

template<typename T> inline T mod(T a, T b) {
	return (a % b + b) % b;
}

inline bool isPrime(long long n)
{
    if (n <= 3) return n >= 2;
    if (!(n&1)) return false;

    if (n % 3 == 0) 	return false;
    if (n < 9) 	return true;

	int r = sqrt(n);
	int f = 5;

	while (f <= r)
	{
		if (!(n % f)) return false;
		if (!(n % (f + 2))) return false;
		f += 6;
	}
	return true;
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
	freopen("./IO/FAGME/input2.txt", "r", stdin);
	freopen("./IO/FAGME/outputx.txt", "wt", stdout);
#endif
	int ntest;
	scanf("%d", &ntest);
	long long n;

	Rep(i, ntest) {
//		scanf("%lld", &n);
		gi(n);
		if (isPrime(n + 1)) {
			printf("Duy\n");
		} else {
			printf("Tam\n");
		}
	}

//	end = clock();
//	cout << end - start << endl;
}


