#include <stdio.h>

int g[105];
int FIND(int x) {return g[x]==x?g[x]:g[x]=FIND(g[x]);}
void UNION(int x, int y) { g[FIND(x)] = FIND(y); }

int main(void) {
	int n, i, j;
	int a[105], d[105];
	scanf("%d", &n);

	for(i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		g[i] = i;
	}

	for(i=1;i<=n;i++) {
		scanf("%d", &d[i]);
		if(i+d[i]<=n) UNION(i, i+d[i]);
		if(i-d[i]>=1) UNION(i, i-d[i]);
	}

	for(i=1;i<=n;i++) {
		if(FIND(i)==i) {
			int c[105]={};
			for(j=1;j<=n;j++) if(FIND(j)==i) c[j]++, c[a[j]]--;
			for(j=1;j<=n;j++) if(c[j]) break;
			if(j<=n) break;
		}
	}

	puts(i <= n ? "NO" : "YES");
	return 0;
}
