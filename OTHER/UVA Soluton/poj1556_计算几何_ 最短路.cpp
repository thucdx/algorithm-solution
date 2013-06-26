#include <algorithm>
#include <cmath>
using namespace std;
#define eps 1e-8

struct Point{
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {};
};

struct Segment{
	Point a, b;
	Segment(){a = Point(), b = Point();}
	Segment(Point x, Point y): a(x), b(y){};
};

Point p[100];
Segment s[100];
int ps, sg;
int n;

bool init(){
	scanf("%d", &n);
	if (n == -1) return false;
	p[0] = Point(0, 5);
	ps = 1, sg = 0;
	double x, y1, y2, y3, y4;
	for (int i = 0; i < n; i++){
		scanf("%lf%lf%lf%lf%lf", &x, &y1, &y2, &y3, &y4);
		p[ps++] = Point(x, y1);
		s[sg++] = Segment(Point(x, 0), p[ps - 1]);
		p[ps++] = Point(x, y2);
		p[ps++] = Point(x, y3);
		s[sg++] = Segment(p[ps - 2], p[ps - 1]);
		p[ps++] = Point(x, y4);
		s[sg++] = Segment(p[ps - 1], Point(x, 10));
	}
	p[ps++] = Point(10, 5);
	return true;
}

int dcmp(double x){
	if (x < -eps) return -1; else return (x > eps);
}

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

double dist(Point a, Point b){
	return sqrt((a.x-b.x) * (a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double g[100][100];

void build(){
	for (int i = 0; i < ps; i++)
		for (int j = 0; j < ps; j++) g[i][j] = -1;
	for (int i = 1; i < ps; i++)
		for (int j = 0; j < i; j++) if (p[j]. x < p[i]. x)
		{
				g[j][i] = g[i][j] = dist(p[i], p[j]);
				for (int k = 0; k < sg; k++) if (s[k]. a. x < p[i]. x && s[k]. a. x > p[j]. x)
					if (segmentIntersectTest(p[i], p[j], s[k]. a, s[k]. b) == 1) 
					{
						g[j][i] = g[i][j] = -1;
						break;
					}
		}
}

double d[100]; 
bool mk[100];

void dijkstra(){
	d[0] = 0;  memset(mk, 0, sizeof(mk));
	for (int i = 1; i < ps; i++) d[i] = 1e20;
	int j;  double min;
	while (1){
		j = -1; min = 1e10;
		for (int i = 0; i < ps; i++)
			if (!mk[i] && d[i] < min){
				min = d[i]; j = i;
			}
		if (j < 0) break;
		if (j == ps - 1) break;
		mk[j] = true;
		for (int i = 0; i < ps; i++)
			if (!mk[i] && g[j][i] > 0 && d[j] + g[j][i] < d[i])
				d[i] = d[j] + g[j][i];
	}
	printf("%.2lf\n", d[ps - 1]);
}

void solve(){
	if (n == 0) {puts("10.00"); return;}
	build();
	dijkstra();
}

int main(){
	while (init()) solve();
	return 0;	
}
