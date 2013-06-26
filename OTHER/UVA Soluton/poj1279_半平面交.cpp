#include <cstdio>
#include <cmath>

const int maxn = 1600;
const double inf = 1e8;
const double eps = 1e-8;

inline int dcmp(const double&x) { return (x<-eps)?-1:(x>eps); }

struct Point {
  	double x, y;
  	Point(const double &_x=0, const double &_y=0) : x(_x), y(_y) {}
  	
  	void get(){
		scanf("%lf%lf", &x, &y);
	}
	void print(){
		printf("%.2lf %.2lf\n", x, y); 
	}
};

double det(const Point&a, const Point&b, const Point&c) {
  	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

Point intersect(const Point &p1, const Point &p2, double a, double b, double c) {
    double u = fabs(a * p1. x + b * p1. y + c);
    double v = fabs(a * p2. x + b * p2. y + c);
    return Point( (p1.x*v + p2.x*u)/(u+v), (p1.y*v+p2.y*u)/(u+v) ) ;
}

struct Poly {
  	int sz;
  	Point p[maxn], q[maxn];

  	void init() {
    	sz = 4;
    	p[1] = Point(-inf, -inf);
    	p[2] = Point(inf, -inf);
    	p[3] = Point(inf, inf);
    	p[4] = Point(-inf, inf);
    	p[5] = p[1]; p[0] = p[4];
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

  	double area() {
    	double ret = 0;
	    for (int i = 1; i<=sz; ++i)
      		ret += det(Point(0, 0), p[i], p[i+1]);
    	return fabs(ret) / 2;
  	}
};


void getLine(Point A, Point B, double &a, double &b, double &c){
    a = B.y - A.y;
    b = A.x - B.x;
    c = A.y * (B.x - A.x) - A.x * (B.y - A.y);
}

Point p[maxn];
Poly h;
int n;

bool init() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) p[i].get();
	p[n] = p[0];
  	return true;
}

void solve() {
	h.init();
	double a, b, c;
  	for (int i = 0; i < n; i++){
		getLine(p[i+1], p[i], a, b, c);
		h.cut(a, b, c);
	}
  	printf("%.2lf\n", h.area());
}

int main() {
	int cases;  scanf("%d", &cases);
	while (cases--){
		init(); 
		solve();
	}
}

