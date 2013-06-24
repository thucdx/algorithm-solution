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

#define dbg(x) cout << #x << " = " << x << endl
#define ok() cout << "ok" << endl

string c[] = {"1", "14", "144"};

set<string> s;
string cur;
void dfs() {
	int len = cur.length();
	if (len >= 10) return;
	if (len > 0) s.insert(cur);

	string _cur = cur;
	REP(i, 3) {
		cur = cur + c[i];
		dfs();
		cur = _cur;
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
//	freopen("./IO/output", "w", stdout);
#endif
	cur = "";
	dfs();
	string x;
	cin >> x;
	if (s.count(x) > 0) {
		puts("YES");
	} else puts("NO");
}
