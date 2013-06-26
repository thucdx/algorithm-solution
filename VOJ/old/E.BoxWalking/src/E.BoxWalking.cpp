//============================================================================
// Name        : BoxWalking.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <math.h>
#include <stdio.h>
long long minL(long long a,long long b, long long c){
	long long rs=a;
	if(rs> b) rs=b;
	if(rs>c) rs=c;
	return rs;
}
long long sqr(int x){
	return (long long) x*x;
}
int main() {
	int lx,ly,lz,x,y,z;
	long long result;
	do{
		cin>>lx>>ly>>lz>>x>>y>>z;
		result=10000000000L;
		if(lx+ly+lz+x+y+z==0) break;
		//tinh toan.
		if(x==0 || y==0 ||z==0){
			cout<<(sqr(x)+sqr(y)+sqr(z))<<endl;
		}
		else
		{
			if(x==lx){
						result=minL(result, sqr(lz+lx-z)+sqr(y+lz),sqr(ly+lx-y)+sqr(z+ly));
						result=minL(result, sqr(y)+sqr(lx+2*lz-z), sqr(z)+sqr(lx+2*ly-y));
						result=minL(result,  sqr(z)+sqr(y+lx),     sqr(y)+sqr(z+lx));
			}
				if(y==ly){
						result=minL(result, sqr(lx+ly-x)+sqr(z+lx),sqr(lz+ly-z)+sqr(x+lz));
						result=minL(result, sqr(z)+sqr(ly+2*lx-x), sqr(x)+sqr(ly+2*lz-z));
						result=minL(result, sqr(x)+sqr(z+ly),      sqr(z)+sqr(x+ly));
						}
			if(z==lz){
						result=minL(result, sqr(ly+lz-y)+sqr(x+ly),sqr(lx+lz-x)+sqr(y+lx));
						result=minL(result, sqr(x)+sqr(lz+2*ly-y), sqr(y)+sqr(lz+2*lx-x));
						result=minL(result, sqr(x)+sqr(y+lz),      sqr(y)+sqr(x+lz));
						}
			cout<<result<<endl;


		}
	}while(true);

}
