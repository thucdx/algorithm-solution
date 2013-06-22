#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

#define For(i,a,b) for(int i = (a), _b = (b); i <= _b; ++i)
#define Down(i,a,b) for(int i = (a), _b = (b);i >= _b; --i)
#define Rep(i, a) for (int i = 0, _a = a; i <= _a; ++i)

using namespace std;

int n, per[10];

inline void show() {
	for (int i = 1; i <= n; i++) {
		printf("%d ", per[i]);
	}
	printf("\n");
}

int main() {
	/*
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	//*/

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) per[i] = i;
	show();

	while (true) {
		int j = n;
		while (j >= 2 && per[j - 1] >= per[j])	--j;
		--j;

		if (j == 0) break;
		for (int p = n; p > j; --p) {
			if (per[p] > per[j]) {
				swap(per[p], per[j]);
				break;
			}
		}

		bool free[10];
		memset(free, false, sizeof(free));
		for (int i = j + 1; i <= n; ++i) {
			free[per[i]] = true;
//			cout << "\tfree " << per[i] << endl;
//			cout << "\t free" << free[per[i]] << endl;
		}

		int cur = j + 1;
		for (int i = 1; i <= n; ++i) if (free[i]) per[cur++] = i;
		show();
	}


}

