#include <iostream>
#include <cstdio>
using namespace std;

int sol(int _a, int b) {
	int a = _a % 10;
	int res = 1;
	for(;b; b >>= 1) {
		if (b&1) {
			res = res * a % 10;
		}
		a = a * a % 10;
	}
	return res;
}

int main() {
	int ntest, a, b;
	scanf("%d", &ntest);
	for(int i = 0; i < ntest; ++i) {
		scanf("%d %d", &a, &b);
		printf("%d\n", sol(a, b));
	}
}


