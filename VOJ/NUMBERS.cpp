// [TIMXAD] ~ [NUMBERS] @ [Sep 4, 2013]
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cassert>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define DOW(i, A, a) for (int i = (A), _a = (a); i >= _a; --i)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

#define dbg(x) cout << #x << " = " << x << endl
#define ok() cout << "@OK!" << endl
#define pb push_back
#define mp make_pair
#define sz(a) (int) a.size()
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAX = 50000;
const int MAX_VAL = (int) 1e6;
int a[MAX + 5], h[MAX_VAL + 5];
vector<int> colors[MAX + 5];

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
#endif
	int n;
	gi(n);
	REP(i, n) gi(a[i]);

	sort(a, a + n);
	int maxH = 0;
	FOR(i, 0, n - 1) {
		int val = a[i], color = 1;
		if (i > 0 && a[i] == a[i - 1]) {
			color = h[a[i]] + 1;
		} else {
			int r = sqrt(val), step = 1 + val % 2;
			for (int d = 1; d <= r; d += step) {
				if (!(val % d)) color = max(color, max(h[d], h[val / d]) + 1);
			}
		}
		h[val] = color;
		maxH = max(maxH, color);
		colors[color].pb(val);
	}

	printf("%d\n", maxH);
	DOW(i, maxH, 1) {
		printf("%d", colors[i].size());
		FIT(it, colors[i]) printf(" %d", *it);
		printf("\n");
	}
}
