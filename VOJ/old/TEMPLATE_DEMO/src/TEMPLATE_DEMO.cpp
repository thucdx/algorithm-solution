//============================================================================
// Name        : TEMPLATE_DEMO.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
template <class T>
void swapd(T &a, T &b){
	T tmp;
	tmp=a;
	a=b;
	b=tmp;
}
int main() {
	int a=4, b=5;
	swapd(a,b);
	double m=3.4,n=4.56;
	swapd(m,n);
	cout<<a<<' '<<b<<endl;
	cout<<m<< ' '<<n<<endl;
}
