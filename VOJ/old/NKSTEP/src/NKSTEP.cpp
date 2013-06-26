//============================================================================
// Name        : NKSTEP.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
#include <math.h>
/*
2(1+2+..+(n-1))+n=n(n-1)+n=n^2<fd<=(n+1)^2
		n^2+n>fd 2n-2
		n^2 , 2n-1 step.
		*/
int main() {
	int a,b,nTest;
	int i;
	int dis;
	int n;
	int rs;
	scanf("%d",&nTest);
	for(i=1;i<=nTest;i++){
		scanf("%d%d",&a,&b);
		dis=b-a;
		n=sqrt(dis);
		if(dis==n*n) rs=2*n-1;
		else if(dis<=(n+1)*n) rs=2*n;
		else rs=2*n+1;
		cout<<rs<<endl;
	}
	return 0;
}
