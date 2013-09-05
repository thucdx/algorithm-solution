// [TIMXAD] ~ [DicePuzzle] @ [Aug 29, 2013]
#include <set>
#include <map>
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
string cube[24];
int top[3][3], front[3][3];
set<int> rights;
int topState[3][3], frontState[3][3];

vector<int> getPossibleCube(string regex) {
	vector<int> rs;
	REP(i, 24) {
		bool isok = true;
		REP(j, 6) {
			if (regex[j] != 'x' && regex[j] != cube[i][j]) {
				isok = false;
				break;
			}
		}
		if (isok) rs.pb(i);
	}
	return rs;
}

void init() {
	string s[] = {
			"123", "135", "142", "154",
			"214", "231", "246", "263",
			"312", "326", "351", "365",
			"415", "421", "462", "456",
			"513", "536", "541", "564",
			"624", "632", "645", "653" };
	for (int i = 0; i < 24; ++i) {
		FOR(j, 0, 2) cube[i].push_back(s[i][j]);
		FOR(j, 3, 5) cube[i].push_back('7' - s[i][5 - j] + '0');
		cout << i << " " << cube[i] << endl;
	}
}

inline bool inRange(int x) {
	return 0 <= x && x < 3;
}

void dfs(int layer, int row, int col) {
}

void solve() {
	memset(topState, -1, sizeof(topState));
	rights.clear();
	dfs(0, 0, 0); // -> 7
	FIT(it, rights) cout << *it << " "; cout << endl;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	init();

	int ntest;
	scanf("%d", &ntest);
	while (ntest--) {
		REP(i, 3) REP(j, 3) scanf("%d", &top[i][j]);
		REP(i, 3) REP(j, 3) scanf("%d", &front[i][j]);
		solve();
	}


}
