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

typedef long long ll;
int n;
string s[10005];

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
//	freopen("./IO/output", "w", stdout);
#endif
	int ntest;
//	scanf("%d", &ntest);
	ios_base::sync_with_stdio(false);
	cin >> ntest;

	while (ntest--) {
		cin >> n;
		REP(i, n) cin >> s[i];
		sort(s, s + n);
//		REP(i, n) cout << s[i] << endl;
		bool isOk = true;
		FOR(i, 0, n - 2) {
			if (s[i].length() >= s[i + 1].length()) continue;
			int minLen = s[i].length();

			bool isMatch = true;
			REP(j, minLen) {
				if (s[i][j] != s[i + 1][j]) {
					isMatch = false;
					break;
				}
			}
			if (isMatch) {
				isOk = false;
				break;
			}
		}

		cout << (isOk ? "YES\n" : "NO\n");
	}

}

