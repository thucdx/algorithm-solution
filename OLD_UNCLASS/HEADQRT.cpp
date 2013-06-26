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
Point pA[30555];
Point pB[30555];
int main()
{
    //freopen("HEADQRT.IN", "rt", stdin);    
    //freopen("HEADQRT.OUT", "wt", stdout);
    int nTest,nA,nB,nPoint;
    double x, y;
    int type;
    scanf("%d",&nTest);
    REP(i,1,nTest)
    {   
        scanf("%d",&nPoint);
        nA=-1;
        nB=-1;
        REP(i,1,nPoint)
        {
            scanf("%lf%lf%d",&x,&y,&type);
            if(type==0)
            {
                nA++;
                pA[nA].x=x;
                pA[nA].y=y;        
            }
            else
            {
                nB++;
                pB[nB].x=x;
                pB[nB].y=y;        
            }
        }
        nA++;
        nB++;
        grahamScan(pA, nA);
        grahamScan(pB, nB);
        //cout<<nA<<" "<<nB<<endl;
        double maxDis=-1,tmp;
        REP(i,0,nA-1)
        REP(j,0,nB-1)
        {
            tmp=dist(pA[i],pB[j]);
            if(tmp>maxDis) maxDis=tmp;
        }
        printf("%I64d",(long long) maxDis);
        //cout<<maxDis<<endl;
        //cout<<(long long)(maxDis+EPS);
        
        if(i!=nTest) printf("\n");
    }
}
