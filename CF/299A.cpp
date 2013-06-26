/* TIMXAD
* Task : 299A
* Desc : http://www.codeforces.com/problemset/problem/299/A
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

vector<int> a;
int n;

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	int min = (int) 1e9;
	scanf("%d", &n);
	int num;
	REP(i, n) {
		scanf("%d", &num);
		if (num < min) min = num;
		a.PB(num);
	}

	bool isOk = true;
	REP(i, n) {
		if (a[i] % min != 0) {
			isOk = false;
			break;
		}
	}
	if (isOk) cout << min;
	else cout << -1;

}
