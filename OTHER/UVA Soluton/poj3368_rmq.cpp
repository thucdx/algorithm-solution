#include <algorithm>
using namespace std;

const int MAXN = 100000;
int n, m;
int be[MAXN], ed[MAXN], num[MAXN];

bool init(){
	int nn;
	scanf("%d", &nn);
	if (nn == 0) return false;
	int a, b = -0x3fffffff;
	n = 0; scanf("%d", &m);
	memset(num, 0, sizeof(num));
	memset(ed, 0, sizeof(ed)); 
	memset(be, 0, sizeof(be));
	scanf("%d", &b); 
	int j = 1; ed[0] = 1;
	for (int i = 2; i <= nn; i++) {
		scanf("%d", &a);
		if (a != b){
			be[n] = j;
			num[n] = i - j;
			ed[n++] = i - 1;
			j = i; b = a;
		}
	}
	be[n] = j;
	ed[n] = nn;
	num[n++] = nn  + 1 - j;
	be[n] = nn + 1;
	return true;
}


int h[MAXN][32];
void prepare(){
	int i, j, l;
	for (i = 0; i < n; i++) h[i][0] = num[i];
	for (j = 1, l = 1; l * 2 <= n; j++, l*= 2) for (i = 0; i <= n - l * 2; i++)
		h[i][j] = (h[i][j-1] > h[i+l][j-1]) ? h[i][j-1] : h[i+l][j-1];	
}

int query(int be, int ed){
	int j = 0, l = 1; 
	while (2 * l <= ed - be + 1) j++, l *= 2;
	return (h[be][j] > h[ed + 1 - l][j]) ? h[be][j] : h[ed + 1 - l][j];	
} 

int find(int x){
	int low = 0, high = n + 1, mid;
	while (low + 1 < high){
		mid = (low + high) / 2;
		if (x < be[mid]) high = mid; else low = mid;
	}
	return low;
}

void solve(){
	prepare();
	int a, b, ia, ib;
	for (int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		ia = find(a); 
		ib = find(b);
		//printf("%d %d\n", ia, ib);
		if (ia == ib){
			printf("%d\n", b - a + 1);
			continue;
		}
		int tmp1 = be[ia + 1] - a;
		int tmp2 = b - be[ib] + 1; 
		//printf("  %d %d\n", tmp1, tmp2);
		if (ia + 1 == ib){
			printf("%d\n", tmp1 >?= tmp2);
			continue;
		}
		int ans = query(ia + 1, ib - 1);
		ans >?= tmp1;
		ans >?= tmp2;
		printf("%d\n", ans);
	}
}	

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	while (init()) solve();
	return 0;	
}
