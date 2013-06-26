#include <algorithm>
using namespace std;
const int MAXN = 100;

int F, E, A, B;
int pnt[MAXN], X[100], Y[100];
bool ca[MAXN], cb[MAXN];

int find(int x){
	if (pnt[x] != x) pnt[x] = find(pnt[x]);
	return pnt[x];
}

void extended_gcd(int a, int b, int &g, int &x, int &y){
	if (b == 0) {x = 1; y = 0; g = a;}	
	else {extended_gcd(b, a % b, g, y, x); y -= x * (a / b); };
}

bool check(){
	if (A == B) return true;
	bool noA = 1, noB = 1;
	int i, j, gcd, x, y, ki, kj, xi, xj, tmp, fi, fj;
	for (i = 0; i < E; i++){
		ca[i] = A >= Y[i] && (A - Y[i]) % X[i] == 0;
		cb[i] = B >= Y[i] && (B - Y[i]) % X[i] == 0;
		if (ca[i] && cb[i]) return true;
		if (ca[i]) noA = 0;
		if (cb[i]) noB = 0;
	}
	if (noA || noB) return false;
	
	for (i = 0; i < E; i++)
		for (j = i + 1; j < E; j++){
			fi = find(i); fj = find(j);
			if (fi == fj) continue;
			if (X[i] >= X[j]) extended_gcd(X[i], X[j], gcd, x, y);
			else extended_gcd(X[j], X[i],gcd, y, x);
			
			if (Y[i] % gcd != Y[j] % gcd) continue;
			xi = X[i] / gcd, xj = X[j] / gcd;
			y = (Y[j] - Y[i]) / gcd;
			ki = (y * x) % xj; if (ki < 0) ki = xj + ki;
			kj = (xi * ki - y) / xj;
			
			if (kj < 0) tmp = (-1 - kj)/ xi + 1; else tmp = 0;
			ki += tmp * xj; kj += tmp * xi;
			
			if (Y[i] + X[i] * ki < F){
				pnt[fj] = fi;
				ca[fi] |= ca[fj];
				cb[fi] |= cb[fj];
				if (ca[fi] && cb[fi]) return true;
			}
		}
	return false;
}

int main(){
	int cases;
	scanf("%d", &cases);
	while (cases--){
		scanf("%d%d%d%d", &F, &E, &A, &B);
		for (int i = 0; i < E; i++)	pnt[i] = i;
		for (int i = 0; i < E; i++) scanf("%d %d", X + i, Y + i);
		if (check()) puts("It is possible to move the furniture.");
		else puts("The furniture cannot be moved.");
	}
	return 0;	
}
