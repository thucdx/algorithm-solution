#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	int a, b;
	if (n <= 0) {
		a = -1;
		if (n < 0)
			b = 0;
		else b = 1;
	}
	else {
		a = (int) sqrt(n);
		if (a*a == n) --a;
		a *= a;
		b = (int) sqrt(n) + 1;
		b *= b;
	}

	cout << a << " " << b << endl;
}

