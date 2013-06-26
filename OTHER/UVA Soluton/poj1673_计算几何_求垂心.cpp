#include <algorithm>
#include <cmath>
using namespace std;

#define sqr(x) ((x)*(x))

struct Point {
	double x, y;
	Point(const double &_x = 0, const double &_y = 0): x(_x), y(_y){};
	void getin(){
		scanf("%lf %lf", &x, &y);
	}
	void print(){
		printf("%.4lf %.4lf\n", x, y);
	}
	
};

Point circumcenter(Point p0, Point p1, Point p2){
	double a1 = p1. x - p0. x, b1 = p1. y - p0. y, c1 = (sqr(a1) + sqr(b1)) / 2;
	double a2 = p2. x - p0. x, b2 = p2. y - p0. y, c2 = (sqr(a2) + sqr(b2)) / 2;
	double d = a1 * b2 - a2 * b1;
	return Point(p0. x + (c1 * b2 - c2 * b1) / d, p0. y + (a1 * c2 - a2 * c1) / d);
}

Point orthocenter(Point A, Point B, Point C){
	Point tmp = circumcenter(A, B, C);	
	return Point(A. x + B. x + C. x - 2 * tmp. x, A. y + B. y + C. y - 2* tmp. y);
}

Point cp, p1, p2, p3;

void solve(){
	p1. getin();  p2. getin();  p3. getin();
	cp = orthocenter(p1, p2, p3);
	cp. print();
}

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int cases; scanf("%d", &cases);
	while (cases--) solve();
	return 0;	
}
