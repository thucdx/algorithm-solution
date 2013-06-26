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

string emo[105];
struct vt{
	int lt;
	int rt;
} bt[10000];
int nVt;
int cmp( const void * a, const void * b)
{
	return (((string *) b)-> length() - ((string *) a)-> length() );
}
int cmp2( const void * a, const void * b)
{
	vt * _a= (vt *)a;
	vt * _b= (vt *)b;
	if(_a->rt != _b->rt)
		return (_a->rt - _b->rt);
	else
	{
		return (_a->lt - _b->lt);
	}
}
int n,m;
string s;
int calc();
bool isOk(int start, int len);
void init();
bool isMatch(int pos, string patern);
bool isMatch(int start, int leng,string pattern);
int main()
{
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	int result;
	do
	{
		cin>>n>>m;
		if(n==0 && m==0) break;
		result=0;
		FOR(i,0,n-1) cin>>emo[i];
		init();
		while(getchar()!='\n');
		FOR(i,0,m-1)
		{
			getline(cin,s);
			result+=calc();
		}
		cout<<result<<endl;
	}
	while(true);
}
void init()
{
	nVt=-1;
}
int calc()
{
	int rs=0;
	int rPos;
	nVt=-1;
	int lim=s.length()-1;
	//cout<<s<<endl;
	FOR(i,0,lim)
	{
		FOR(j,0,n-1)
		{		if(isMatch(i,emo[j]))
				{
					nVt++;
					bt[nVt].lt=i;
					bt[nVt].rt=i+emo[j].length()-1;
				}
		}
	}
	//Calc
	qsort(bt, nVt+1, sizeof(bt[0]),cmp2);
	rPos=-1;
	FOR(i,0,nVt)
		if(bt[i].lt > rPos)
		{
			rs++;
			rPos=bt[i].rt;
		}
	return rs;
}
bool isMatch(int pos, string patern)
{
	int len=patern.length();
	int lim=s.length();
	FOR(i,pos,pos+len-1)
	{
		if(i>lim) return false;
		if(s[i]!=patern[i-pos]) return false;
	}
	return true;
}
