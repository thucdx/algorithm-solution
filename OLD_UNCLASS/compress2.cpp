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
string rs[65];
void calc();
void print();
void initial();
void calc(int x1,int y1, int x2,int y2);
int check(int x1,int y1, int x2,int y2);
void fill(int x1, int y1, int x2, int y2,char c);
int main() {
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);

	int numTest=0;
	do
	{
		cin>>w;
		if(w==0) break;
		initial();
		cin>>t;
		numTest++;
		cout<<"Image "<<numTest<<":"<<endl;
		for(int i=0;i<w;++i)
			cin>>g[i];
		calc();
		print();
	}
	while(true);
}
void initial()
{
	for(int i=0;i<=64;i++)
	{
		g[i]="";
		rs[i]="";
		for(int j=0;j<w;j++)
			rs[i]+=" ";

	}
}
void calc()
{
	calc(0,0,w-1,w-1);
}
void calc(int x1,int y1, int x2,int y2)
{
	int a=check(x1,y1,x2,y2);
	if(a==1 || a==0)
	{
		fill(x1,y1,x2,y2,a+'0');
		return;
	}
	int x3=(x1+x2+1)/2, y3=(y1+y2+1)/2;
	calc(x1,y1,x3-1,y3-1); //part 1
	calc(x1,y3,x3-1,y2); //p2
	calc(x3,y1,x2,y3-1);//p3
	calc(x3,y3,x2,y2);//p4
}
int check(int x1, int y1, int x2, int y2){
	int nOne=0,nZero=0;
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)
		{
			if(g[i][j]=='1') nOne++;
			else nZero++;
		}
	if(((1.0*nOne)/(nOne+nZero) )>= (t*1.0)/100) return 1;
	if(((1.0*nZero)/(nOne+nZero)) >= (1.0*t)/100) return 0;
	return -1;
}
void fill(int x1, int y1, int x2, int y2,char c)
{
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)
		{
			rs[i][j]=c;
		}
}
void print()
{
	for(int i=0;i<w;i++)
		cout<<rs[i]<<endl;
}
