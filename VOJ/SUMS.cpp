#include <set>
#include <map>
#include <queue>
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

#define dbg(x) cout << #x << " = " << x << endl
#define ok() cout << "ok" << endl

#define F first
#define S second
#define MP make_pair

typedef pair<int, int> II;
const int MAXN = 5000;
const int MAXE = 50000;

int n, MOD, t[MAXN + 5], du[MAXN + 5], g[MAXE + 5];
bool exist[MAXE + 5];

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
	int x, _t, _du, cnt = 0;

	gi(n); gi(MOD);
	FOR(i, 2, n) {
		gi(x);
		_du = x % MOD;
		if (!exist[_du]) {
			_t = x / MOD;
			++cnt;
			t[cnt] = _t, du[cnt] = _du, exist[_du] = true;
		}
	}

	FOR(i, 1, MAXE) g[i] = (int) 1e9;
	priority_queue<II> q;
	q.push(MP(0, 0));

	int distance, vertice, carryOut, nextVer;
	while (!q.empty()) {
		distance = -q.top().F, vertice = q.top().S; q.pop();
		if (distance > g[vertice]) continue;

		FOR(i, 1, cnt) {
			nextVer = vertice + du[i];
			carryOut = 0;
			if (nextVer >= MOD) {
				carryOut = 1;
				nextVer -= MOD;
			}

			if (g[nextVer] > distance + carryOut + t[i]) {
				g[nextVer] = distance + carryOut + t[i];
				q.push(MP(-g[nextVer], nextVer));
			}
		}
	}

	int m;
	gi(m);
	FOR(i, 1, m) {
		gi(x);
		if (x / MOD < g[x % MOD]) puts("NIE");
		else puts("TAK");
	}

}
