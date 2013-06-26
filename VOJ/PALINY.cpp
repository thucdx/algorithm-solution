// Created		: 1:55:28 AM Feb 19, 2013
// Task			: PALINY
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
#define ll long long

const int MOD = (int) 137;
const int PSIZE = 50000;

int len;
char str[PSIZE + 5];
int lft[PSIZE + 5], rght[PSIZE + 5];
int power[PSIZE + 5];

inline int getHashLeft(int l, int r) {
	if (l == 0) return lft[r];
	return lft[r] - lft[l - 1] * power[r - l + 1];
}

inline ll getHashRight(int l, int r) {
	if (r == len - 1) return rght[l];
	return rght[l] - rght[r + 1] * power[r - l + 1];
}

inline int isExist(int l) {
	for (int i = 0; i < len - 2 * l + 1; ++i) {
			int first = getHashLeft(i, i + l - 1);
			int second = getHashRight(i + l, i + 2 * l - 1);
			if (first == second) return 2 * l;
	}

	for (int i = 0; i < len - 2 * l + 2; ++i) {
		int first = getHashLeft(i, i + l - 1);
		int second = getHashRight(i + l - 1, i + 2 * l - 2);
		if (first == second) return 2 * l - 1;
	}

	return -1;
}

int main() {
#ifdef LOCAL
	freopen("input/PALINY", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &len);
	scanf("%s", str);
	len = strlen(str);

	// Hash
	for (int i = 0; i < len; ++i) {
		str[i] -= 'a' - 1;
	}
	lft[0] = str[0];
	power[0] = 1;
	for (int i = 1; i < len; ++i) {
		lft[i] = lft[i - 1] * MOD + str[i];
		power[i] = MOD * power[i - 1];
	}
	rght[len - 1] = str[len - 1];
	for (int i = len - 2; i >= 0; --i) {
		rght[i] = rght[i + 1] * MOD + str[i];
	}
	int low = 1, hi = len;
	while (low < hi - 1) {
		int mid = (low + hi) / 2;
		if (isExist(mid) != -1) {
			low = mid;
		} else {
			hi = mid - 1;
		}
	}

	int last = isExist(hi);
	cout << (last != -1 ? last : isExist(low));
}
