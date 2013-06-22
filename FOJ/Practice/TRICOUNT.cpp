#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

unsigned long long f[(int)1e6 + 5];

void init() {
	f[1] = 1;
	f[2] = 5;
	for (long long i = 3; i <= 1e6; ++i) {
		int k = (i-1)/2;
		f[i] = f[i - 1] + i*(i+1)/2 + (k+1) * (i - 1 - k);
	}
}

int main() {
	int ntest, n;
	init();
	scanf("%d", &ntest);
	while(ntest--) {
		scanf("%d", &n);
		printf("%llu\n", f[n]);
	}
}

