#include <algorithm>
using namespace std;
const int MAXN = 2010;
const int MAXQ = 1000000;
int n, m;
int g[MAXN][MAXN], d[MAXN][MAXN], qx[MAXQ], qy[MAXQ];
int qn;

void update(int x, int y, int a, int b)   {
	if (x+a > 2000) return;
   	if (x+a < 0) return;
   	if (y+b > 2000) return;
   	if (y+b < 0) return;
   	if (d[x+a][y+b] > d[x][y] + 1) {
      	d[x+a][y+b] = d[x][y] + 1; 
      	qx[qn] = x + a;
      	qy[qn++] = y + b;
      	if (qn >= MAXQ) qn = 0;
   	}
}

int main(){
	while (scanf("%d", &n) && n){
		memset(g, 0, sizeof(g));
		for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) d[i][j] = INT_MAX;
		int x, y;
		qn = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			g[x][y] = 1;
			d[x][y] = 0;
			qx[qn] = x;
			qy[qn++] = y;	
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			g[x][y] = 2;
		}
		int f = 0;
		while (f!= qn){
			f++; if (f >= MAXQ) f = 0;
			if (g[qx[f]][qy[f]] == 2){
				printf("%d\n", d[qx[f]][qy[f]]);
				break;				
			}
			update(qx[f], qy[f], 1, 0); update(qx[f], qy[f], 0, 1);
			update(qx[f], qy[f], -1, 0); update(qx[f], qy[f], 0, -1);
		}
	}
	return 0;	
}
