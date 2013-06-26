//后缀数组求两字符串最长公共子串
#include <algorithm>
using namespace std;

const int MAXLEN =  200100;
int n;
int head[MAXLEN], b[MAXLEN], id[MAXLEN], rank[MAXLEN], nb[MAXLEN], next[MAXLEN], height[MAXLEN];
char str[MAXLEN];

bool cmp(const int &a, const int &b){
    return str[a] < str[b];
}

void suffixarray(){
	int i, j, k, h;
	for (i = 0; i < n; i++) id[i] = i;
	sort(id, id + n, cmp);	
	for (i = 0; i < n; i++)
		if (i == 0 || str[id[i]] != str[id[i-1]]) b[id[i]] = i;
		else b[id[i]] = b[id[i-1]];
	for (h = 1; h < n; h <<= 1){
		for (i = 0; i < n; i++) head[i] = next[i] = -1;
		for (i = n - 1; i >= 0; i--) if (id[i]){
			j = id[i] - h; if (j < 0) j += n;
			next[j] = head[b[j]]; head[b[j]] = j;
		}
		j = n - h; next[j] = head[b[j]]; head[b[j]] = j;
		for (i = k = 0; i < n; i++) if (head[i] >= 0)
			for (j = head[i]; j >= 0; j = next[j]) id[k++] = j;
		for (i = 0; i < n; i++) if (i > 0 && id[i] + h < n && id[i-1] + h < n
			&& b[id[i]] == b[id[i-1]] && b[id[i] + h] == b[id[i-1]+h])
				nb[id[i]] = nb[id[i-1]]; else nb[id[i]] = i;
		for (i = 0; i < n; i++) b[i] = nb[i];
	}
}

void getheight(){
	int i, j, h; 
	height[0] = 0;
	for (i = 0; i < n; i++) rank[id[i]] = i;
	for (h = 0, i = 0; i < n; i++) 
		if (rank[i] > 0){
			j = id[rank[i]-1];
			while (str[i+h] == str[j+h]) ++h;
			height[rank[i]] = h;
			if (h > 0) --h;	
		}	
}

void solve(){
	gets(str);
	int l1 = strlen(str);
	str[l1] = '$';
	gets(str + l1 + 1);
	n = strlen(str);
	suffixarray(); 
	getheight();
	int ans = 0;
	for (int i = 1; i < n; i++){
		if (height[i] >= ans && id[i - 1] < l1 && id[i] > l1)
			ans = height[i];
		if (height[i] >= ans && id[i] < l1 && id[i - 1] > l1)
			ans = height[i];
	}
	printf("%d\n", ans);
}

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	solve();
	return 0;	
}
