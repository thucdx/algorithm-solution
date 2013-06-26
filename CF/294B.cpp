/*
* TIMXAD
* Date : Apr 15, 2013, 2:41:41 PM
* Task : 294B
* Desc : http://codeforces.com/problemset/problem/294/B
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
#define FOR(i, a, b) for (int _a = (a), _b = (b), i = _a; i <= _b; i++)
#define FORD(i, a, b) for (int _a = (a), _b = (b), i = _a; i >= _b; i--)
#define REP(i, a) for (int i = 0; i < (a); i++)
#define FIT(it, v) for (typeof((v).begin())it = (v).begin(); it != (v).end(); it++)

int n;
vector<int> one, two;

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	scanf("%d", &n);
	int t, w;
	REP(i, n) {
		scanf("%d %d", &t, &w);
		if (t == 1) one.PB(w);
		else two.PB(w);
	}

	sort(one.begin(), one.end());
	sort(two.begin(), two.end());

	int minThickBehind = (int) 1e6;
	FORD(i, SZ(one), 0) {
		FORD(j, SZ(two), 0) {
			int behind = 0, above = 0;
			behind = SZ(one) - i + (SZ(two) - j) * 2;
			FOR(ii, 0, i - 1) above += one[ii];
			FOR(jj, 0, j - 1) above += two[jj];
			if (above <= behind && behind < minThickBehind) {
				minThickBehind = behind;
			}
		}
	}
	cout << minThickBehind << endl;
}
