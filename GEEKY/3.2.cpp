// [TIMXAD] ~ [3.2] @ [Sep 25, 2013]
#include <set>
#include <map>
#include <queue>
#include <deque>
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
#define dbg(x) cout << #x << " " << x << endl

typedef long long ll;

string result = "there's no reality except the one contained within us. that's why so many people live an unreal life. they take images outside them for reality and never allow the world within them to assert itself.";
string ACCEPT_SYMBOL = " .,\'";
bool isOk[260];
void init() {
	FOR (c, 'a', 'z') isOk[c] = true;
	FOR (c, 'A', 'Z') isOk[c] = true;
	FOR (c, '0', '9') isOk[c] = true;
	REP (i, ACCEPT_SYMBOL.length()) isOk[ACCEPT_SYMBOL[i]] = true;
}

#define MESSAGE_LENGTH 199

int main() {
#ifdef LOCAL
	freopen("D:/GK/datdata/data.dat", "r", stdin);
//	freopen("./IO/output", "w", stdout);
#endif
	init();

	ll pos = 0;
	int totalOk = 0;
	deque<char> q;
	char curChar;

	while (scanf("%c", &curChar) != EOF) {
		if (isOk[curChar]) ++totalOk;
		q.push_back(curChar);
		if (pos >= MESSAGE_LENGTH) {
			if (isOk[q.front()]) --totalOk;
			q.pop_front();
		}

		if (totalOk == MESSAGE_LENGTH) {
			bool isOk = true;
			int i = 0;
			FIT (it, q) {
				if (*it != result[i]) { isOk = false; break; }
				++i;
			}
			if (isOk) cout << pos - (MESSAGE_LENGTH - 1) << endl;
		}

		++pos;
	}
}
