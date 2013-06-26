#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int tens[]  = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int nines[] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 2000000000};

int hmNines(int x){
	for (int i = 1; i < 9 ; i++){
		if (x % tens[i] != nines[i]){
			if (x > nines[i - 1]) return i - 1;
			else return i - 2;
		}
	}
	return 7;
}

vector<int> countDig(int a){
	vector<int> dig(10, 0);
	while (a > 0){
		int n = hmNines(a);
		for (int i = a/tens[n]; i ; i /= 10)
			dig[ i % 10 ] += tens[n];
		if (n) for(int i = 0; i < 10 ;i++)
			dig[ i ] += tens[n - 1] * n;
		a -= tens[n];
	}
	return dig;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	cout << hmNines(10) << endl;
	cout << hmNines(1998) << endl;
	cout << hmNines(99) << endl;
	cout << hmNines(1000001) << endl;
	cout << hmNines(998) << endl;
	/*int a, b;
	scanf("%d %d", &a, &b);
	while(a){
		vector<int> digA = countDig(a-1);
		vector<int> digB = countDig(b);
		for(int i=0; i<10 ;i++)
			digB[i] -= digA[i];
		printf("%d", digB[0]);
		for(int i=1; i<10 ;i++)
			printf(" %d", digB[i]);
		printf("\n");
		scanf("%d %d", &a, &b);
	}*/
}
