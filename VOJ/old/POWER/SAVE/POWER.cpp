//============================================================================
// Name        : POWER.cpp
// Author      : ThucDX
// Version     :
// Copyright   : POWER-VNOI
// Description : Hello World in C++, ANSI-style
//============================================================================

#include <iostream>
using namespace std;
#include <math.h>
#include <iomanip>
#define MAX 40
long long l,r;
bool isOk(int k);
int find();

int main() {
	int nTest,i;
	cin>>nTest;
	for(i=0;i<nTest;i++){
		cin>>l>>r;
		cout<<"Case #"<<i+1<<": "<<find()<<endl;
	}
	return 0;
}
int find(){
	int i=0;
	int rs=1;
	int j=(long double)log(r) / (long double)log(2.0)+1;

	for(i=1;i<=j;i++)
	{
		if(isOk(i))
			rs=i;
	}
	return rs;
}
bool isOk(int k){
	long double a,b;
	a=pow((long double)l,1.0/k);
	b=pow((long double)r,1.0/k);
	//cout<<setprecision(24);
	//cout<<k<<':'<<a<<' '<<b<<endl;
	//cout<<k<<':'<<a<<' '<<(long long)(b+0.0000000001)<<endl;
	if(a<= (long long)(b+1e-14))
	{	//cout<<"ACCEPTED!  "<<k<<endl;
		return true;
	}
	else return false;
}
