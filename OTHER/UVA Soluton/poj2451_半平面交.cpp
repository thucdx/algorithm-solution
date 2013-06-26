#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define EPS 1e-10
#define INF 1e8
#define MAXN 25000

inline double sqr( double x ) { return x * x ; };

inline int dcmp( double x ) {
	if( x < -EPS ) return -1; else return ( x > EPS );
}

struct TPoint { 
	double x, y ;
	TPoint () :x(0),y(0) {};
	TPoint ( const TPoint&b ) :x(b.x),y(b.y) {};
	TPoint ( double a, double b ) :x(a),y(b) {};
	TPoint stretch( double l ) {
		return TPoint( x * l, y * l );
	}	
    double sqrdis ( const TPoint&b )  {
		return sqr(x-b.x) + sqr(y-b.y);
	}
	double distance( const TPoint&b ) {
		return sqrt(sqrdis(b));
	}
	double length() {
		return distance( TPoint(0,0) );
	}
	TPoint dotpoint_right(){
		return TPoint( y, -x );
	}
	TPoint dotpoint_left(){
		return TPoint( -y, x );
	}
	TPoint operator - ( const TPoint&b ) {
		return TPoint( x-b.x, y-b.y );
	}
	TPoint operator + ( const TPoint&b ) {
		return TPoint( x+b.x, y+b.y );
	}
	double cross( const TPoint&b ) const {
		return x*b.y-y*b.x;
	}
	double cross( const TPoint&b , const TPoint&c ) const
	{
		return (b.x-x)*(c.y-y)-(b.y-y)*(c.x-x);
	}
	void input() {
		scanf("%lf %lf", &x, &y);
	}
	void print(){
        cout << int(x) << " " << int(y) << "  ";   
    }
	TPoint toInf( const TPoint& d, double sgn ){
		if( fabs(d.x) > fabs(d.y) )
			return TPoint( sgn*(INF*dcmp(d.x)) + x, sgn*(INF/fabs(d.x)*d.y) + y );
		else
			return TPoint( sgn*(INF/fabs(d.y)*d.x) + x, sgn*(INF*dcmp(d.y)) + y );
	}
};

int N;
const double pi = acos(-1.0);
struct Line{
	TPoint a, b;
	TPoint polar;
	Line () : a(TPoint(0,0)), b(TPoint(0,0)), polar(TPoint(0,0)) {};
	Line ( const TPoint& _a, const TPoint& _b ) : a(_a), b(_b) {
	    polar = b - a;
    };
	bool operator < (const Line &a) const{
        if (dcmp(polar.y) >= 0 && dcmp(a.polar.y) < 0) return true;
        if (dcmp(polar.y) < 0 && dcmp(a.polar.y) >= 0) return false;
        if (dcmp(polar.y) == 0 && dcmp(a.polar.y) == 0){
            if (dcmp(polar.x) >= 0 && dcmp(a.polar.x) < 0) return true;
            if (dcmp(polar.x) < 0 && dcmp(a.polar.x) >= 0) return false;
            return fabs(polar.x) < fabs(a.polar.x); 
        }
        double t = polar.x * a.polar.y - polar.y * a.polar.x;
        return  dcmp(t) == 0 ? polar.x*polar.x + polar.y*polar.y < a.polar.x*a.polar.x + a.polar.y*a.polar.y : t > 0;
    };
};

Line lines[MAXN];
TPoint pts[MAXN];
int op, ed ;

double getarea ( TPoint pts[], int st, int ed ){
	int i; double s = 0;
	if( ed-st < 3 ) return 0;
	for( i = st; i < ed; ++ i ) s += pts[i].cross(pts[i+1]);
	return fabs(s)/2;
}

TPoint lnInln(const TPoint &a, const TPoint &b, const TPoint &c, const TPoint &d) {
    double u = a.cross(b, c), v = b.cross(a, d);
    return TPoint( (c.x*v+d.x*u)/(u+v), (c.y*v+d.y*u)/(u+v) );
}

double getAns (){
	Line tlne = lines[0];
	op = ed = 0;
	pts[ed++] = tlne.a.toInf( tlne.b-tlne.a, -1 );
	pts[ed++] = tlne.a.toInf( tlne.b-tlne.a, 1 );	
	for( int i = 1; i < N; ++ i ) {
		tlne = lines[i];
		int ted = ed;
		while( op < ted && dcmp( tlne.a.cross( tlne.b, pts[ted-1] ) ) < 0 ) -- ted;
		if( ted < ed ){
			TPoint p = lnInln( tlne.a, tlne.b, pts[ted-1], pts[ted] );
			ed = ted;
			pts[ed++] = p;
			int top = op;
			while( top < ed && dcmp( tlne.a.cross( tlne.b,pts[top] ) ) < 0 ) ++ top;
			if( top > op )
			{
				TPoint p = lnInln( tlne.a, tlne.b, pts[top-1], pts[top] );
				op = top-1;
				pts[op] = pts[ed++] = p;
			} 
			else
			    pts[ed++] = tlne.b.toInf( tlne.b-tlne.a, 1 );
		}
	}
	return getarea( pts, op, ed-1 );
}

bool init (){    
	if (EOF == scanf("%d", &N)) return false;
	TPoint p1, p2;
	lines[0].polar = TPoint(0, 0);
	for( int i = 0; i < N; ++ i) {
		p1.input();
		p2.input();
		lines[i] = Line(p1, p2);
	}
	lines[N++] = Line(TPoint(0,0), TPoint(10000, 0));
	lines[N++] = Line(TPoint(10000,0), TPoint(10000, 10000));
	lines[N++] = Line(TPoint(10000,10000), TPoint(0, 10000));
	lines[N++] = Line(TPoint(0,10000), TPoint(0, 0));
	return true;
}

double ans;
void solve(){
    sort(lines, lines + N);
	ans = getAns();
	printf("%.1lf\n", ans);
}

int main (){
	while( init() ) solve ();
	return 0;
}

