#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int cnt[255];

int main() {
	string a;
	cin >> a;
	int len = a.length();
	for (int i = 0; i < len; ++i) {
		cnt[a[i]]++;
	}

	int total = 0;
	for (int i = 'a'; i <= 'z'; ++i) {
		if (cnt[i] != 0) total++;
	}

	cout << total << endl;

}
