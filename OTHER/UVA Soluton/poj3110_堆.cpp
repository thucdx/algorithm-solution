#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 50010;

struct Node{
	int d, id;
	Node(int d = 0, int id = 0):d(d), id(id){}
	bool operator < (const Node &a) const{
		return d < a.d;
	}
};

priority_queue<Node> h;

int n, last;
char s[100];
Node t[MAXN];
int dl[MAXN];

inline bool special(int x){
	if (x % 400 == 0) return true;
	if (x % 100 != 0 && x % 4 == 0) return true;
	return false;	
}

const int md[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int days(int y, int m, int d){
	int ret = 0;
	for (int i = 1600; i < y; i++){
		ret += 365;
		if (special(i)) ret++;
	}
	for (int i = 1; i < m; i++){
		ret += md[i];
		if (i == 2 && special(y)) ret++;
	}
	ret += d;
	return ret;
}

void printDate(const int x){
	int ds = 0, y, m, d;
	for (y = 1600; ds < x; y++){
		ds += 365;
		if (special(y)) ds++;
	}
	y--;
	ds -= 365; if (special(y)) ds--;
	for (m = 1; ds < x; m++){
		ds += md[m];
		if (m == 2 && special(y)) ds++;	
	}
	m--;
	ds -= md[m]; if (m == 2 && special(y)) ds--;
	d = x - ds;
	printf("%0.2d.%0.2d.%0.4d\n", d, m, y);
}

void init(){
	scanf("%d", &n);  last = 0;
	for (int i = 1; i <= n; i++){
		getchar();
		gets(s);		
		int y, m, d;
		scanf("%d.%d.%d", &d, &m, &y);
		t[i] = Node(days(y, m, d), i);
		if (t[i]. d > last) last = t[i].d;
		scanf("%d", &d);
		dl[i] = t[i].d - d;		
	}
}

void solve(){
	int i, j, q, have;	
	sort(t + 1, t + n + 1);
	have = 1;  
	i = n;  
	int td = days(2100,12,31);
	while (i > 0 || !h.empty()){
		if (i > 0 && td == t[i].d){
			h.push(Node(dl[t[i].id], t[i].id));
			i--;
		}
		else if (!h.empty()){
			j = h.top().id;
			h.pop();
			if (td < dl[j]) {
				have = 0;  break;
			} 
		}
		td--;
	}
	if (!have){puts("Impossible"); return;}
	printDate(td + 1);
}

int main(){
	init();
	solve();
	return 0;	
}
