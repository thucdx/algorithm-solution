#include <algorithm>
using namespace std;

#define eps 1e-8

struct Point{
	double x, y;
	Point(double x = 0, double y = 0):x(x), y(y){};
	void get(){
		scanf("%lf%lf", &x, &y);
	}
};

inline int dcmp(double x){
	if (x < -eps) return -1; else return x > eps;
}

double det(Point p0, Point p1, Point p2){
	return (p1.x-p0.x) * (p2.y-p0.y) - (p2.x-p0.x) * (p1.y-p0.y);	
}

double dot(Point p0, Point p1, Point p2){
	return (p1.x-p0.x)*(p2.x-p0.x) + (p1.y-p0.y)*(p2.y-p0.y);
}

int between(Point A, Point B, Point C){
	return dcmp(dot(A, B, C)) <= 0;
}

int segmentIntersectTest(Point a, Point b, Point c, Point d){
	int d1 = dcmp(det(a, b, c));
	int d2 = dcmp(det(a, b, d));
	int d3 = dcmp(det(c, d, a));
	int d4 = dcmp(det(c, d, b));
	if ((d1^d2) == -2 && (d3^d4) == -2) return 1;
	if (d1 == 0 && between(c, a, b) ||
		d2 == 0 && between(d, a, b) ||
		d3 == 0 && between(a, c, d) ||
		d4 == 0 && between(b, c, d)) return 1;
	return 0;
}

Point p[10];

void solve(){
	p[5].get();
	p[6].get();
	double ax, ay, bx, by;
	scanf("%lf %lf %lf %lf", &ax, &ay, &bx, &by);
	p[0] = Point(min(ax, bx), min(ay, by));
 	p[1] = Point(min(ax, bx), max(ay, by));
	p[2] = Point(max(ax, bx), min(ay, by));
	p[3] = Point(max(ax, bx), max(ay, by));
 	p[4] = p[0];	
	if (dcmp(p[5].x-p[0].x) >= 0 && dcmp(p[5].x-p[2].x) <= 0 && dcmp(p[5].y-p[0].y) <= 0 && dcmp(p[5].y - p[2].y) >= 0 ||
		dcmp(p[6].x-p[0].x) >= 0 && dcmp(p[6].x-p[2].x) <= 0 && dcmp(p[6].y-p[0].y) <= 0 && dcmp(p[6].y - p[2].y) >= 0){
		puts("T");  return;
	}
	for (int i = 0; i < 4; i++){
		if (segmentIntersectTest(p[i], p[i+1], p[5], p[6]) > 0){
			puts("T");  return;
		}
	}
	puts("F");
}

int main(){
	int cases;  scanf("%d", &cases);
	while (cases--) solve();
	return 0;
}
