#include <algorithm>
using namespace std;
#define MAXN 1200000

int a[MAXN];
int p[MAXN];

int main() {
    int n, max, i, j, d;
    bool first = 1;
    while (1 == scanf("%d", &n) && n) {
        if (!first) printf("\n"); else first = 0;
        memset(a, 0, sizeof(a));
        memset(p, 0, sizeof(p));
        max = 0;
      	for(i = 0; i < n; i++) {
          	scanf("%d", &d);
          	a[d]++;
          	p[i] = d;
          	max >?= a[d];
      	}
      	printf("%d\n", max);
      	sort(p, p + n);
      	for(i = 0; i < max; i++) {
          	for(j = i; j < n; j+=max) {
              	if (j > i) printf(" ");
              	printf("%d", p[j]);
          	}
          	printf("\n");
      	}
   	}
	return  0;
}
