/* TIMXAD
* Task : 279E
* Desc : http://www.codeforces.com/problemset/problem/279/E
*/
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(a) a.size()

#define FOR(i, a, b) for (int _b = (b), i = (a); i <= _b; i++)
#define FORD(i, a, b) for (int _b = (b), i = (a); i >= _b; i--)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; i++)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	string s;
	while (cin >> s) {
		int result = 0;
		s = "0" + s;
		FORD(i, s.length() - 1, 1) {
			if (s[i] == '1') {
				result++;
				bool move = false;
				while (i > 0 && s[i - 1] == '1') {
					move = true;
					--i;
				}
				if (move) s[i - 1] = '1';
			}
		}
		result += s[0] == '1';
		cout << result << endl;
	}
}
