#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	string c = a + b, d = b + a;
	if (c < d) cout << d;
	else cout << c;
}
