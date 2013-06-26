#include <algorithm>
#include <cmath>
using namespace std;
#define eps 1e-8

int dcmp(double x){
	if (x < -eps) return -1; else return (x > eps);
}

struct Point{
	double x, y;
	Point (double x = 0.0, double y = 0.0): x(x), y(y) {}
};

int n;
Point l[50][2], pt;

double det(Point p0, Point p1, Point p2){
	return (p1. x - p0. x) * (p2. y - p0.y) - (p2. x - p0. x) * (p1. y - p0.y);
}


int segmentIntersectTest(Point p1, Point p2, Point p3, Point p4){
	if (max(p1. x, p2. x) + eps < min(p3. x, p4. x) ||
		max(p3. x, p4. x) + eps < min(p1. x, p2. x) ||
		max(p1. y, p2. y) + eps < min(p3. y, p4. y) ||
		max(p3. y, p4. y) + eps < min(p1. y, p2. y)) return 0;
	int d1 = dcmp(det(p3, p4, p2));
	int d2 = dcmp(det(p3, p4, p1));
	int d3 = dcmp(det(p1, p2, p4));
	int d4 = dcmp(det(p1, p2, p3));
	if (d1 * d2 == 1 || d3 * d4 == 1) return 0;
	if (d1 == 0 && d2 == 0 && d3 == 0 && d4 == 0) return -1;
	return 1;
}

void init(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf %lf %lf %lf", &l[i][0]. x, &l[i][0]. y, &l[i][1]. x, &l[i][1]. y);
	scanf("%lf %lf", &pt. x, &pt. y);
}

void solve(){
	int ans = 10000, j, t;
	double i;
	for (i = 0.5; i < 100; i += 1){
		for (t = 1, j = 0; j < n; j++)	
			t += segmentIntersectTest(l[j][0], l[j][1], pt, Point(0.0, i));
		ans <?= t;
	}
	for (i = 0.5; i < 100; i += 1){
		for (t = 1, j = 0; j < n; j++)
			t += segmentIntersectTest(l[j][0], l[j][1], pt, Point(i, 0.0));
		ans <?= t;	
	}
	for (i = 0.5; i < 100; i += 1){
		for (t = 1, j = 0; j < n; j++)
			t += segmentIntersectTest(l[j][0], l[j][1], pt, Point(i, 100.0));
		ans <?= t;	
	}
	for (i = 0.5; i < 100; i += 1){
		for (t = 1, j = 0; j < n; j++)
			t += segmentIntersectTest(l[j][0], l[j][1], pt, Point(100.0, i));
		ans <?= t;	
	}
	printf("Number of doors = %d\n", ans);			
}

int main(){
	init();
	solve();
	return 0;
}
