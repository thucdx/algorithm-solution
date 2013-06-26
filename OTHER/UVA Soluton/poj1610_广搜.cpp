#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAXN = 555;
int n;
string ans;
int a[MAXN][MAXN];

struct Node{
	int x, y, l;
	Node(int x = 0, int y = 0, int l = 0):x(x), y(y), l(l) {};
};

vector<Node> q;

void init(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);	
}

bool checksame(Node p){
	for (int i = p. x; i < p. x + p. l; i++)
		for (int j = p. y; j < p. y + p. l; j++)
			if (a[i][j] != a[p.x][p.y]) return false;
	return true;
}

void solve(){
	q. clear();  ans = "";
	q. push_back(Node(1, 1, n));
	Node tmp;
	for (int i = 0; i < q. size(); i++){
		tmp = q[i];
		if (checksame(tmp)){
			ans += '0';
			if (a[tmp.x][tmp.y] == 1)  ans += '1'; else ans += '0';
		}
		else{
			ans += '1';
			if (tmp. l > 1){
				q. push_back(Node(tmp. x, tmp. y, tmp. l / 2));
				q. push_back(Node(tmp. x, tmp. y + tmp. l / 2, tmp. l / 2)); 
				q. push_back(Node(tmp. x + tmp. l / 2, tmp. y, tmp. l / 2));
				q. push_back(Node(tmp. x + tmp. l / 2, tmp. y + tmp. l / 2, tmp. l / 2));
			}
		}
	}
}

void print(){
	while (ans. size() % 4 != 0) ans = '0' + ans;
	string tmp;
	while (ans. size()){
		tmp = ans. substr(0, 4);
		if (tmp == "0000") putchar('0');
		if (tmp == "0001") putchar('1');
		if (tmp == "0010") putchar('2');
		if (tmp == "0011") putchar('3');
		if (tmp == "0100") putchar('4');
		if (tmp == "0101") putchar('5');
		if (tmp == "0110") putchar('6');
		if (tmp == "0111") putchar('7');
		if (tmp == "1000") putchar('8');
		if (tmp == "1001") putchar('9');
		if (tmp == "1010") putchar('A');
		if (tmp == "1011") putchar('B');
		if (tmp == "1100") putchar('C');
		if (tmp == "1101") putchar('D');
		if (tmp == "1110") putchar('E');
		if (tmp == "1111") putchar('F');
		ans = ans. substr(4, ans. size());
	}
	puts("");
}

int main(){
	int cases; scanf("%d", &cases);
	while (cases--){
		init(); 
		solve();
		print();	
	}
	return 0;	
}
