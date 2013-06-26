#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 10010

int n;
int tree[80000];

int insert(int k, int l, int r, int s, int t, int tc)
{
	if ( (l == s) && (r == t) ) {
		tree[k] = tc;  return 0;
	}
	if (tree[k] > -1){
		tree[k*2] = tree[k];
		tree[k*2+1] = tree[k];
		tree[k] = -1;
	}
	int m = (l + r) / 2;
	if (t <= m) insert(k * 2, l, m, s, t, tc);
	else 
	if (s >= m) insert(k * 2 + 1, m, r, s, t, tc);
	else{
		insert(k * 2, l, m, s, m, tc);
		insert(k * 2 + 1, m, r, m, t, tc);
	}
	return 0;
}

int ls[MAXN], lt[MAXN];
int m, a[2 * MAXN];
void init(){
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d %d", ls + i, lt + i);
		a[i] = ls[i];  a[i+n] = lt[i];
	}
	sort(a, a + n * 2);
	m = unique(a, a + n * 2) - a;
	for (i = 0; i < n; i++){
		ls[i] = lower_bound(a, a + m, ls[i]) - a + 1;
		lt[i] = lower_bound(a, a + m, lt[i]) - a + 1;
	}
}

bool mk[MAXN];
int ans;
void Count(int k, int l, int r){
	if ( tree[k] >= 0 ) {
		if (tree[k] > 0 && !mk[tree[k]]){
			mk[tree[k]] = true;
			ans++;
		}
		return;
	}
	int m = (l + r) / 2; 
	Count(k * 2, l, m);
	Count(k * 2 + 1, m, r);
}

void solve(){
	insert(1, 0, m, 0, m, 0);
	for (int i = 0; i < n; i++){
		insert(1, 0, m, ls[i] - 1, lt[i], i + 1);
	}
	ans = 0;	
	memset(mk, 0, sizeof(mk));
	Count(1, 0, m);
	printf("%d\n", ans);
}

int main(){
	int cases;  scanf("%d", &cases);
	while (cases--){
		init();
		solve();
	}
	return 0;
}

