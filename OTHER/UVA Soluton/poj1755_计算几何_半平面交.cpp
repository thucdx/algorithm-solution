#include <algorithm>
#include <math.h>
#define inf 1e30
#define eps 1e-8
using namespace std;

const int MAXN = 110;
int n;
double u[MAXN], v[MAXN], w[MAXN];

int dcmp(double x){
	if (x < -eps) return -1; else return (x > eps);	
}

struct Point{
	double x, y;
	Point(const double &_x=0 , const double &_y=0) : x(_x) , y(_y) {}
};

Point intersect(const Point &p1, const Point &p2, double a, double b, double c) {
    double u = fabs(a * p1. x + b * p1. y + c);
    double v = fabs(a * p2. x + b * p2. y + c);
    return Point( (p1.x*v + p2.x*u)/(u+v), (p1.y*v+p2.y*u)/(u+v) ) ;
}

struct Poly{
	int sz;
	Point p[MAXN], q[MAXN];
	
	void init(){
		sz = 4;
		p[1] = Point(0, 0);
		p[2] = Point(inf, 0);
		p[3] = Point(inf, inf);
		p[4] = Point(0, inf);
		p[0] = p[4], p[5] = p[1];
	}
	
	void cut(double a, double b, double c){
		int s = 0;
		for (int i = 1; i <= sz; i++){
			if (dcmp(a * p[i]. x + b * p[i]. y + c) < 1)
				q[++s] = p[i];
			else {
				if (dcmp(a * p[i - 1]. x + b * p[i - 1]. y + c) < 0)
					q[++s] = intersect(p[i-1], p[i], a, b, c);
				if (dcmp(a * p[i + 1]. x + b * p[i + 1]. y + c) < 0)
					q[++s] = intersect(p[i], p[i+1], a, b, c);
			}
		}
		for (int i = 1; i <= s; i++) p[i] = q[i]; 
		p[s+1] = p[1]; p[0] = p[s];
		sz = s;
	}
};

Poly pol;

bool win(int x){
	for (int i = 0; i < n; i++) if (i != x)
		if (u[x] <= u[i] && v[x] <= v[i] && w[x] <= w[i]) return false;
	pol. init();
	for (int i = 0; i < n; i++) if (i != x){
		double a = 1/u[x] - 1/u[i], b = 1/v[x] - 1/v[i], c = 1/w[x] - 1/w[i]; 
		pol. cut(a, b, c);
		if (pol. sz < 3) return false;
	}
	return (pol. sz > 2);
}


void solve(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf%lf%lf", u + i, v + i, w + i);
	for (int i = 0; i < n; i++)
		if (win(i)) puts("Yes"); else puts("No");
}

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	solve();
	return 0;	
}
