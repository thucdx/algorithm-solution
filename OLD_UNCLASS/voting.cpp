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

int main() {
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	string s;
	int a,n,y,p;
	do
	{
		cin>>s;
		if(s=="#") break;
		a=0;n=0;y=0;p=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='Y') y++;
			if(s[i]=='A') a++;
			if(s[i]=='N') n++;
			if(s[i]=='P') p++;
		}
		if(2*a>= s.length()) {cout<<"need quorum"<<endl; continue;}
		if(y> n) {cout<<"yes"<<endl; continue;}
		if(n> y) {cout<<"no"<<endl; continue;}
		if(y==n) {cout<<"tie"<<endl; continue;}

	}
	while(true);

}
