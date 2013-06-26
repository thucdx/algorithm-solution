#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define EPS 1e-6
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
Point p[4055];
int main()
{
    freopen("MILITARY.IN", "rt", stdin);    
    freopen("MILITARY.OUT", "wt", stdout);
    int nPoint;
    scanf("%d",&nPoint);
    REP(i,0,nPoint-1)
    {
        scanf("%lf%lf",&p[i].x, &p[i].y);    
    }   
    //solve
    int nLop=0;
    int prevN=nPoint;
    while(true)
    {   
        prevN=nPoint;
        if(nPoint==0) break;
        grahamScan(p,nPoint);
        if(nPoint<=2)
            break;
        //>=3
        //check xem 3 diem thang hang ko ==> suy bien duong thang
        //if(ccw(p[0],p[1],p[2])==0)
          //  break;
        nLop++;
        //copy;
        int i,j;
        i=nPoint;j=0;
        while(i<prevN)
        {
            //check xem diem p[i] co nam tren canh nao cua da giac ko.
            bool isAdd=true;
            REP(l,0,nPoint-1)
            {
                int t=(l+1)%nPoint;
                if (ccw(p[i],p[l],p[t])==0)
                {
                    isAdd=false;
                    break;
                }   
            }
            if(isAdd)
            {
                p[j]=p[i];
                j++;    
            }    
            i++;
        }
        nPoint=j;
    }
    
    cout<<nLop;
    

}
