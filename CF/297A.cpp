/*
* TIMXAD
* Date : Apr 24, 2013, 6:06:28 PM
* Task : 297A
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

string a, b;

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	while (cin >> a) {
		cin >> b;
		int cntA = 0, cntB = 0;
		REP(i, a.length()) cntA += (a[i] == '1');
		REP(i, b.length()) cntB += (b[i] == '1');
		if (cntA + (cntA % 2) >= cntB) puts("YES");
		else puts("NO");
	}
}
