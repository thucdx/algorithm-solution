#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int f[15000];
void init() {
	int val = 1, i = 1, max = (int) 2e7;
	f[0] = 0;
	while (val <= max) {
		f[i] = val;
		++i;
		val = i * (i + 1) / 2;
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "r", stdin);
#endif

	int ntest, n;
	init();
	scanf("%d", &ntest);
	for (int i = 0; i < ntest; ++i) {
		scanf("%d", &n);
		for (int j = 0; ; ++j) {
			if (f[j] >= n) {
				int row = j;
				int k = n - f[row - 1];
//				printf("__ %d %d\n", f[j], f[row - 1]);
//				printf("Row = %d, K = %d \n", row, k);
				int tu = ((row % 2 == 0) ? k: (row - k + 1));
				printf("TERM %d IS %d/%d\n", n, tu, row + 1 - tu);
//				cout << "\n_________________ " << endl;
				break;
			}
		}
	}
}

