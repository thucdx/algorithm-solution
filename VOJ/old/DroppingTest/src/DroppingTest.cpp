//============================================================================
// Name        : DroppingTest.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define max 1001;

struct ps {
	int t,m;
};
ps lst[1002];
int n,k;
float tmp[1002];
double round(double x){
	double t=x*100;
	t=t-floor(t)>=0.5?ceil(t):floor(t);
	return t/100;
}
int cp(const void* a, const void *b){
	float *ia=(float * )a;
	float *ib=(float *)b;
	float rs=*ia-*ib;
	if(rs>0) return 1;
	else return -1;
}
int cmp(const void * a, const void *b){
	ps *ia= (ps*)a;
	ps *ib= (ps*)b;
	float va=(ia->t)/(ia->m),vb=(ib->t)/(ib->m);
	if(va !=0 || vb!=0) return (va>vb);
	//va==0 vb==0
	return (ia->m > ib->m);
}
void attempt(double first, double last);
int main() {
	int i,j;
	do{
		cin>>n>>k;
		if(n==0 && k==0) break;
		//tinh toan
		for(i=0;i<n;++i){
			scanf("%d",&lst[i].t);
		}
		for(i=0;i<n;++i){
					scanf("%d",&lst[i].m);
				}
		attempt(0.0,1.0);
	}
	while(true);
}
void attempt(double first, double last){
	double mid=(last+first)/2;
	double sum=0;
	int i;
	if((last-first)<=1e-6)
	{
		//cout<<mid<<endl;
		int rs;
		rs=100*round(mid);
		printf("%d\n",rs);
	}
	else
	{
		for(i=0;i<n;++i){
			tmp[i]=lst[i].t - mid*lst[i].m;
		}
		qsort(tmp,n,sizeof(tmp[0]),cp);

		for(i=k;i<n;++i){
			sum+=tmp[i];
		}
		if(sum>=0) attempt(mid,last);
		else attempt(first, mid);
	}
}
