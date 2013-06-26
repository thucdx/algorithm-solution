//============================================================================
// Name        : EUCLIDE.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

int a, b,c;
bool permute=false;
int swap(int & a, int &b){
	int c;
	c=a;
	a=b;
	b=c;
}
int main() {
	cin>>a>>b>>c;//ax+by=c;
	//solve
	int Q0,Q1,P0,P1,R0,R1,q,R2,P2,Q2;
	R0=a;R1=b;P0=0;P1=1;Q0=1;Q1=0;
	if(a<b) {
		permute=true;
		swap(R0,R1);
		swap(P0,P1);
		swap(Q0,Q1);
	}
	while(R)

}
