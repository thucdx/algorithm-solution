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
int w,t;
string g[65];
void calc();
string * calc(int n, string * g);
int check(string * g, int size);
int main() {
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	int numTest=0;
	do
	{
		cin>>w;
		if(w==0) break;
		cin>>t;
		numTest++;
		cout<<"Image "<<numTest<<":"<<endl;
		for(int i=0;i<w;++i)
			cin>>g[i];
		calc();
	}
	while(true);
}
void calc()
{
	string* result= calc(w,g);
	for(int i=0;i<w;i++)
	{
		cout<<result[i]<<endl;
	}
}
string * calc(int n, string * g){
	//Chia lam 4.
	string* rs;

	string* p1,*p2,*p3,*p4; //luu tung phan
	cout<<n<<endl;
	for(int i=0;i<=n;i++)
	{
		rs[i]="";
		p1[i]="";
		p2[i]="";
		p3[i]="";
		p4[i]="";
	}
	//p1
	for(int i=0;i<n/2;i++)
	{
		p1[i]=g[i].substr(0,n/2);
	}
	for(int i=n/2;i<n;i++)
	{
		p3[i-n/2]=g[i].substr(0,n/2);
	}
	//p2,p4;
	for(int i=0;i<n/2;i++)
	{
		p2[i]=g[i].substr(n/2,n/2);
	}
	for(int i=n/2;i<n;i++)
	{
		p4[i-n/2]=g[i].substr(n/2,n/2);
	}
	int a1=check(p1,n/2);
	if(a1==1 || a1==0)
	{
		///fill;
		for(int i=0;i<n/2;i++)
			for(int j=0;j<n/2;j++)
			{
				p1[i][j]=a1+'0';
			}
	}
	else p1=calc(n/2,p1);

	int a2=check(p2,n/2);
	if(a2==1 || a2==0)
	{
		///fill;
		for(int i=0;i<n/2;i++)
			for(int j=0;j<n/2;j++)
			{
				p2[i][j]=a2+'0';
			}
	}
	else p2=calc(n/2,p2);

	int a3=check(p3,n/2);
	if(a3==1 || a3==0)
	{
		///fill;
		for(int i=0;i<n/2;i++)
			for(int j=0;j<n/2;j++)
			{
				p3[i][j]=a3+'0';
			}
	}
	else p3=calc(n/2,p3);

	int a4=check(p4,n/2);
	if(a4==1 || a4==0)
	{
		///fill;
		for(int i=0;i<n/2;i++)
			for(int j=0;j<n/2;j++)
			{
				p4[i][j]=a4+'0';
			}
	}
	else p4=calc(n/2,p4);

	//Ghep bang
	for(int i=0;i<n/2;i++)
	{
		rs[i]=p1[i]+p2[i];
	}
	for(int i=n/2;i<n;i++)
	{
		rs[i]=p3[i-n/2]+p4[i-n/2];
	}
	return rs;

}

int check(string * g, int size){
	int nOne=0, nZero=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(g[i][j]=='1') nOne++;
			else nZero++;
		}
	}
	if((1.0*nOne)/(nOne+nZero) >= (1.0*t)/100) return 1;
	if((1.0*nZero)/(nOne+nZero) >= (1.0*t)/100) return 0;
	return -1;
}
