// Created		: 5:08:52 PM Feb 22, 2013
// Task			: NKCNT1
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

int n, m;
const int MAX = 5000;
char str[MAX + 5][MAX + 5];
int l[MAX + 5][MAX + 5], totalRow[MAX + 5];
int t[MAX + 5][MAX + 5], totalColumn[MAX + 5];
int total[MAX + 5][MAX + 5]; // count number of zero in (0,0) -> (i, j);

inline int getNumberOfZero(int x1, int y1, int x2, int y2) {
	int result = total[x2][y2] + total[x1][y1] - total[x1][y2] - total[x2][y1] +
					l[x1][y2] - l[x1][y1] + str[x1][y1] + t[x2][y1] - t[x1][x1];
	return result;
}

inline bool isOK(int row, int column, int d) {
	return getNumberOfZero(row, column, row + d - 1, column + d - 1) == d * d;
}

int main() {
#ifdef LOCAL
	freopen("input/NKCNT1", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", str[i]);
//		cout << str[i] << endl;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			str[i][j] = '1' - str[i][j];
		}
	}

	// Row
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		l[i][0] = str[i][0];
		cnt += l[i][0];
		for (int j = 1; j < m; ++j) {
			l[i][j] = l[i][j - 1] + str[i][j];
			cnt += str[i][j];
		}
		totalRow[i] = cnt;
	}

	// Column
	for (int i = 0; i < m; ++i) {
		int cnt = 0;
		t[0][i] = str[0][i];
		for (int j = 1; j < n; ++j) {
			t[j][i] = t[j - 1][i] + str[j][i];
			cnt += t[j][i];
		}
		totalColumn[i] = cnt;
	}

	for (int i = 0; i < n; ++i) {
		total[i][0] = t[i][0];
		for (int j = 1; j < m; ++j) {
			total[i][j] = total[i][j - 1] + t[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (str[i][j] == 0) continue;
			int low = 1, hi = min(n - i, m - j);
			while (low < hi - 1) {
				int mid = (low + hi) / 2;
				if (isOK(i, j, mid)) low = mid;
				else hi = mid - 1;
			}
			result += isOK(i, j, hi) ? hi : low;
		}
	}
	cout << result;
}
