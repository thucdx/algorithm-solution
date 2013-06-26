#include <algorithm>
#include <math.h>
using namespace std;

typedef long long Long;

inline int mod(int x, int n){
	return (x%n+n)%n;	
}

void gcd(int a, int b, int &d, int &x, int &y){
	if (b == 0){
		d = a; x = 1; y = 0; return;	
	}	
	gcd(b, a % b, d, y, x);
	y -= x * (a / b);
}

int Inv(int a, int n){
	int d, x, y;  gcd(a, n, d, x, y);
	if (d == 1) return mod(x, n); else return -1;	
}

int ModPow(int a, int b, int n){
	Long d(1), i(0);
	while (b >=((Long)1 << i)) i++;
	for (--i; i >= 0; --i){
		d = d * d % n;
		if (b & (1 << i)) d = d * a % n;
	}	
	return d;
}

int mexp[50000], id[50000];
bool logcmp(const int &a, const int &b){
	return mexp[a] < mexp[b];
}

int ModLog(int a, int b, int n){
	int i, j, m = (int)ceil(sqrt(n));
	int inv = Inv(ModPow(a, m, n), n);
	for (id[0] = 0, mexp[0] = i = 1; i < m; i++){
		id[i] = i; mexp[i] = (mexp[i-1]*(Long)a) % n;
	}
	stable_sort(id, id + m, logcmp);
	sort(mexp, mexp + m);
	for (i = 0; i < m; i++){
		j = lower_bound(mexp, mexp + m, b) - mexp;
		if (j < m && mexp[j] == b) return i * m + id[j];
		b = (b*(Long)inv)%n;
	}
	return -1;	
}

int main(){
	Long n, b, p;
	while (scanf("%I64d %I64d %I64d", &p, &b, &n) != EOF){
		int ans = ModLog(b, n, p);
		if (ans != -1) printf("%d\n", ans);
		else puts("no solution");
	}
	return 0;	
}
