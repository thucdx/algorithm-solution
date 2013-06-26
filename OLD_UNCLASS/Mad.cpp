#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <ctime>
#include <list>
#include <vector>
using namespace std;

#define forn(i,n) for(long long i=0;i<n;++i)
#define forx(i,n) for(long long i=1;i<=n;++i)
#define forab(i,a,b) for (long long i=a;i<=b;++i)
int n;
int main() {
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	int prev=0;
	int a;
	bool first;
	bool firstline=true;
	do
	{
		cin>>n;
		first=true;
		//firstline=true;

		if(n==0) break;
		if(!firstline) cout<<endl;
		firstline=false;

		prev=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			if(a==prev)
				 continue;
			else
			{
				for(int j=1;j<=a-prev;j++)
				{
					if(first) cout<<i;
					else
						cout<<' '<<i;
					if(first) first=false;
				}
			}
			prev=a;
		}
		//cout<<endl;
	}while(true);
}
