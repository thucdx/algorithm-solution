#include <math.h>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define INF 1e8

using namespace std;

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
		scanf("%lf%lf", &x, &y);
	}
	TPoint toInf( const TPoint& d, double sgn ){
		if( fabs(d.x) > fabs(d.y) )
			return TPoint( sgn*(INF*dcmp(d.x)) + x, sgn*(INF/fabs(d.x)*d.y) + y );
		else
			return TPoint( sgn*(INF/fabs(d.y)*d.x) + x, sgn*(INF*dcmp(d.y)) + y );
	}
};

int N, K, H;

struct Line
{
	TPoint a, b;
	Line () : a(TPoint(0,0)), b(TPoint(0,0)) {};
	Line ( const TPoint& _a, const TPoint& _b ) : a(_a), b(_b) {};
	Line ( const Line& l ) : a(l.a), b(l.b) {};
	Line move () {
		TPoint c = ((b-a).dotpoint_left()).stretch( H/(b-a).length() );
		return Line( a+c, b+c );
	}
};

bool mk[20];
Line lines[20];
TPoint pts[50];
int op, ed ;

double getarea ( TPoint pts[], int st, int ed )
{
	int i; double s = 0;
	if( ed-st < 3 ) return 0;
	for( i = st; i < ed; ++ i ) s += pts[i].cross(pts[i+1]);
	return fabs(s)/2;
}

TPoint lnInln(const TPoint &a, const TPoint &b, const TPoint &c, const TPoint &d) {
    double u = a.cross(b, c), v = b.cross(a, d);
    return TPoint( (c.x*v+d.x*u)/(u+v), (c.y*v+d.y*u)/(u+v) );
}

double getAns ()
{
	Line tlne;
	tlne = mk[0] ? lines[0].move() : lines[0];
	op = ed = 0;
	pts[ed++] = tlne.a.toInf( tlne.b-tlne.a, -1 );
	pts[ed++] = tlne.a.toInf( tlne.b-tlne.a, 1 );	
	for( int i = 1; i < N; ++ i ) 
	{
		tlne = mk[i] ? lines[i].move() : lines[i];
		int ted = ed;
		while( op < ted && dcmp( tlne.a.cross( tlne.b, pts[ted-1] ) ) < 0 ) -- ted;
		if( ted < ed )
		{
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
			} else
				pts[ed++] = tlne.b.toInf( tlne.b-tlne.a, 1 );
		}

	}
	return getarea( pts, op, ed-1 );
}

bool init ()
{    
	scanf("%d%d%d", &N, &K, &H ) ;
	if( N == 0 ) return false;
	TPoint p0, p, lp; p0.input(); lp = p0;
	for( int i = 1; i < N; ++ i ) {
		p.input();
		lines[i] = Line(lp,p);
		lp = p;
	}
	lines[0] = Line(lp,p0);
	return true;
}

double ans;
double total;

void search(int p, int x){
	if (x == K){
		double a = getAns();
        ans <?= a;
        return;
	}
	if (p == N) return;
	mk[p] = true;
	search(p + 1, x + 1);
	mk[p] = false;
	search(p + 1, x); 
}

void solve(){
	if (K > N) K = N;
	memset(mk, 0, sizeof(mk));
	total = getAns();
	ans = total;
	search(0, 0);
	printf("%.2lf\n", total - ans);
}

int main ()
{
	while( init() ) solve ();
	return 0;
}
