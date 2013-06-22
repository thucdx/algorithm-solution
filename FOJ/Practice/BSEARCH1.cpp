#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int a[(int) 1e5 + 5];

inline int search(int x) {
	int lo = 0, hi = n - 1, mid;
	while (lo < hi - 1) {
		mid = (lo + hi) >> 1;
		if (a[mid] < x) lo = mid + 1;
		else  {
			hi = mid;
		}
	}
	if (a[lo] == x) return lo;
	if (a[hi] == x) return hi;
	return -1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	int x;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &x);
		printf("%d\n", search(x));
	}
	// more comment
}

