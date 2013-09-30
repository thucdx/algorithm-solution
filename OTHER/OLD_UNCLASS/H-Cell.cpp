#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstring>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, n) for (int i = 0; i < n; i++)
#define FIT(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int) (c).size()
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define SET(a, x) memset(a, x, sizeof(a));

typedef long long LL;
typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<pair<int, int> > VII;
struct point
{
	double x,y;
	int power;
	void operator=(point b)
	{
		x=b.x;
		y=b.y;
		power=b.power;
	}
};
point tower[15];
point segLine[15];

int t,r;
int nPoint();
void exe();
char check(point a);
double dis(point a, point b);
double sqr(double x)
{
	return x*x;
}
point getPoint(int i);
point getPoint(point a,point b, double dis);
int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);

	do
	{
		cin>>t;
		if(t==0) break;
		cin>>r;

		FOR(i,0,t-1)
		{
			cin>>tower[i].x>>tower[i].y>>tower[i].power;
			//cout<<tower[i].x<<tower[i].y<<tower[i].power<<endl;
		}

		FOR(i,0,r)
		{
			cin>>segLine[i].x>>segLine[i].y;
			//cout<<segLine[i].x<<segLine[i].y<<endl;
		}
		exe();
	}while(true);
}
void exe()
{
	int nP=nPoint();
	point poinI;
	double space=1;
	int nSeg=0;
	char prev;
	poinI=segLine[0];
	prev=check(poinI);
	cout<<"(0,"<<prev<<")";
	FOR(i,1,nP-1)
	{
		//poinI=getPoint(i);
		if (dis(poinI,segLine[nSeg+1])>=1)
		{
			poinI=getPoint(poinI,segLine[nSeg+1],1);
		}
		else  //< 1
		{
			space=1-dis(poinI,segLine[nSeg+1]);
			nSeg++;
			poinI=getPoint(segLine[nSeg],segLine[nSeg+1],space);
		}
		char cur=check(poinI);
		//cout<<poinI.x<<' '<<poinI.y<<' '<<cur<<endl;
		if(cur!=prev)
		{
			cout<<" ("<<i<<","<<cur<<")";
			prev=cur;
		}
	}
	cout<<endl;
}
char check(point a)
{
	//cout<<"CHECK "<<a.x<<" "<<a.y<<endl;
	int pos=0;
	//cout<<"CHECK"<<endl;
	long long  minTower=(long long) (0.5+tower[0].power/(sqr(dis(a,tower[0]))));
	//cout<<minTower<<endl;
	FOR(i,1,t-1)
	{
		long long  temp=(long long) (0.5 +tower[i].power/(sqr(dis(a,tower[i]))));
		//cout<<temp<<endl;
		if(temp> minTower)
		{
			minTower=temp;
			pos=i;
		}
	}
	//cout<<a.x<<" "<<a.y<<" "<<pos<<" "<<minTower<<endl;
	return ((char)('A'+pos));
}
double dis(point a, point b)
{
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
int nPoint()
{
	double len=0;
	FOR(i,0,r-1)
	{
		len+=dis(segLine[i],segLine[i+1]);
	}
	return (int(len+1.0+0.5));
}
point getPoint(point a,point b, double space) //spae <= dis(a,b)
{
	point rs;
	if(b.y==a.y)
	{
		rs.y=a.y;
		rs.x=(b.x>a.x ?(a.x+space): (a.x-space));
		return rs;
	}
	int k=1;
	if(a.y> b.y) k=-1;
	double t=(b.x-a.x)/(b.y-a.y);
	rs.y=a.y+k* space/sqrt(t*t+1);
	rs.x=t*(rs.y-a.y)+a.x;
	return rs;
}
