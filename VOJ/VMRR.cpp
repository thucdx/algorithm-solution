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

const int MAX = (int) 1e6;
int cnt[MAX + 5];
char s[MAX + 5];

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
//	freopen("./IO/output", "w", stdout);
#endif

	char c1, c2;
	//scanf("%s\n", s);
	gets(s);
	scanf("%c %c", &c1, &c2);

	int len = strlen(s);
	cnt[len] = 0;
	DOW(i, len - 1, 0) {
		cnt[i] = cnt[i + 1];
		if (s[i] == c2) cnt[i]++;
	}

	long long result = 0;
	REP(i, len) {
		if (s[i] == c1) {
			result += cnt[i + 1];
		}
	}

	cout << result << endl;
}
