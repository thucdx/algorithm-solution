#include <algorithm>
#include <math.h>
using namespace std;
#define pi acos(-1)

struct Point{
	double x, y;
	double angle;
	
	double dist(){
		return x*x + y*y;
	}
	Point(double x = 0, double y = 0, double angle = 0): x(x), y(y), angle(angle) {}
	
	void get(){
		scanf("%lf %lf", &x, &y);
		double d = dist();
		if (y >= 0) angle = acos(x / d);
		else angle = 2 * pi - acos(x / d);
		angle = angle / pi * 180;
	}
	
	bool operator < (const Point &a) const {
		return angle < a. angle;
	}
};

Point a[3];
double r;

bool check(){
	if (a[2]. angle - a[0]. angle <= 120) return false;
	if (a[1]. angle + 360 - a[2]. angle <= 120) return false;
	if (a[0]. angle + 360 - a[1]. angle <= 120) return false;
	return true;  
}

int main(){
	int cases; scanf("%d", &cases);
	while (cases--){
		scanf("%lf", &r);
		a[0]. get(), a[1]. get(), a[2]. get();
		sort(a, a + 3);
		if (check()) printf("Yes\n"); else printf("No\n");
	}
	return 0;	
}
