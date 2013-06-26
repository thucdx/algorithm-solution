//后缀数组求两字符串最长公共子串
//利用sort 实现简单 效率略低
#include <algorithm>
using namespace std;

const int MAXLEN =  200100;
int n;
int power, lstSA[MAXLEN], lstRank[MAXLEN], SA [MAXLEN], rank[MAXLEN], h[MAXLEN], height[MAXLEN];
char ts[MAXLEN], str[MAXLEN];

bool cmpChar(const int &a, const int &b){
    return str[a] < str[b];
}

bool cmpLst(const int& a, const int& b){
  	return lstRank[a]<lstRank[b]||lstRank[a]==lstRank[b]&&lstRank[a+power]<lstRank[b+power];
}

void suffixArray(){
  	for (int i = 0; i<n; i++) SA[i] = i;
  	sort(SA, SA+n, cmpChar);
  	for (int i = 0, j = 0; i<n; i++) {
    	if (i>0&&str[SA[i]]!=str[SA[i-1]]) j++;
    	rank[SA[i]] = j;
  	}
  	for (power = 1; rank[SA[n-1]]<n-1; power *= 2) {
    	memcpy(lstRank, rank, sizeof(int)*n);
    	memcpy(lstSA, SA, sizeof(int)*n);
    	sort(SA, SA+n, cmpLst);
    	for (int i = 0, j = 0; i<n; i++) {
      		if (i>0&&cmpLst(SA[i-1], SA[i])) j++;
      		rank[SA[i]] = j;
    	}
  	}
}

void getheight(){
	int i, j, h; 
	height[0] = 0;
	for (i = 0; i < n; i++) rank[SA[i]] = i;
	for (h = 0, i = 0; i < n; i++) 
		if (rank[i] > 0){
			j = SA[rank[i]-1];
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
	suffixArray(); getheight();
	int ans = 0;
	for (int i = 1; i < n; i++){
		if (height[i] >= ans && SA[i - 1] < l1 && SA[i] > l1)
			ans = height[i];
		if (height[i] >= ans && SA[i] < l1 && SA[i - 1] > l1)
			ans = height[i];
	}
	printf("%d\n", ans);
}

int main(){
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	solve();
	return 0;	
}
