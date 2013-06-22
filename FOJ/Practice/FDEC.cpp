#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

inline bool isPrime(int n) {
	if (n <= 3) return n >= 2;
	if (n % 2 == 0 || n % 3 == 0) return false;
	int r = sqrt(n);
	int i = 5;

	while (i <= r) {
		if (n % i == 0 || n % (i + 2) == 0) return false;
		i += 6;
	}
	return true;
}

string s;

int main() {
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		if (isPrime(i + 1)) {
			printf("%c", s[i]);
		}
	}
}
