#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define EPS 1e-9
#define INF 1e100
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

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
    void operator=(const Point& that) {
        x=that.x;
        y=that.y;
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
Point p0;
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
double sqdist(Point p0, Point p1) {
	double dx = p1.x - p0.x, dy = p1.y - p0.y;
	return dx * dx + dy * dy;
}
bool cmpP(Point p1, Point p2) {
	int i = ccw(p0, p1, p2);
	if (i > 0)
		return true;
	if (i < 0)
		return false;
	return sqdist(p0, p1) < sqdist(p0, p2);
}
double dist(Point p0, Point p1) {
	double dx = p1.x - p0.x, dy = p1.y - p0.y;
	return sqrt(dx * dx + dy * dy);
}

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

void grahamScan(Point p[], int& n) {
	if (n == 1)
		return;
	int j = 0;
	for (int i = 1; i < n; i++)
		if (dcmp(p[j].y, p[i].y) > 0 || (dcmp(p[j].y, p[i].y) == 0 && dcmp(
				p[j].x, p[i].x) < 0))
			j = i;
	swap(p[0], p[j]);
	p0 = p[0];
	sort(p + 1, p + n, cmpP);
	int k = 2;
	for (int i = 2; i < n; i++) {
		while (k > 1 && ccw(p[i], p[k - 1], p[k - 2]) >= 0)
			k--;
		swap(p[k++], p[i]);
	}
	n = k;
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

/*
 * Kiem tra diem p0 nam trong goc tao boi 2 tia p1p2 va p1p3
 */
bool insideAngle(Point p0, Point p1, Point p2, Point p3) {
	if (ccw(p0, p1, p2) * ccw(p0, p1, p3) > 0)
		return false;
	Point p4;
	getIntersect(p0, p1, p2, p3, p4);
	return positionOnSegment(p0, p1, p4) == 0 || positionOnSegment(p4, p0, p1)
			== 0;
}

/*
 * Kiem tra diem p0 nam trong tam giac p1p2p3
 */
bool insideTriangle(Point p0, Point p1, Point p2, Point p3) {
	if (positionOnSegment(p0, p1, p2) == 0)
		return true;
	if (positionOnSegment(p0, p2, p3) == 0)
		return true;
	if (positionOnSegment(p0, p1, p3) == 0)
		return true;
	return (ccw(p0, p1, p2) * ccw(p0, p1, p3) < 0 && ccw(p0, p2, p1) * ccw(p0,
			p2, p3) < 0);
}

bool insideConvexPolygon2(Point p0, Point p[], int n) {
	if (!insideAngle(p0, p[0], p[1], p[n - 1]))
		return false;
	int i = 1;
	int j = n - 1;
	while (j - i > 1) {
		int k = (i + j) >> 1;
		if (insideAngle(p0, p[0], p[i], p[k]))
			j = k;
		else
			i = k;
	}
	return insideTriangle(p0, p[0], p[i], p[j]);
}
bool inSegment(Point a, Point b, Point c)
{
    if(ccw(a,b,c)!=0) return false;
    if ((c.y>=a.y  && a.y >=b.y) ||(b.y>=a.y && a.y>=c.y)) return true;
    return false;
}
Point p[100005];
int n,m;
int main()
{   
   freopen("KMIX.IN", "rt", stdin);    
   freopen("KMIX.OUT", "wt", stdout);
    scanf("%d",&n);
    int save;
    REP(i,0,n-1)
    {
        scanf("%lf%lf",&p[i].x,&p[i].y);    
    }
    //Tien xu li
    grahamScan(p,n);
    //REP(i,0,n-1)
    //cout<<p[i].x<<" "<<p[i].y<<endl;
//    return 0;
    double x,y;
    scanf("%d",&m);
    REP(i,1,m)
    {
        scanf("%lf%lf",&x,&y);
        //check nam trong.
        if(n==1)
        {    
            if(p[0].x ==x && p[0].y==y)    
               printf("YES\n");    
            else printf("NO\n");
        }
        else if(n==2)
        {
            if(positionOnSegment(Point(x,y),p[0],p[1])==0)
                printf("YES\n");
            else printf("NO\n");        
        }
        else
        {
            bool isYes=false;
            Point yaku(x,y);
            //cout<<yaku.x<<" "<<yaku.y<<endl;
            //REP(i,0,n-1)
//            {
//                if(positionOnSegment(yaku,p[i],p[(i+1)%n])==0)
//                {
//                    isYes=true;
//                    break;
//                }
//            }
//            if(isYes) printf("YES\n");
//            else
//            {
                if(insideConvexPolygon2(yaku,p,n)){
                    printf("YES\n");
                }
                else printf("NO\n");
//            }
        }
        
    }
        
}
