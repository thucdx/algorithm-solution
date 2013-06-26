/* TIMXAD
* Task : 302C
* Desc : 
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

int n;

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	scanf("%d", &n);
	int a, min = 1005, count = 0, sum = 0;
	REP(i, 2 * n - 1) {
		scanf("%d", &a);
		if (a < 0) count++;
		sum += abs(a);
		if (abs(a) < min) min = abs(a);
	}

	if (count % 2 == 0) {
		cout << sum << endl;
	} else {
		if (n % 2 == 0) cout << (sum - 2 * min) << endl;
		else cout << sum << endl;
	}
}
