// Created		: 3:09:15 PM Feb 16, 2013
// Task			: CATGO
// Description	: 

#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int PSIZE = 50;
int n, m;
int remainLength[PSIZE + 5], valueable[PSIZE + 5];
int valueOfLeng[PSIZE + 5];
int cost[PSIZE + 5][2 * PSIZE + 5]; // cost[i][j] : i thanh cat thanh j lan.
int valueLenToSegment[PSIZE + 5][PSIZE + 5]; // cut[i][j] : gia tri thu duoc do dai i cat thanh j manh.

int main() {
#ifdef LOCAL
	freopen("input/CATGO", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &remainLength[i]);
	scanf("%d", &m);
	int value;
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d", &valueable[i], &value);
		valueOfLeng[valueable[i]] = value;
	}

	for (int len = 1; len <= PSIZE; ++len) {
		valueLenToSegment[len][0] = valueOfLeng[len];
		for (int times = 1; times <= len; ++times) {
			int max = 0;
			for (int last = 1; last <= len; ++last) {
				int cur = valueLenToSegment[len - last][times - 1] + valueOfLeng[last];
				if (cur > max) max = cur;
			}
			valueLenToSegment[len][times] = max;
		}
	}

	cost[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		cost[i][0] = cost[i - 1][0] + valueOfLeng[remainLength[i]];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 2 * PSIZE; ++j) {
			int max = 0;
			int lenI = remainLength[i];
			for (int k = 0; k <= j; ++k) {
				int cur = cost[i - 1][k] + valueLenToSegment[lenI][j - k];
				if (cur > max) max = cur;
			}
			cost[i][j] = max;
		}
	}

	int result = 0;
	for (int j = 0; j <= 2 * PSIZE; ++j) {
		int cur = cost[n][j] - j * (j + 1) / 2;
//		cout << j << " " << cur << endl;
		if (cur > result) result = cur;
	}
	cout << result;
}
