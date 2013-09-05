// [TIMXAD] ~ [LEAKY] @ [Aug 29, 2013]
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
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

inline int getVal(char c) {
	return  (c >= '0' && c <= '9') ? c - '0' : c - 'a' + 10;
}

inline char getChar(int c) {
	return c >= 10 ? c - 10 + 'a' : c + '0';
}

ll getNum(string a) {
	ll rs = 0;
	int len = a.length();
	for (int i = 0; i < len; ++i) {
		rs =  (rs << 4) + getVal(a[i]);
	}
	return rs;
}

ll s[10];
int key[35];

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	int ntest;
	string x;
	cin >> ntest;
	REP(i, ntest) {
		REP(j, 9) {	cin >> x; s[j] = getNum(x); }

		memset(key, 0, sizeof(key));
		int carryOut = 0;
		DOW(pos, 31, 0) {
			int cnt = 0;
			REP(i, 8) cnt += s[i] % 2;
			cnt += carryOut;
			key[pos] = (cnt % 2 == s[8] % 2) ? 0 : 1;

			REP(i, 8) carryOut += (s[i] % 2) ^ key[pos];
			carryOut -= (s[8] % 2) ^ key[pos];
			carryOut >>= 1;
			REP(i, 9) s[i] >>= 1;
		}

		string rs = "";
		REP(i, 8) {
			int num = 0;
			FOR(j, 4 * i, 4 * i + 3) num = num * 2 + key[j];
			rs.push_back(getChar(num));
		}

		REP(i, sz(rs)) {
			if (rs[i] != '0' || i == sz(rs) - 1) {
				cout << rs.substr(i) << endl;
				break;
			}
		}
	}
}
