#include <algorithm>
#define eps 1e-10
using namespace std;

struct Point {
	double x, y;
	Point (double x = 0, double y = 0): x(x), y(y) {};
	void get(){
		scanf("%lf %lf", &x, &y);	
	}
};

int dcmp(double x){
	if (x < -eps) return -1; else return (x > eps);	
}

double det(Point p0, Point p1, Point p2){
	return (p1. x - p0. x) * (p2. y - p0. y) - (p2. x - p0. x) * (p1. y - p0. y);
}

Point a[200], b[200];
int link[200];

bool testIntersect(Point p1, Point p2, Point p3, Point p4){
	if (max(p1. x, p2. x) + eps < min(p3. x, p4. x) ||
		max(p3. x, p4. x) + eps < min(p1. x, p2. x) ||
		max(p1. y, p2. y) + eps < min(p3. y, p4. y) ||
		max(p3. y, p4. y) + eps < min(p1. y, p2. y) ) return false;
	int d1 = dcmp(det(p3, p4, p1));
	int d2 = dcmp(det(p3, p4, p2));
	int d3 = dcmp(det(p1, p2, p4));
	int d4 = dcmp(det(p1, p2, p3));
	if (d1 * d2 == 1|| d3 * d4 == 1) return false;
	return true;
}

int main(){
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) a[i]. get();
	for (int i = 1; i <= n; i++) b[i]. get();
	for (int i = 1; i <= n; i++) link[i] = i;
	
	while (1){
		bool ch = false;
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				if (testIntersect(a[i], b[link[i]], a[j], b[link[j]])) {
					swap(link[i], link[j]);
					ch = true;
				}
		if (!ch) break;
	}
	
	for (int i = 1; i <= n; i++) printf("%d\n", link[i]);
	return 0;	
}
