/*
 * Sol2.cpp
 *
 *  Created on: Jun 18, 2011
 *      Author: ThucDX
 */
#include <iostream>
using namespace std;
#include <math.h>
#include <cstdio>
long long power(long long x, long long k);
void solve(int t);
long long l,r;

int main()
{
	int nTest,i;
	//FILE* in=fopen("input","r");
	//if(in==NULL) return 0;
	cin>>nTest;
    //fscanf(in,"%d",&nTest);
	for(i=0;i<nTest;i++){
		cin>>l>>r;
		//fscanf(in,"%l%ll",&l,&r);
		//cout<<l<<' '<<r<<endl;
		solve(i+1);
	}
	return 0;
}
long long power(long long x, long long k){
	long long u=1;
	if(k==0) return 1;
	else
	{
	   u=k/2;
	   long long tmp= power(x,u);
	   if(k%2==1){
		   return (tmp*tmp*x);
	   }
	   else return (tmp*tmp);
	}
}
void solve(int t){
	cout<<"Case #"<<t<<": ";
	long long i, p;
	double q;
	long long x;
	//cout<<endl<<l<<' '<<r<<endl;
	for(i=39;i>=2;i--){
		q=exp(log(r)/i);
		p=q+1e-12;
		x=power(p,i);
		//cout<<i<<':'<<p<<' '<<q<<' '<<x<<endl;

		if(l<=x) {cout<<i<<endl;return;}
	}
	cout<<1<<endl;
}
