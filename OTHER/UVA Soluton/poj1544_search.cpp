#include <algorithm>
using namespace std;

bool have;
int m[5][5];
int x[110], y[110];
bool a[110][5][5];
bool v[110];
int n;

void check(){
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			if (m[i][j] == 0) return;
	have = true;
	for (int i = 1; i <= 4; i++){
		for (int j = 1; j <= 4; j++)
			printf("%d", m[i][j]);
		putchar('\n');
	}
}

bool ok(int xx, int yy ,int k){
	for (int i = xx; i < xx + x[k]; i++)
		for (int j = yy; j < yy + y[k]; j++)
			if (m[i][j] > 0 && a[k][i+1-xx][j+1-yy])
				return false;
	return true;
}

void fillmap(int xx, int yy, int k){
	for (int i = xx; i < xx + x[k]; i++)
		for (int j = yy; j < yy + y[k]; j++)
			if (a[k][i+1-xx][j+1-yy]) m[i][j] = k;	
}

void clearmap(int xx, int yy, int k){
	for (int i = xx; i < xx + x[k]; i++)
		for (int j = yy; j < yy + y[k]; j++)
			if (a[k][i+1-xx][j+1-yy]) m[i][j] = 0;	
}

void dfs(){
	if (!have) check();
	if (have) return;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			for (int k = 1; k <= n; k++)		
				if (!v[k] && ok(i, j, k)){
					fillmap(i, j, k);
					v[k] = true;
					dfs();
					v[k] = false;
					clearmap(i, j, k);
				}	
}

int main(){
	//freopen("test.in", "r" ,stdin);
	//freopen("test.out", "w", stdout);
	bool first = 1;
	while(1){
		if (first) first = 0; else putchar('\n');
		scanf("%d", &n);
		if (n == 0) break;
		memset(m, 0, sizeof(m));
		memset(a, 0, sizeof(a));
		for (int k = 1; k <= n; k++){
			scanf("%d%d", x + k, y + k);
			for (int i = 1; i <= x[k]; i++){
				getchar();
				for (int j = 1; j <= y[k]; j++){
					char ch; ch = getchar();
					a[k][i][j] = (ch == '1');
				}	
			}
		}	
		have = false;
		memset(v, 0, sizeof(v));
		dfs();
		if (!have) puts("No solution possible");
	}	
	return 0;	
}
