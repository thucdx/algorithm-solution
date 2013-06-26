#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <list>
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
typedef list<int> IntegerList;

struct node
{
	bool isExist;
	long long price;
}lft[200005];
int three[12];
int m,n;
long long p[35];
IntegerList f[35];
int like[35];
long long minPrice;

void init();
int genNum();
void make1();
void make2();
void reset();
long long  min(long long a, long long b)
{
	if(a<b) return a;
	return b;
}
int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	cin>>m>>n;
	FOR(i,1,m)
	{
		cin>>p[i];
	}
	while(getchar()!='\n');
	FOR(i,1,n)
	{
		stringstream ss;
		string s;
		int j;
		getline(cin,s);
		ss<<s;
		while(ss>>j)
		{
			//Tim xem co trung ko.
			bool isDuplicate=false;
			for (IntegerList::const_iterator ci = f[j].begin(); ci != f[j].end(); ++ci)
			{
				if(*ci==i)
				{
					isDuplicate=true;
					break;
				}
			}
			if(!isDuplicate)
				f[j].push_back(i);
		}
	}
	init();
	make1();
	make2();
	cout<<minPrice; //result;
}
void init()
{
	minPrice=-1;
	three[0]=1;
	FOR(i,1,11)
	{
		three[i]=3*three[i-1];
	}
	FOR(i,0,200000)
	{
		lft[i].isExist=false;
		lft[i].price=100000000;
	}

}
bool isOk()
{
	for(int i=1;i<=n;++i)
	{
		if(like[i]>2) return false;
	}
	return true;
}
void reset()
{
	FOR(i,0,n)
			like[i]=0;
}
void make1()
{
	int _price=0;
	lft[0].isExist=true;
	lft[0].price=0;
	int lim=(1<<(m/2))-1;
	FOR(i,1,lim)
	{
		reset();
		_price=0;
		FOR(j,0,(m/2)-1)
		{
			if((i&(1<<j))!=0) //mon do j+1 duoc chon.
			{	//update like
				_price+= p[j+1];
				for (IntegerList::const_iterator ci = f[j+1].begin(); ci != f[j+1].end(); ++ci)
				{
					like[*ci]++;
				}
			}
		}
		if(isOk()) //tat ca so like <=2
		{ //luu ket qua vao mang lft[].
			int index=genNum();

			lft[index].isExist=true;
			lft[index].price=min(lft[index].price,_price);
			if(index==(three[n]-1) && (minPrice==-1 || _price<minPrice))
			{
				minPrice=_price;
			}

		}
	}
}
void make2()
{
	int _price=0;
	int lim=(1<<(m-(m/2)))-1;
	FOR(i,1,lim)
	{
		reset();
		_price=0;
		int lim2=m-m/2+1;
		FOR(j,0,lim2)
		{
			if((i&(1<<j))!=0) //mon do j+1 duoc chon.
			{	//update like
				_price+= p[j+m/2+1];
				for (IntegerList::const_iterator ci = f[j+m/2+1].begin(); ci != f[j+m/2+1].end(); ++ci)
				{
					like[*ci]++;
				}
			}
		}
		if(isOk()) //tat ca so like <=2
		{ //luu ket qua vao mang lft[].
			int index=genNum();
			if(index==(three[n]-1) && (minPrice==-1 || _price<minPrice))
			{
				minPrice=_price;
			}
			//update ket qua
			if(lft[three[n]-1-index].isExist && (minPrice==-1 ||(lft[three[n]-1-index].price+ _price < minPrice)))
			{
				minPrice=lft[three[n]-1-index].price+_price;

			}
		}

	}
}
int genNum()
{
	int result=0;
	FOR(i,1,n)
	{
		result+=like[i]*three[i-1];

	}

	return result;
}





/*
void solve(int i) //chon mon an i
{
	if(i>m) return;
	//chon i
	price+=p[i];
	//cap nhat like
	for (IntegerList::const_iterator ci = f[i].begin(); ci != f[i].end(); ++ci)
	{
		like[*ci]++;
	}
	if(isOk())
	{
		if((price< minPrice|| minPrice==-1))//update ket qua
		{
			minPrice=price;
		}
		restore(i); //khong can duyet tiep
		return;
	}
	else solve(i+1);
	//khong chon i;
	restore(i);
	solve(i+1);
}
void restore(int i)
{
	price-=p[i];
	for (IntegerList::const_iterator ci = f[i].begin(); ci != f[i].end(); ++ci)
	{
		like[*ci]--;
	}

}
*/
