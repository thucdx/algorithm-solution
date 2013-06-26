/*
* TIMXAD
* Date : Apr 26, 2013, 9:55:52 PM
* Task : 299C
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
int c, xa, xb;
int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	int n;
	cin >> n >> a >> b;
	REP(i, 2 * n) {
		if (a[i] == b[i] && b[i] == '1') {
			c++;
			continue;
		}
		if (a[i] == '1') xa++;
		if (b[i] == '1') xb++;
	}
	xb -= c % 2;
	if (xa <= xb && xa + 1 >= xb) {
		puts("Draw");
	} else {
		if (xa + 1 > xb) {
			puts("First");
		} else
			puts("Second");
	}
}
