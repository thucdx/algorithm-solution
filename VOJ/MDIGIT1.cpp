// [TIMXAD] ~ [QMAX2] @ [Aug 27, 2013]
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
const int MAX = 65536;

int n, m, mcnt, tcnt, h, a[5];
bool vs[MAX + 5];
string ans, tans;

struct Node {
	int dig, val, pre, pos;
	Node() { dig = val = pre = pos = 0; }
	void set(int _pos, int _dig, int _val, int _pre) {
		pos = _pos; dig = _dig; val = _val; pre = _pre;
	}
} q[MAX + 5];

void getAns(int k) {
	char c;
	if (k == -1) return;
	else {
		getAns(q[k].pre);
		c = q[k].dig + '0';
		tans += c;
	}
}

bool bfs(int k) {
	int nval, ncnt, tval;
	int head = 0, tail = -1;
	Node cur, now;

	memset(vs, 0, sizeof(vs));
	for (int i = 1; i <= k; i++) {
		if (a[i]) {
			cur.set(0, a[i], a[i] % n, -1);
			vs[cur.val] = 1;
			q[++tail] = cur;
		}
	}

	// bfs
	while (head <= tail) {
		now = q[head];
		nval = now.val;
		ncnt = now.pos;
		if (ncnt > mcnt) break;
		if (!nval) {
			h = head;
			tcnt = ncnt;
			return true;
		}

		for (int i = 1; i <= k; i++) {
			tval = (nval * 10 + a[i]) % n;
			if (!vs[tval]) {
				vs[tval] = 1;
				cur.set(ncnt + 1, a[i], tval, head);
				q[++tail] = cur;
			}
		}
		head++;
	}

	return false;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	string NOT_FOUND = "xxxx";
	while (scanf("%d", &n) && n != 0) {
		int found = 0;
		ans = NOT_FOUND;
		mcnt = (int) 1e9;
		for (int i = 1; i <= 9; i++) {
			a[1] = i;
			if (bfs(1)) {
				tans = "";
				getAns(h);
				if (mcnt > tcnt || (mcnt == tcnt && ans > tans)) {
					ans = tans;
					mcnt = tcnt;
				}
			}
		}
		if (ans != NOT_FOUND) {
			found = 1;
			cout << ans << endl;
		}
		if (found) continue;

		for (int i = 0; i <= 9; i++) {
			a[1] = i;
			for (int j = i + 1; j <= 9; j++) {
				a[2] = j;
				if (bfs(2)) {
					tans = "";
					getAns(h);
					if (mcnt > tcnt || (mcnt == tcnt && ans > tans)) {
						ans = tans;
						mcnt = tcnt;
					}
				}
			}
		}
		cout << ans << endl;
	}
}
