/*
* TIMXAD
* Date : Apr 15, 2013, 3:09:25 PM
* Task : 294A
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

#define FOR(i, a, b) for (int _a = (a), _b = (b), i = _a; i <= _b; i++)
#define FORD(i, a, b) for (int _a = (a), _b = (b), i = _a; i >= _b; i--)
#define REP(i, a) for (int i = 0; i < (a); i++)
#define FIT(it, v) for (typeof((v).begin())it = (v).begin(); it != (v).end(); it++)

int n, w[105];

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	scanf("%d", &n);
	FOR(i, 1, n) scanf("%d", &w[i]);
	int nShot, xi, yi;
	scanf("%d", &nShot);
	REP(i, nShot) {
		scanf("%d %d", &xi, &yi);
		if (xi > 1) w[xi - 1] += yi - 1;
		if (xi < n) w[xi + 1] += w[xi] - yi;
		w[xi] = 0;
	}

	FOR(i, 1, n) {
		printf("%d\n", w[i]);
	}
}
