#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 110;
const double inf = 1e8;
const double eps = 1e-8;

inline int dcmp(const double&x) { 
    return (x<-eps) ? -1 : (x>eps); 
}

struct Point {
    double x, y;
    Point(const double&_x=0, const double&_y=0) : x(_x), y(_y) {}

	void get(){
		scanf("%lf%lf", &x, &y);
	}
	
    double abs() const {
        return sqrt(x*x+y*y);
    }

    Point law() {
        return Point(-y, x);
    }

    Point unit() {
        return Point(x/abs(), y/abs());
    }
};

double det(const Point &a, const Point &b, const Point &c){
	return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

Point lnInln(const Point &a, const Point &b, const Point &c, const Point &d) {
    double u = det(a, b, c), v = det(b, a, d);
    return Point( (c.x*v+d.x*u)/(u+v), (c.y*v+d.y*u)/(u+v) );
}

struct Poly 
{
    int sz;
    Point p[maxn], q[maxn];

    void init() {
        sz = 4;
        p[0] = Point(-inf, -inf);
        p[1] = Point(inf, -inf);
        p[2] = Point(inf, inf);
        p[3] = Point(-inf, inf);
        p[4] = p[0];
    }

    void del(const Point &a, const Point &b) {
        int s = 0;
        for (int i = 0; i < sz; i++) {
            if (dcmp(det(a, b, p[i]))>=0) q[s++] = p[i];
            if (dcmp(det(a, b, p[i]))*dcmp(det(a, b, p[i+1]))<0)
	        q[s++] = lnInln(a, b, p[i], p[i+1]);
        }
        for (int i = 0; i < s; i++) p[i] = q[i];
        p[s] = p[0];
        sz = s;
    }
};

Point p[maxn];
Poly h;
int n, r;

void calc(const Point&a, const Point&b, double r, Point&p, Point&q) {
    Point s = Point(b.x-a.x, b.y-a.y);
    Point t = s.law().unit();
    t.x*=r; t.y*=r;
    p = Point(a.x+t.x, a.y+t.y);
    q = Point(b.x-a.x+p.x, b.y-a.y+p.y);
}

void init() {
	scanf("%d %d", &n, &r);
	for (int i = 1; i <= n; i++)
		p[i]. get();
	p[n+1] = p[1];
}

double dist(const Point &a, const Point &b){
	return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

void solve() {
    h.init();
    for (int i = 1; i<=n; ++i) {
        Point pp, q;
        calc(p[i+1], p[i], r, pp, q);
        h.del(pp, q);
    }
    Point a, b;
    double ans = -1;
    if (h.sz == 1) {a = b = h.p[0];}
    
    for (int i = 0; i < h.sz - 1; i++)
    	for (int j = i + 1 ; j < h. sz; j++){
			double d = dist(h.p[i], h.p[j]);
			if (d > ans){
				ans = d;
				a = h.p[i]; b = h.p[j];
			}
		}
    printf("%.4lf %.4lf %.4lf %.4lf\n", a.x, a.y, b.x, b.y);
}

int main() {
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
    init();
	solve();
}

