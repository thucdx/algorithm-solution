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
	do
	{
		int i;
		cin>>s;
		bool ok=true;
		string rs="";
		if(s=="#") break;
		for(i=s.length()-1;i>=0;--i)
		{
			if(s[i]=='d') {rs+='b'; continue;}
			if(s[i]=='b') {rs+='d'; continue;}
			if(s[i]=='p') {rs+='q'; continue;}
			if(s[i]=='q') {rs+='p'; continue;}
			if(s[i]=='i' ||s[i]=='o' ||s[i]=='v'||s[i]=='w' ||s[i]=='x')
			{
				rs+=s[i]; continue;
			}

			cout<<"INVALID"<<endl;
			ok=false;
			break;

		}
		if(ok)
		cout<<rs<<endl;
	}
	while(true);
}
