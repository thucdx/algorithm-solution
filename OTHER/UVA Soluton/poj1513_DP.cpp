#include <algorithm>
using namespace std;

int n, l, s, cc;
int f[1010], c[1010], t[1010];

int di(int s){
	if (!s) return 0;
	if (s >= 1 && s <= 10) return -cc;
	return (s - 10) * (s - 10);	
}

int main(){
	int cases = 0;
	while (scanf("%d", &n) != EOF && n){
		if (cases) puts("");
		scanf("%d %d", &l, &cc);
		memset(t, 0, sizeof(t));
		for (int i = 1; i <= n; i++){
			scanf("%d", &s);
			t[i] = t[i - 1] + s;
		}
		memset(f, 0, sizeof(f));
		memset(c, 0, sizeof(c));
		
		for (int i = 1; i <= n; i++){
			c[i] = INT_MAX;  f[i] = INT_MAX;
			for (int j = i - 1; j >= 0; j--)
				if (l >= t[i] - t[j]){
					if (c[j] + 1 < c[i]){
						c[i] = c[j] + 1;
						f[i] = f[j] + di(l - t[i] + t[j]);	
					}
					else if (c[j] + 1 == c[i])
						f[i] <?= f[j] + di(l - t[i] + t[j]); 
				}
				else break	;
		}
		printf("Case %d:\n\n", ++cases);
		printf("Minimum number of lectures: %d\n", c[n]);
		printf("Total dissatisfaction index: %d\n", f[n]); 
	}
	return 0;	
}
