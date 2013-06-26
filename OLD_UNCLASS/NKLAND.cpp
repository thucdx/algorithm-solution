#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define EPS 1e-9
#define INF 1e100
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
#define EPS 1e-9
#define INF 1e100

int dcmp(double a, double b) {
	if (abs(a - b) < EPS)
		return 0;
	if (a > b)
		return 1;
	return -1;
}

struct Point {
	double x, y;

	Point() {
		x = y = 0;
	}

	Point(double _x, double _y) {
		x = _x, y = _y;
	}

	bool operator==(const Point& that) const {
		return dcmp(x, that.x) == 0 && dcmp(y, that.y) == 0;
	}

	bool operator<(const Point& that) const {
		if (dcmp(x, that.x) != 0)
			return dcmp(x, that.x) < 0;
		return dcmp(y, that.y) < 0;
	}
};

/*
 * ham nguoc chieu kim dong ho
 * 0: ba diem cung duong thang
 * 1: nguoc chieu kim dong ho (re trai)
 * -1: cung chieu kim dong ho (re phai)
 */
int ccw(Point p0, Point p1, Point p2) {
	double dx1 = p1.x - p0.x, dy1 = p1.y - p0.y;
	double dx2 = p2.x - p0.x, dy2 = p2.y - p0.y;
	double t = dx1 * dy2 - dx2 * dy1;
	if (dcmp(t, 0) == 0)
		return 0;
	if (t < 0)
		return -1;
	return 1;
}

/*
 * Tra ra vi tri cua p0 so voi doan thang co 2 dau mut p1, p2:
 * -2: khong xac dinh duoc doan thang vi p1 trung p2
 * 0: o giua,
 * 1: gan diem nho hon (o ngoai doan),
 * 2: gan diem lon hon (o ngoai doan),
 * -1: khong nam tren duong thang noi boi 2 diem
 */
int positionOnSegment(Point p0, Point p1, Point p2) {
	if (p1 == p2)
		return -2;
	if (ccw(p0, p1, p2) != 0)
		return -1;
	if (p2 < p1)
		swap(p1, p2);
	if (p0 < p1)
		return 1;
	if (p2 < p0)
		return 2;
	return 0;
}

/*
 * Tra ve vi tri cua diem p0 so voi tia ma p1 la goc p2 la ngon
 * -2: khong xac dinh duoc vi p1 trung voi p2
 * -1: khong nam tren duong thang chua hai diem p1, p2
 * 0: nam tren tia
 * 1: nam tren tia doi
 */
int positionOnRay(Point p0, Point p1, Point p2) {
	if (p1 == p2)
		return -2;
	if (ccw(p0, p1, p2) != 0)
		return -1;
	if (p0 == p1)
		return 0;
	if (p0 == p2)
		return 0;
	double dx0 = p0.x - p1.x, dy0 = p0.y - p1.y;
	double dx2 = p2.x - p1.x, dy2 = p2.y - p1.y;
	double t;
	if (dcmp(dx2, 0) != 0)
		t = dx0 * dx2;
	else
		t = dy0 * dy2;
	if (dcmp(t, 0) > 0)
		return 0;
	return 1;
}

bool positionOnLine(Point p0, Point p1, Point p2) {
	return (ccw(p0, p1, p2) == 0);
}

bool getLine(Point p0, Point p1, double& a, double& b, double& c) {
	if (p0 == p1)
		return false;
	a = p1.y - p0.y;
	b = p0.x - p1.x;
	c = -(a * p0.x + b * p0.y);
	return true;
}

/*
 * Tim giao diem cua 2 duong thang; mot duong di qua 2 diem p0, p1; mot duong di qua p2, p3; giao diem neu co p4
 * 0: song song
 * -1: trung nhau
 * 1: cat nhau tai 1 diem
 */
int getIntersect(Point p0, Point p1, Point p2, Point p3, Point& p4) {
	double a0, b0, c0, a1, b1, c1;
	getLine(p0, p1, a0, b0, c0);
	getLine(p2, p3, a1, b1, c1);
	double d = a0 * b1 - a1 * b0;
	double dx = b0 * c1 - b1 * c0;
	double dy = -(c1 * a0 - c0 * a1);
	if (dcmp(d, 0) == 0) {
		if (dcmp(dx, 0) == 0 && dcmp(dy, 0) == 0)
			return -1;
		return 0;
	}
	p4.x = dx / d;
	p4.y = dy / d;
	return 1;
}

double sqdist(Point p0, Point p1) {
	double dx = p1.x - p0.x, dy = p1.y - p0.y;
	return dx * dx + dy * dy;
}

double dist(Point p0, Point p1) {
	double dx = p1.x - p0.x, dy = p1.y - p0.y;
	return sqrt(dx * dx + dy * dy);
}

bool isCut(Point p0, Point p1, Point p2, Point p3) {
	if (ccw(p0, p1, p2) * ccw(p0, p1, p3) < 0)
		if (ccw(p2, p3, p0) * ccw(p2, p3, p1) < 0)
			return true;
	if (positionOnSegment(p0, p2, p3) == 0)
		return true;
	if (positionOnSegment(p1, p2, p3) == 0)
		return true;
	if (positionOnSegment(p2, p0, p1) == 0)
		return true;
	if (positionOnSegment(p3, p0, p1) == 0)
		return true;
	return false;
}

Point p0;

bool cmpP(Point p1, Point p2) {
	int i = ccw(p0, p1, p2);
	if (i > 0)
		return true;
	if (i < 0)
		return false;
	return sqdist(p0, p1) < sqdist(p0, p2);
}

bool insideConvexPolygon(Point p0, Point p[], int n) {
	int k, l;
	if (n == 1)
		return false;
	if (n == 2) {
		if (ccw(p0, p[0], p[1]) == 0)
			if (positionOnSegment(p0, p[0], p[1]) == 0)
				return true;
			else
				return false;
		else
			return false;
	}
	k = l = 0;
	for (int i = 0; i < n; i++) {
		int j = ccw(p0, p[i], p[(i + 1) % n]);
		if (j < 0)
			k = 1;
		if (j > 0)
			l = 1;
	}
	if (k + l == 2)
		return false;
	return true;
}

bool notHaveCommonPointBetween2ConvexPolygons(Point p1[], int n1, Point p2[],
		int n2) {
	for (int i = 0; i < n1; i++)
		if (insideConvexPolygon(p1[i], p2, n2))
			return false;
	for (int i = 0; i < n2; i++)
		if (insideConvexPolygon(p2[i], p1, n1))
			return false;
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			if (isCut(p1[i], p1[(i + 1) % n1], p2[j], p2[(j + 1) % n2]))
				return false;
	return true;
}
Point child[1005], ancestor[1005];
int n,m;
int main()
{
    //freopen("NKLAND.IN","rt", stdin);    
    //freopen("NKLAND.OUT","wt", stdout);
    int nTest;
    scanf("%d",&nTest);
    REP(i,1,nTest)
    {
        scanf("%d",&m);
        REP(i,0,m-1)
        {
            scanf("%lf%lf",&child[i].x,&child[i].y);    
        }
        scanf("%d",&n);
        REP(i,0,n-1)
        {
            scanf("%lf%lf",&ancestor[i].x,&ancestor[i].y);    
        }
        if( notHaveCommonPointBetween2ConvexPolygons(child,m,ancestor,n)==true)
        {
            cout<<"NO\n";    
        }
        else cout<<"YES\n";
            
    }
        
}
